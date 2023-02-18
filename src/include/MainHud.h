#ifndef _MAIN_HUD_H_
#define _MAIN_HUD_H_

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

using namespace sf;

class MainHud {
    private:
        float margin = 20.0;
        float mainHudHeight = 200.0;
        RectangleShape mainHudBackground;
    public:
        MainHud();
        MainHud(RenderWindow *window);
        virtual ~MainHud();

        void renderMainHud(RenderTarget *target);
};

#endif