#include "include/Game.h"

void Game::initVariables() {
    window = new RenderWindow(VideoMode(1920, 800), "Battles", Style::Close | Style::Titlebar);
    window->setFramerateLimit(144);

    map = new Map();

    Player newEnemy {};
    enemies.push_back(newEnemy);
    map->deploySoldierToTile(Coordinate(2,2), newEnemy.armySetup, newEnemy.army);

    selectedTile = nullptr;

    if (!font.loadFromFile("../assets/Cantarell-ExtraBold.otf"))
    {
        cout<<"font loading error!"<<endl;
        return;
    }


    this->clockText.setFont(font);
    this->clockText.setCharacterSize(30);
    this->clockText.setFillColor(sf::Color::Black);
    this->clockText.setPosition(Vector2f(200.0,0.0));

    // Coordinate coordinate = Coordinate(2, 3);

    // Tile * tile = map->getTile(coordinate);

    // cout<<"chamou: " << tile<<endl;

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
    if(gameState.getCurrentGameState() == "PLAN") {
        if(clock.timerSeconds <= 0) {
            gameState.evolveState("GAME");
            deltaClock = clock.elapsedTime;
            this->clockText.setString("Execution");
        } else {
            this->clockText.setString(to_string(clock.timerSeconds));   
        }
    }

    if(gameState.getCurrentGameState() == "GAME" && deltaClock == clock.elapsedTime) {  
        deltaClock = clock.elapsedTime + delaySeconds;       
        bool hasMovedTroops = map->makeOneStepMovementTroops(); 
        if (!hasMovedTroops) {
            cout<<"PLAN state called"<<endl;
            gameState.evolveState("PLAN");
            this->clock.startClock();
        }
    }

    map->setFogOfWar(&player.army);
    map->clearShadows();

    updateMousePositions();
    processPollEvents();

    clock.update();
}

void Game::render() {
    window->clear();

    map->render(window);
    map->renderDestinationShadows(window);
    map->renderShadows(window);
    map->renderPaths(window);

    window->draw(clockText);
    window->display();
}

void Game::processPollEvents() {
    if(this->selectedTile != nullptr) {
        map->castShadowOnTile(mousePosView, selectedTile);
    }
    
    while (window->pollEvent(event))
    {
        switch (event.type)
        {
        case Event::Closed:
            cout<<"Event for closing the program called"<<endl;
            window->close();
            break;
        case Event::KeyPressed:
            if(event.key.code == Keyboard::Escape) {
                cout<<"Event for closing the program called"<<endl;
                window->close();
            }

            if(event.key.code == Keyboard::Enter) {
               
            }
        case Event::MouseButtonPressed:
            if (gameState.getCurrentGameState() == "ARMY_SETUP"){
                if(map->deploySoldierToTile(mousePosView, player.armySetup, player.army)) {
                    gameState.evolveState("PLAN");
                    this->clock.startClock();
                }
                break;
            }


            if(gameState.getCurrentGameState() == "PLAN") {
                if (selectedTile != nullptr) {
                    map->setCreatureDestination(mousePosView, selectedTile);
                    pathFinding = new PathFinding(map);
                    map->setPath(pathFinding->getPath(selectedTile));
                    delete pathFinding;

                    selectedTile->removeSelectedRender();
                    selectedTile = nullptr;
                    break;
                }

                map->selectTileWithCreature(mousePosView, &selectedTile);
                break;
            }


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

