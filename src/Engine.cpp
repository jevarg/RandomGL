//
//  Engine.cpp
//  randomgl
//
//  Created by Jean Gravier on 07/08/2014.
//  Copyright (c) 2014 Jean Gravier. All rights reserved.
//

#include "Engine.h"

Engine::Engine(int windowX, int windowY)
: _windowX(windowX), _windowY(windowY), _running(false)
{
    _window = NULL;
    _context = 0;
//    _event = NULL;
}

Engine::~Engine()
{
    //    SDL2 Exit
    
    if (_context)
    SDL_GL_DeleteContext(_context);
    if (_window != NULL)
        SDL_DestroyWindow(_window);
    SDL_Quit();
}


/***************/
/****Getters****/
/***************/

bool	Engine::isRunning() const
{
    return (_running);
}

/***************/
/****Setters****/
/***************/



/***************/
/****Methods****/
/***************/

bool	Engine::init()
{
    //    SDL2 Init
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL2 init error: " << SDL_GetError() << std::endl;
        return (false);
    }
    
    //    Setting OpenGL Version
    
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    
#ifdef __APPLE__
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
#endif
    
    //    Enabling Double Buffering
	
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    
    //    Window Creation
    
    _window = SDL_CreateWindow("RandomGL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _windowX, _windowY, SDL_WINDOW_SHOWN);
    
    if(_window == 0)
    {
        std::cout << "Erreur lors de la creation de la window : " << SDL_GetError() << std::endl;
        return (false);
    }
    
    //    OpenGL context creation
    
    _context = SDL_GL_CreateContext(_window);
    
    if (!_context)
    {
        std::cerr << "OpenGL context error: " << SDL_GetError() << std::endl;
        return (false);
    }

    return (true);
}

void	Engine::stop()
{
    _running = false;
}

void	Engine::start()
{
    _running = true;
    
    //    Main Loop
    
    while (_running)
    {
        SDL_WaitEvent(&_event);
        if (_event.type == SDL_QUIT || _event.key.keysym.sym == SDLK_ESCAPE)
            stop();
    }
}