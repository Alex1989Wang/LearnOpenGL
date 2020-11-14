//
//  GLRenderer.hpp
//  LearnOpenGL
//
//  Created by 王江 on 2020/11/5.
//

#ifndef GLRenderer_hpp
#define GLRenderer_hpp

#include <OpenGLES/ES3/gl.h>
#include <stdio.h>

namespace Renderer {

/// gl renderer
class GLRenderer {

public:
    
    virtual ~GLRenderer() { };

    /// the virtual funtion for renderer
    virtual void render() = 0;
    
};

}

#endif /* GLRenderer_hpp */
