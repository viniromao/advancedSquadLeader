#ifndef _TILE_H_
#define _TILE_H_

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include "include/Creature.h"
#include "include/Wiolan.h"

using namespace sf;

class Tile {

    private:
        float tileSize = 50.f;

        RectangleShape shape;

        Creature *creature;


        void initVariables();
        void initCreatureShape(Vector2f position);

    public:

        Tile(Vector2f position);
        ~Tile();  

        void render(RenderTarget *target);

        void initTileShape(Vector2f position);

        void setDeadPixel();

        float getTileSize();
        RectangleShape getShape();

        inline static float totalTileSize = 52.f;
};

#endif