//
//  Texture.hpp
//  randomgl
//
//  Created by Jean Gravier on 08/08/2014.
//  Copyright (c) 2014 Jean Gravier. All rights reserved.
//

#ifndef randomgl_Texture_hpp
# define randomgl_Texture_hpp

# include <string>
# include <SDL2/SDL.h>

# ifdef __APPLE__
# 	include <SDL2_image/SDL_image.h>
# else // WIN32 and LINUX
# 	include <SDL2/SDL_image.h>
# endif // __APPLE__

# include "OpenGL.hpp"

class Texture
{

public:
    Texture();
    virtual ~Texture();

    bool	load(const std::string &path);


    //    Getters
    int		getID() const;

private:
    GLuint			_id;
};

#endif
