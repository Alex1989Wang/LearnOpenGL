//
//  GLImage.cpp
//  LearnOpenGL
//
//  Created by 王江 on 2020/11/21.
//

#include "GLImage.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

GLImage::GLImage():
m_img_data(nullptr),
m_img_width(0),
m_img_height(0) {
    
};

GLImage::~GLImage() {
    stbi_image_free(m_img_data);
};

void GLImage::load(const char *img_path) {
    int w, h, channels = 0;
    unsigned char *data = stbi_load(img_path, &w, &h, &channels, 0);
    m_img_width = w;
    m_img_height = h;
    m_img_data = data;
}

int GLImage::getImageWidth() const {
    return m_img_width;
}

int GLImage::getImageHeight() const {
    return m_img_height;
}

unsigned char * GLImage::getImageData() const {
    return m_img_data;
}
