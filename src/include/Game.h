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
#include"include/MainHud.h"
#include"include/ClickEventProducer.h"
#include"include/ClickEventObserver.h"

using namespace sf;

struct WindowSize {
    unsigned int x = 1600;
    unsigned int y = 800;
};

class Game {
    private:
        ClickEventProducer *producer = new ClickEventProducer();
        ClickEventObserver *clickEventObserver = new ClickEventObserver(*producer);

        RenderWindow *window;
        Event event;
        GameState gameState {};
        GameClock clock {};
        int deltaClock = 0;
        int delaySeconds = 1;
        Font font;
        Text clockText;
        Player player {producer};
        vector<Player> enemies {};
        MainHud mainHud;

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