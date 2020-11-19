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
#include "GLShader.hpp"

namespace Renderer {

class GLTextureRenderer: public GLRenderer {

public:
    
    /// constructor and deconstructor
    GLTextureRenderer(const char *vsPath, const char *fsPath);
    ~GLTextureRenderer();
    
    void setTextureImagePath(const char *imgPath);
    
    virtual void render() override;
    
private:
    GLShader m_shader;
    
    std::string m_img_path;
    
    GLuint m_tid { GL_INVALID_VALUE };
    
    /// vertex array object
    GLuint m_vbo { GL_INVALID_VALUE };
    GLuint m_ebo { GL_INVALID_VALUE };
    GLuint m_vao { GL_INVALID_VALUE };
};

}

#endif /* GLTextureRenderer_hpp */
