#ifndef _MAIN_HUD_H_
#define _MAIN_HUD_H_

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include "include/ClickEventProducer.h"
#include "include/ClickEventObserver.h"

using namespace sf;

class MainHud {
    private:
        float margin = 20.0;
        float mainHudHeight = 200.0;
        RectangleShape mainHudBackground;

        ClickEventObserver *observer = nullptr;
    public:
        MainHud();
        MainHud(RenderWindow *window, ClickEventProducer *producer);
        virtual ~MainHud();

        void renderMainHud(RenderTarget *target);
};

#endif