//
//  GLRotationRenderer.cpp
//  LearnOpenGL
//
//  Created by 王江 on 2020/11/21.
//

#include "GLRotationRenderer.hpp"
#include <iostream>
#include <algorithm>
#include "GLImage.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Renderer {

static float vertices[] = {
    // positions          // colors           // texture coords
     0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left
};

static GLuint indices[] = {
    0, 1, 2,
    2, 3, 0,
};

static unsigned int RENDER_COUNT_MAX = 360;

GLRotationRenderer::GLRotationRenderer(const char *vsPath, const char *fsPath):
m_shader(GLShader(vsPath, fsPath)) {
    // bind vertex array before any vertex configurations
    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);
    // vertex
    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glGenBuffers(1, &m_ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    // vertex attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    // unbind vao for later use
    glBindVertexArray(0); //pass 0 to unbind
}

GLRotationRenderer::~GLRotationRenderer() {
    
}

void GLRotationRenderer::setTextureImagePath(const char *imgPath) {
    std::string path(imgPath);
    m_img_path = path;
    
    GLImage img = GLImage();
    img.load(imgPath);
    if (m_tid != GL_INVALID_VALUE) {
        glDeleteTextures(1, &m_tid);
    }
    glGenTextures(1, &m_tid);
    glBindTexture(GL_TEXTURE_2D, m_tid);
    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img.getImageWidth(), img.getImageHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, img.getImageData());
    glGenerateMipmap(GL_TEXTURE_2D);
}

void GLRotationRenderer::render() {
    // render
    // ------
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    // use shader program
    m_shader.use();
    glm::mat4 trans = glm::mat4(1.f);
    trans = glm::rotate(trans, glm::radians(float(1.0 * m_render_count)), glm::vec3(0.0, 0.0, 1.0));
    m_shader.setMat4FloatUniform("transform", trans);
    m_render_count++;
    if (m_render_count >= RENDER_COUNT_MAX) {
        m_render_count = 0;
    }
    // use texture
    glBindTexture(GL_TEXTURE_2D, m_tid);
    // use vao
    glBindVertexArray(m_vao);
    // draw
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

}
