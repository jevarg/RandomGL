//
//  Engine.cpp
//  randomgl
//
//  Created by Jean Gravier on 07/08/2014.
//  Copyright (c) 2014 Jean Gravier. All rights reserved.
//

#include "Engine.hpp"
#include "OpenGL.hpp"
#include "Cube.hpp"

Engine::Engine(int windowX, int windowY)
: _windowWidth(windowX), _windowHeight(windowY), _running(false), _mainShader("assets/shaders/basic.vert", "assets/shaders/basic.frag")
{
    _window = NULL;
    _context = 0;
    _camera = NULL;
    _event = {0};
}

Engine::~Engine()
{
    //    SDL2 Exit

    if (_context)
    {
        SDL_GL_DeleteContext(_context);
    }
    if (_window)
    {
        SDL_DestroyWindow(_window);
    }
    SDL_Quit();

    if (_camera)
    {
        delete _camera;
    }
}


/***************/
/****Getters****/
/***************/

bool Engine::isRunning() const
{
    return (_running);
}

/***************/
/****Setters****/
/***************/


/***************/
/****Methods****/
/***************/

bool Engine::init()
{
    //    SDL2 Init

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL2 init error: " << SDL_GetError() << std::endl;
        return (false);
    }

    //    Setting OpenGL Version

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

#ifdef __APPLE__

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

#endif // __APPLE__

    //    Enabling Double Buffering

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    //    Window Creation

    _window = SDL_CreateWindow("RandomGL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _windowWidth, _windowHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    if (!_window)
    {
        std::cout << "SDL2 window error: " << SDL_GetError() << std::endl;
        return (false);
    }

    //    OpenGL context creation

    _context = SDL_GL_CreateContext(_window);

    if (!_context)
    {
        std::cerr << "OpenGL context error: " << SDL_GetError() << std::endl;
        return (false);
    }

#ifdef WIN32
    GLenum glewReturn = glewInit();

    if (glewReturn != GLEW_OK)
    {
        std::cout << "GLEW init error : " << glewGetErrorString(glewReturn) << std::endl;
        return (false);
    }
#endif // WIN32

    return (true);
}

void Engine::stop()
{
    _running = false;
}

void Engine::start()
{
    Clock clock;
    Cube cube;
    unsigned int frameRate = (1000 / MAX_FPS);
    unsigned int elapsedTime = 0;

    _running = true;

    _camera = new Camera(_windowWidth, _windowHeight);
    _camera->setPosition(glm::vec3(0, 3, 3));

    //    cube.loadTexture("assets/textures/cube/grass.png");
    cube.build();

    _mainShader.create();


    //    Main Loop

    while (_running)
    {
        //        clock.reset();
        SDL_PollEvent(&_event);
        if (_event.type == SDL_QUIT || _event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
        {
            stop();
        }


        //    Window clearing and swapping

        glClear(GL_COLOR_BUFFER_BIT);

        _camera->lookAt();

        _mainShader.bind();
        _mainShader.setUniform("projection", _camera->getProjection());
        _mainShader.setUniform("view", _camera->getTransformation());

        cube.draw(&_mainShader);
        //        _mainShader.setUniform("gColor", glm::vec4(1));
        //        _mainShader.setUniform("camPos", _camera->getPosition());
        //        _mainShader.setUniform("light", glm::vec4(0));

        //        FPS limit management

        //        elapsedTime = clock.getElapsed();
        //        if (elapsedTime < frameRate)
        //            SDL_Delay(frameRate - elapsedTime);
        //        if (elapsedTime > 0.1)
        //            	std::cout << "FPS: " << frameRate / elapsedTime << std::endl;

        SDL_GL_SwapWindow(_window);
    }
}
