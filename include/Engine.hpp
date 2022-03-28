//
//  Engine.h
//  randomgl
//
//  Created by Jean Gravier on 07/08/2014.
//  Copyright (c) 2014 Jean Gravier. All rights reserved.
//

#ifndef __randomgl__Engine__
#define __randomgl__Engine__

#define MAX_FPS 60

#include <iostream>
#include <SDL2/SDL.h>
#include "Clock.hpp"
#include "Camera.hpp"
#include "Shader.hpp"

class Engine
{

public:
    Engine(int windowX = 800, int windowY = 600);
    virtual ~Engine();

    bool init();
    void start();
    void stop();

    //    Getters
    bool isRunning() const;

    //    Setters

private:
    int _windowWidth;
    int _windowHeight;

    bool _running;

    SDL_Window *_window;
    SDL_GLContext _context;
    SDL_Event _event;

    Camera *_camera;
    Shader _mainShader;
};

#endif /* defined(__randomgl__Engine__) */
