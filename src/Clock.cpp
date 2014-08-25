//
//  Clock.cpp
//  randomgl
//
//  Created by Jean Gravier on 14/08/2014.
//  Copyright (c) 2014 Jean Gravier. All rights reserved.
//

#include <SDL2/SDL.h>
#include "Clock.hpp"

Clock::Clock()
{
    
}

Clock::~Clock()
{
    
}

void	Clock::reset()
{
    _ticks = SDL_GetTicks();
}

unsigned int	Clock::getElapsed() const
{
    return (SDL_GetTicks() - _ticks);
}