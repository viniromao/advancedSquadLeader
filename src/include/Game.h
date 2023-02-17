#ifndef _GAME_H_
#define _GAME_H_
#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <chrono>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include"include/Map.h"
#include"include/PathFinding.h"
#include"include/GameState.h"
#include"include/ArmySetup.h"
#include"include/Tile.h"
#include"include/GameClock.h"
#include"include/Player.h"


using namespace sf;

class Game {
    private:
        RenderWindow *window;
        Event event;
        GameState gameState {};
        GameClock clock {};
        int deltaClock = 0;
        int delaySeconds = 1;
        Font font;
        Text clockText;
        Player player {};
        vector<Player> enemies {};

        Tile *selectedTile;
        PathFinding *pathFinding;

        Vector2i mousePosWindow;
        Vector2f mousePosView;

        Map *map;

        std::chrono::high_resolution_clock::time_point begin;

        void initVariables();

    public:
        Game();
        virtual ~Game();

        void update();
        void render();

        void processPollEvents();

        bool running();
        void updateMousePositions();
        void startClock();
        unsigned getPassedSeconds();
};

#endif