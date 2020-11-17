//
//  GLTextureRenderer.hpp
//  LearnOpenGL
//
//  Created by JiangWang on 2020/11/17.
//

#ifndef GLTextureRenderer_hpp
#define GLTextureRenderer_hpp

#include <stdio.h>
#include <string>
#include "GLRenderer.hpp"


namespace Renderer {

class GLTextureRenderer: public GLRenderer {

public:
    
    /// constructor and deconstructor
    GLTextureRenderer();
    ~GLTextureRenderer();
    
    void setTextureImagePath(const char *imgPath);
    
    virtual void render() override;
    
private:
    std::string m_img_path;
    
    GLuint m_tid { GL_INVALID_VALUE };
    
    /// shader program
    GLuint m_shaderProgram { GL_INVALID_VALUE };
    
    /// vertex array object
    GLuint m_vbo { GL_INVALID_VALUE };
    GLuint m_ebo { GL_INVALID_VALUE };
    GLuint m_vao { GL_INVALID_VALUE };
};

}

#endif /* GLTextureRenderer_hpp */
