#ifndef _TILE_H_
#define _TILE_H_

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include "include/Creature.h"
#include "include/Wiolan.h"
#include "include/Auropodas.h"

using namespace sf;

class Tile {

    private:

        RectangleShape shape;

        Vector2f position;

        void initVariables();
        void initCreatureShape(Vector2f position);
        void setPosition(Vector2f position);

    public:
        float tileSize = 50.f;
        Vector2f center;
        Creature *creature;
        Tile *destinationTile;
        Vector2u discretePosition;

        bool blocked;
        
        Tile(Vector2f position, Vector2u discretePosition);
        ~Tile();  

        void render(RenderTarget *target);
        void renderShadow(RenderTarget *target);
        void renderDestinationShadow(RenderTarget *target);

        void initTileShape(Vector2f position, Vector2u discretePosition);

        void setSelected();
        void removeSelectedRender();
        void clearShadow();
        void deploySoldier(Creature *creature);
        void castShadow(Creature *creature);

        bool isBlocked();
        void setIsBlocked(bool blocked);

        float getTileSize();
        RectangleShape getShape();

        inline static float totalTileSize = 52.f;
};

#endif