//
//  main.cpp
//  randomgl
//
//  Created by Jean Gravier on 05/08/2014.
//  Copyright (c) 2014 Jean Gravier. All rights reserved.
//

#include <iostream>
#include "Engine.hpp"

int main(int argc, char **argv)
{
    Engine game(800, 600);
    game.init();
    game.start();

    return (0);
}
