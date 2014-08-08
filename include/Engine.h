//
//  Engine.h
//  randomgl
//
//  Created by Jean Gravier on 07/08/2014.
//  Copyright (c) 2014 Jean Gravier. All rights reserved.
//

#ifndef __randomgl__Engine__
#define __randomgl__Engine__

#include <iostream>
#include <SDL2/SDL.h>

class 	Engine
{
    
public:
    Engine(int windowX = 800, int windowY = 600);
    virtual ~Engine();
    
    bool	init();
    void	start();
    void	stop();
    
    //    Getters
    bool	isRunning() const;
    
    //    Setters

private:
    int				_windowX;
    int				_windowY;
    
    bool			_running;
    
    SDL_Window		*_window;
    SDL_GLContext	_context;
    SDL_Event		_event;
};

#endif /* defined(__randomgl__Engine__) */
