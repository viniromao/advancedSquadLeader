#ifndef _MAP_H_
#define _MAP_H_

#include <vector>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include"Tile.h"

using namespace std;

class Map {
    private:
        vector<vector<Tile>> map; 

        void initVariables();
        vector<vector<Tile>> initMap(int x, int y);

    public:
        Map();
        virtual ~Map();

        void render(RenderTarget *target);
};

#endif