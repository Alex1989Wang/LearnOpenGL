//
//  GLEffectRenderer.hpp
//  LearnOpenGL
//
//  Created by 王江 on 2020/11/5.
//

#ifndef GLEffectRenderer_hpp
#define GLEffectRenderer_hpp

#include <stdio.h>
#include <iostream>

#include "GLRenderer.cpp"

namespace Renderer {

class GLTriangleRenderer: public GLRenderer {
    
public:
    
    /// constructor and destructor
    GLTriangleRenderer();
    virtual ~GLTriangleRenderer() override;
    
    /// override the render function
    virtual void render() override;
    
private:
    /// shader program
    GLuint m_shaderProgram { GL_INVALID_VALUE };
    
    /// vertex array object
    GLuint m_vbo { GL_INVALID_VALUE };
    GLuint m_vao { GL_INVALID_VALUE };
};

}

#endif /* GLEffectRenderer_hpp */
