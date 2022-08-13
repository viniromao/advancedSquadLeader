#ifndef _GAME_H_
#define _GAME_H_
#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include"Map.h"

using namespace sf;

class Game {
    private:
        RenderWindow *window;
        Event event;

        Vector2i mousePosWindow;
        Vector2f mousePosView;

        Map *map;

        void initVariables();

    public:
        Game();
        virtual ~Game();

        void update();
        void render();

        void processPollEvents();

        bool running();
        void updateMousePositions();
};

#endif