#include "Game.h"
#include "Map.h"

void Game::initVariables() {
    window = new RenderWindow(VideoMode(800, 600), "Battles", Style::Close | Style::Titlebar);
    map = new Map();

}

Game::Game() {
    initVariables();
    window->setFramerateLimit(60);
}

Game::~Game() {
    delete window;
    delete map;
}

void Game::update() {
    updateMousePositions();
    processPollEvents();
}

void Game::render() {
    window->clear();

    map->render(window);

    window->display();
}

void Game::processPollEvents() {
    while (window->pollEvent(event))
    {
        switch (event.type)
        {
        case Event::Closed:
            window->close();
            break;
        case Event::KeyPressed:
            if(event.key.code == Keyboard::Escape)
                window->close();
        case Event::MouseButtonPressed:
            map->clickEvent(mousePosView);
            break;
        default:
            break;
        }
    }
}

bool Game::running() {
   return window->isOpen(); 
}

void Game::updateMousePositions()
{
    mousePosWindow = Mouse::getPosition(*window);
    mousePosView = window->mapPixelToCoords(mousePosWindow);
}

