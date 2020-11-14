//
//  GLRectangleRenderer.hpp
//  LearnOpenGL
//
//  Created by 王江 on 2020/11/7.
//

#ifndef GLRectangleRenderer_hpp
#define GLRectangleRenderer_hpp

#include <stdio.h>
#include <iostream>

#include "GLRenderer.cpp"

namespace Renderer {

class GLRectangleRenderer: public GLRenderer {
    
public:
    
    /// constructor and destructor
    GLRectangleRenderer();
    virtual ~GLRectangleRenderer() override;

    /// override the render function
    virtual void render() override;
    
private:
    /// shader program
    GLuint m_shaderProgram { GL_INVALID_VALUE };
    
    /// vertex array object
    GLuint m_vbo { GL_INVALID_VALUE };
    GLuint m_ebo { GL_INVALID_VALUE };
    GLuint m_vao { GL_INVALID_VALUE };
};

}

#endif /* GLRectangleRenderer_hpp */
