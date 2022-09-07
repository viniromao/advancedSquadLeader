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

#include"include/Map.h"
#include"../resources/imgui/imgui.h"
#include"../resources/imgui/imgui-SFML.h"

#include"include/GameState.h"
#include"include/Army.h"
#include"include/ArmySetup.h"
#include"include/Tile.h"

using namespace sf;

class Game {
    private:
        RenderWindow *window;
        Event event;
        Clock clock;
        GameState gameState {};
        Army army {};
        ArmySetup armySetup {};

        Tile *selectedTile;

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