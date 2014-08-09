//
//  OpenGL.hpp
//  randomgl
//
//  Created by Jean Gravier on 09/08/2014.
//  Copyright (c) 2014 Jean Gravier. All rights reserved.
//

#ifndef randomgl_OpenGL_hpp
#define randomgl_OpenGL_hpp

# ifdef __APPLE__
#  include <OpenGL/gl3.h>
# else
#   ifndef GL_GLEXT_PROTOTYPES
#    define GL_GLEXT_PROTOTYPES
#   endif
#  include <GL/gl.h>
#  include <GL/glext.h>
# else
#
# endif


#endif
