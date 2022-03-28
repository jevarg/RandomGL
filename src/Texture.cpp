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
: _id(0)
{
}

Texture::~Texture()
{
}

/***************/
/****Getters****/
/***************/

int Texture::getID() const
{
    return (_id);
}

bool Texture::load(const std::string &path)
{
    SDL_Surface *SDLTexture = IMG_Load(path.c_str());
    GLenum textureFormat = 0;
    GLenum textureByteOrder = 0;

    if (SDLTexture == NULL)
    {
        std::cerr << "Error: " << SDL_GetError() << std::endl;
        return (false);
    }

    //    OpenGL texture generation
    glGenTextures(1, &_id);

    //    Texture binding
    glBindTexture(GL_TEXTURE_2D, _id);

    if (SDLTexture->format->BytesPerPixel == 3) // 3 -> R G B
    {
        textureFormat = GL_RGB;

        //        Checking texture byte order
        if (SDLTexture->format->Rmask == 0xff)
            textureByteOrder = GL_RGB;
        else
            textureByteOrder = GL_BGR;
    }
    else if (SDLTexture->format->BytesPerPixel == 4) // 4 -> R G B A
    {
        textureFormat = GL_RGBA;

        //        Checking texture byte order
        if (SDLTexture->format->Rmask == 0xff)
            textureByteOrder = GL_RGBA;
        else
            textureByteOrder = GL_BGRA;
    }
    else
    {
        std::cerr << "Texture format error !" << std::endl;
        SDL_FreeSurface(SDLTexture);
        return (false);
    }

    //    Copying texture data
    glTexImage2D(GL_TEXTURE_2D, 0, textureFormat, SDLTexture->w, SDLTexture->h, 0, textureByteOrder, GL_UNSIGNED_BYTE, SDLTexture->pixels);

    //    Setting texture filtering behaviour
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    //    Texture unbinding
    glBindTexture(GL_TEXTURE_2D, 0);

    SDL_FreeSurface(SDLTexture);

    return (true);
}