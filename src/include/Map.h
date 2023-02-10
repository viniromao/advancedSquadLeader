#ifndef _MAP_H_
#define _MAP_H_

#include<vector>
#include<iostream>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include"include/Tile.h"
#include"include/ArmySetup.h"
#include"include/Path.h"

using namespace std;

class Map {
    private:
        

        void initVariables();
        vector<vector<Tile *>> initMap(int x, int y);
        Vector2f getTile(Tile **tileSelected, Vector2f position);

    public:
        vector<vector<Tile *>> paths {};
        vector<vector<Tile *>> map;

        Map();
        virtual ~Map();

        void update();
        void render(RenderTarget *target);
        void renderShadows(RenderTarget *target);
        void renderDestinationShadows(RenderTarget *target);

        void clickEvent(Vector2f position);
        bool deploySoldierToTile(Vector2f position, ArmySetup &armySetup, Army &army);
        void selectTileWithCreature(Vector2f position,  Tile **tileToBeSelected);
        void setCreatureDestination(Vector2f position,  Tile *tileToBeSelected);
        void castShadowOnTile(Vector2f position,Tile *tileSelected);
        void clearShadows();
        void renderPaths(RenderTarget *target);

        vector<Tile *> getPath(Tile *initialTile);
        void makeOneStepMovementTroops();
        void setFogOfWar(Army *army);

};

#endif