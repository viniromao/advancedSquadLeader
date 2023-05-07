#ifndef _GAME_H_
#define _GAME_H_

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <chrono>
#include <string.h>
#include <cmath>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glu.h>

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
#include"include/Mesh.h"

using namespace sf;

struct WindowSize {
    unsigned int x = 2300;
    unsigned int y = 1000;
};

class Game {
    private:
        ClickEventProducer *producer = new ClickEventProducer();
        ClickEventObserver *clickEventObserver = new ClickEventObserver(*producer);


        RenderWindow *window;
        GLFWwindow *mainWindow;
        glm::mat4 projection;
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
        Creature *currentCreatureHudActive;

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