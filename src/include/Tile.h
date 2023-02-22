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
#include "include/Coordinate.h"

using namespace sf;

enum FogOfWarState{
    VISIBLE,
    FADED,
    SHADOWED
};

class Tile {

    private:

        RectangleShape shape;
        Texture grassTexture;


        Vector2f position;

        RectangleShape treeShape;
        Texture texture;

        bool hasTree = false;

        void initVariables();
        void initCreatureShape(Vector2f position);
        void setPosition(Vector2f position);

    public:
        float tileSize = 50.f;
        Vector2f center;
        Vector2f upperLeftCorner;
        Vector2f upperRightCorner;
        Vector2f bottomRightCorner;
        Vector2f bottomLeftCorner;
        Creature *creature;
        Tile *destinationTile;
        Coordinate coordinate;
        Vector2i discretePosition;
        FogOfWarState fogOfWarState;

        bool blocked;
        
        Tile(Vector2f position, Vector2i discretePosition);
        ~Tile();  

        void render(RenderTarget *target);
        void renderTree(RenderTarget *target);
        void renderCreatureHud(RenderTarget *target);
        void renderShadow(RenderTarget *target);
        void renderDestinationShadow(RenderTarget *target);

        void initTileShape(Vector2f position, Vector2i discretePosition);

        void setSelected();
        void removeSelectedRender();
        void clearShadow();
        void deploySoldier(Creature *creature);
        void castShadow(Creature *creature);

        bool isBlocked();
        void setIsBlocked(bool blocked);
        void setIsClosed();
        void setIsFaded();
        void setIsOpen();
        void setTree();
        void setIsVisible(bool visible);

        float getTileSize();
        Coordinate getCoordinate();
        RectangleShape getShape();

        inline static float totalTileSize = 52.f;
};

#endif