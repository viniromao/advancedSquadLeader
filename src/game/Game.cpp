#include "include/Game.h"
#include "include/Map.h"

void Game::initVariables() {
    window = new RenderWindow(VideoMode(800, 600), "Battles", Style::Close | Style::Titlebar);
    window->setFramerateLimit(144);
    ImGui::SFML::Init(*window);
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

    ImGui::SFML::Update(*window, clock.restart());
    ImGui::Begin("Game Gui");
    ImGui::Button("Example");
    ImGui::End();

    updateMousePositions();
    processPollEvents();
}

void Game::render() {
    window->clear();

    map->render(window);

    ImGui::SFML::Render(*window);

    window->display();
}

void Game::processPollEvents() {
    
    while (window->pollEvent(event))
    {
        ImGui::SFML::ProcessEvent(*window, event);
       
        
        switch (event.type)
        {
        case Event::Closed:
            window->close();
            ImGui::SFML::Shutdown();
            break;
        case Event::KeyPressed:
            if(event.key.code == Keyboard::Escape) {
                window->close();
                ImGui::SFML::Shutdown();
            }
            break;
        case Event::MouseButtonPressed:
            if(!ImGui::GetIO().WantCaptureMouse) {
                if (gameState.getCurrentGameState() == "ARMY_SETUP"){
                    if (!armySetup.haveSoldiersToDeploy()) {
                        gameState.evolveState();
                        break;
                    }

                    map->deploySoldier(mousePosView, armySetup.getNextSoldierToDeploy());
                    break;
                }
                map->clickEvent(mousePosView);
            }
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

