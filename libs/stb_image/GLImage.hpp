//
//  GLImage.hpp
//  LearnOpenGL
//
//  Created by 王江 on 2020/11/21.
//

#ifndef GLImage_hpp
#define GLImage_hpp

#include <stdio.h>
#include <iostream>

class GLImage {
    
public:
    
    GLImage();
    ~GLImage();
    
    void load(const char *img_path);
    
    int getImageWidth() const;
    
    int getImageHeight() const;
    
    unsigned char *getImageData() const;
    
private:
    
    unsigned char *m_img_data;
    
    int m_img_width;
    
    int m_img_height;
    
};

#endif /* GLImage_hpp */
