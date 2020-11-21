//
//  GLRotationRenderer.hpp
//  LearnOpenGL
//
//  Created by 王江 on 2020/11/21.
//

#ifndef GLRotationRenderer_hpp
#define GLRotationRenderer_hpp

#include <stdio.h>
#include <string>
#include "GLShader.hpp"
#include "GLRenderer.hpp"

namespace Renderer {

class GLRotationRenderer: public GLRenderer {

public:
    
    /// constructor and deconstructor
    GLRotationRenderer(const char *vsPath, const char *fsPath);
    ~GLRotationRenderer();
    
    void setTextureImagePath(const char *imgPath);
    
    virtual void render() override;
    
private:
    GLShader m_shader;
    
    std::string m_img_path;
    
    GLuint m_tid { GL_INVALID_VALUE };
    
    GLuint m_render_count { 0 };
    
    /// vertex array object
    GLuint m_vbo { GL_INVALID_VALUE };
    GLuint m_ebo { GL_INVALID_VALUE };
    GLuint m_vao { GL_INVALID_VALUE };
    
};

}


#endif /* GLRotationRenderer_hpp */
