//
//  GLShader.hpp
//  LearnOpenGL
//
//  Created by 王江 on 2020/11/19.
//

#ifndef GLShader_hpp
#define GLShader_hpp

#include <stdio.h>
#include <OpenGLES/ES3/gl.h>
#include <iostream>
#include <string>
#include <glm/glm.hpp>

namespace Renderer {

class GLShader {
    
    
public:
    GLShader(const char *vsPath, const char *fsPath);
    ~GLShader();
    
    /// get the shader id
    GLuint getShaderId() const;
    
    /// use the shader
    void use() const;
    
    /// set a float-type uniform's value
    /// @param name uniform's name
    /// @param value the value of the uniform
    void setFloatUniform(const std::string &name, float value) const;
    
    /// set a mat4 of floats as an uniform
    /// @param name uniform's name
    /// @param transform value
    void setMat4FloatUniform(const std::string &name, glm::mat4 &transform) const;
    
private:
    
    /// shader id
    GLuint m_shader_id { GL_INVALID_VALUE };
};
}


#endif /* GLShader_hpp */
