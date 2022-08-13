#ifndef _TILE_H_
#define _TILE_H_

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include "Creature.h"

using namespace sf;

class Tile {

    private:
        float tileSize = 50.f;

        RectangleShape shape;

        Creature *creature;


        void initVariables();

    public:

        Tile();
        ~Tile();  

        void render(RenderTarget *target, Vector2f position);

        void initTileShape();

        float getTileSize();
};

#endif