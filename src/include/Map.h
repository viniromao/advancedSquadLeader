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

using namespace std;

class Map {
    private:
        vector<vector<Tile *>> map; 

        void initVariables();
        vector<vector<Tile *>> initMap(int x, int y);
        void getTile(Tile **tileSelected, Vector2f position);

    public:
        Map();
        virtual ~Map();

        void update();
        void render(RenderTarget *target);
        void renderShadows(RenderTarget *target);

        void clickEvent(Vector2f position);
        void deploySoldier(Vector2f position, Creature *creature);
        void selectTileWithCreature(Vector2f position,  Tile **tileToBeSelected);
        void castShadowOnTile(Vector2f position,Tile *tileSelected);
        void clearShadows();
};

#endif