//
//  GLEffectRenderer.cpp
//  LearnOpenGL
//
//  Created by 王江 on 2020/11/5.
//

#include "GLTriangleRenderer.hpp"

namespace Renderer {

static float vertices[] = {
    -0.5f, -0.5, 0.0f,
    0.5f, -0.5, 0.0f,
    0.0f, 0.5, 0.0f,
};

static const char *vertexShaderSource = "#version 300 es\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

static const char *fragShaderSource = "#version 300 es\n"
"precision highp float;\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\0";

GLTriangleRenderer::GLTriangleRenderer() {
    // shader
    unsigned int vsob;
    vsob = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vsob, 1, &vertexShaderSource, NULL);
    glCompileShader(vsob);
    int success;
    char info[1024];
    glGetShaderiv(vsob, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vsob, 1024, NULL, info);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << info << std::endl;
    }
    unsigned int fsob = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fsob, 1, &fragShaderSource, NULL);
    glCompileShader(fsob);
    glGetShaderiv(fsob, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fsob, 1024, NULL, info);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << info << std::endl;
    }
    // program
    m_shaderProgram = glCreateProgram();
    glAttachShader(m_shaderProgram, vsob);
    glAttachShader(m_shaderProgram, fsob);
    glLinkProgram(m_shaderProgram);
    glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(m_shaderProgram, 1024, NULL, info);
        std::cout << "ERROR::PROGRAM::LINK_FAILD\n" << info << std::endl;
    }
    glDeleteShader(vsob);
    glDeleteShader(fsob);
    
    // bind vertex array before any vertex configurations
    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);
    // vertex
    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // vertex attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // unbind buffer
    glBindBuffer(GL_ARRAY_BUFFER, 0); // aready bind to vao
    // unbind vao for later use
    glBindVertexArray(0);
}

GLTriangleRenderer::~GLTriangleRenderer() {
    glDeleteProgram(m_shaderProgram);
    glDeleteBuffers(1, &m_vbo);
    glDeleteVertexArrays(1, &m_vao);
}

void GLTriangleRenderer::render() {
    // render
    // ------
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    // use shader program
    glUseProgram(m_shaderProgram);
    // use vao
    glBindVertexArray(m_vao);
    // draw
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

}
