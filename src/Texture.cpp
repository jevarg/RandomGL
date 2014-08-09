//
//  Texture.cpp
//  randomgl
//
//  Created by Jean Gravier on 08/08/2014.
//  Copyright (c) 2014 Jean Gravier. All rights reserved.
//

#include <iostream>
#include "Texture.hpp"

Texture::Texture()
: _id(0), _SDLTexture(NULL)
{
    
}

Texture::~Texture()
{
    
}

/***************/
/****Getters****/
/***************/

int		Texture::getID() const
{
    return (_id);
}

bool Texture::load(const std::string &path)
{
    GLenum	textureFormat = 0;
    GLenum	textureByteOrder = 0;
    
    _SDLTexture = IMG_Load(path.c_str());
    if (_SDLTexture == NULL)
    {
        std::cerr << "Error: " << SDL_GetError() << std::endl;
        return (false);
    }
    
    //    OpenGL texture generation
    glGenTextures(1, &_id);
    
    //    Texture binding
    glBindTexture(GL_TEXTURE_2D, _id);
    
    if (_SDLTexture->format->BytesPerPixel == 3) // 3 -> R G B
    {
        textureFormat = GL_RGB;
        
        //        Checking texture byte order
        if (_SDLTexture->format->Rmask == 0xff)
            textureByteOrder = GL_RGB;
        else
            textureByteOrder = GL_BGR;
    }
    else if (_SDLTexture->format->BytesPerPixel == 4) // 4 -> R G B A
    {
        textureFormat = GL_RGBA;
        
        //        Checking texture byte order
        if (_SDLTexture->format->Rmask == 0xff)
            textureByteOrder = GL_RGBA;
        else
            textureByteOrder = GL_BGRA;
    }
    else
    {
        std::cerr << "Texture format error !" << std::endl;
        SDL_FreeSurface(_SDLTexture);
        return (false);
    }
    
    //    Copying texture data
    glTexImage2D(GL_TEXTURE_2D, 0, textureFormat, _SDLTexture->w, _SDLTexture->h, 0, textureByteOrder, GL_UNSIGNED_BYTE, _SDLTexture->pixels);
    
    //    Setting texture filtering behaviour
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    //    Texture unbinding
    glBindTexture(GL_TEXTURE_2D, 0);
    
    return (true);
}