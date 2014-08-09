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
# include <SDL2_image/SDL_image.h>
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
