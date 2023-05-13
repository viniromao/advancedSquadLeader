#include "include/Game.h"
#include "include/ASLTexture.h"

//=========================NEW CODE ===============================
const GLint WIDTH = 800, HEIGHT = 600;
const float toRadians = 3.14159265f / 180.0f;

GLuint VBO, VAO, IBO, shader, uniformModel, uniformProjection;

float velocity = 0.001;
float velocity2 = 0;

bool direction = true;
float triOffset = 0.0f;
float triMaxOffset = 0.7f;
float triIncrement = 0.0005f;

std::vector<Mesh*> meshList;

float curAngle = 45.0f;

ASLTexture texture;

bool sizeDirection = true;
float curSize = 0.4f;
float maxSize = 0.8f;
float minSize = 0.1f;


// Vertex Shader code
static const char* vShader = "#version 330\n\
\n\
layout (location = 0) in vec3 pos;\n\
layout (location = 1) in vec2 tex;\n\
\n\
out vec4 vCol;\n\
out vec2 TexCoord;\n\
\n\
uniform mat4 model;\n\
uniform mat4 projection;\n\
uniform mat4 view;\n\
\n\
void main()\n\
{\n\
	gl_Position = projection * model * vec4(pos, 1.0);\n\
	vCol = vec4(clamp(pos, 0.0f, 1.0f), 1.0f);\n\
	\n\
	TexCoord = tex;\n\
}";

// Fragment Shader
static const char* fShader = "                                                \n\
#version 330\n\
\n\
in vec4 vCol;\n\
in vec2 TexCoord;\n\
\n\
out vec4 colour;\n\
\n\
uniform sampler2D theTexture;\n\
\n\
void main()\n\
{\n\
	colour = texture(theTexture, TexCoord);;\n\
}";
//=================================================================

void CreateTriangle(std::vector<glm::vec3> positions)
{
	unsigned int indices[] = { 
		0,1,2,
        2,1,3,
        3,1,4,
        0,1,4
	};

    float size = 1;
    float newSize = 1.f;

    for(size_t i = 0; i < positions.size() ; i++) {
        GLfloat vertices[] = {
            positions[i].x - size,  positions[i].y,         4.f,                               newSize, newSize,
            positions[i].x,         positions[i].y,         1.f,                                newSize/2, newSize/2,
            positions[i].x ,        positions[i].y + size,  0.f,                                0.f, newSize,
            positions[i].x + size,  positions[i].y ,        0.f,                                0.f, 0.f,
            positions[i].x,         positions[i].y - size,  0.f,                                newSize, 0.f
	    };

        Mesh *obj1 = new Mesh();
        obj1->CreateMesh(vertices, indices, 30, 12);
        meshList.push_back(obj1);
    };
}

void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType)
{
	GLuint theShader = glCreateShader(shaderType);

	const GLchar* theCode[1];
	theCode[0] = shaderCode;

	GLint codeLength[1];
	codeLength[0] = strlen(shaderCode);

	glShaderSource(theShader, 1, theCode, codeLength);
	glCompileShader(theShader);

	GLint result = 0;
	GLchar eLog[1024] = { 0 };

	glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);
	if (!result) 
	{
		glGetShaderInfoLog(theShader, 1024, NULL, eLog);
		fprintf(stderr, "Error compiling the %d shader: '%s'\n", shaderType, eLog);
		return;
	}

	glAttachShader(theProgram, theShader);
}

void CompileShaders()
{
	shader = glCreateProgram();

	if (!shader) 
	{
		printf("Failed to create shader\n");
		return;
	}

	AddShader(shader, vShader, GL_VERTEX_SHADER);
	AddShader(shader, fShader, GL_FRAGMENT_SHADER);

	GLint result = 0;
	GLchar eLog[1024] = { 0 };

	glLinkProgram(shader);
	glGetProgramiv(shader, GL_LINK_STATUS, &result);
	if (!result) 
	{
		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
		printf("Error linking program: '%s'\n", eLog);
		return;
	}

	glValidateProgram(shader);
	glGetProgramiv(shader, GL_VALIDATE_STATUS, &result);
	if (!result) 
	{
		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
		printf("Error validating program: '%s'\n", eLog);
		return;
	}

	uniformModel = glGetUniformLocation(shader, "model");
	uniformProjection = glGetUniformLocation(shader, "projection");
}

void Game::initVariables() {

    if (!glfwInit())
	{
		printf("GLFW initialisation failed!");
		glfwTerminate();
		return;
	}

	// Setup GLFW window properties
	// OpenGL version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Core Profile
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// Allow Forward Compatbility
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	// Create the window
	this->mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", NULL, NULL);
	if (!this->mainWindow)
	{
		printf("GLFW window creation failed!");
		glfwTerminate();
		return;
	}

	// Get Buffer Size information
	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	// Set context for GLEW to use
	glfwMakeContextCurrent(mainWindow);

	// Allow modern extension features
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		printf("GLEW initialisation failed!");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return;
	}

	glEnable(GL_DEPTH_TEST);

	// Setup Viewport size
	glViewport(0, 0, bufferWidth, bufferHeight);

    std::vector<glm::vec3> positions = {
        glm::vec3(0,0,1),
    };

	CreateTriangle(positions);
	CompileShaders();

    float distance = 4.f;

	this->projection = glm::ortho(-distance, distance, -distance, distance, -distance*10, 10*distance);

    texture = ASLTexture("../assets/sprites/grass2.png");
    texture.LoadTexture();

    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(glm::value_ptr(projection));


    // Set up the viewport

    
    // WindowSize windowSize {};
    // window = new RenderWindow(VideoMode(windowSize.x, windowSize.y), "Battles", Style::Close | Style::Titlebar);
    // window->setFramerateLimit(144);
    // mainHud = MainHud(window, this->producer);

    // map = new Map(this->producer);

    // player.army.deployRegion = DeployRegion{Coordinate(0,0), Coordinate(7, 9)};

    // Player newEnemy {producer};
    // enemies.push_back(newEnemy);
    // map->deploySoldierToTile(Coordinate(2,2), newEnemy.armySetup, newEnemy.army);

    // selectedTile = nullptr;

    // if (!font.loadFromFile("../assets/Cantarell-ExtraBold.otf"))
    // {
    //     cout<<"font loading error!"<<endl;
    //     return;
    // }

    // this->clockText.setFont(font);
    // this->clockText.setCharacterSize(30);
    // this->clockText.setFillColor(sf::Color::Black);
    // this->clockText.setPosition(Vector2f(200.0,0.0));
}



Game::Game() {
    initVariables();
    // window->setFramerateLimit(60);
}

Game::~Game() {
    // delete window;
    delete map;
}

void Game::update() {
    

		// Clear window
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(shader);

		glm::mat4 model(1.0f);

		// model = glm::translate(model, glm::vec3(triOffset, 0.0f, -2.5f));
		// model = glm::rotate(model, curAngle * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		// model = glm::scale(model, glm::vec3(0.4f, 0.4f, 1.0f));

        velocity += 1;
        velocity2 += 1;

        // model = glm::translate(model, glm::vec3(0.0f, 0.0f, -1.0f)); // move the camera back
        model = glm::rotate(model, glm::radians(45.f), glm::vec3(1.f, 0.f, 0.f)); // rotate the camera around the x-axis
        model = glm::rotate(model, glm::radians(velocity), glm::vec3(0.f, 0.f, 1.f)); // rotate the camera around the x-axis

        // model = glm::rotate(model, glm::radians(velocity), glm::vec3(1.f, 0.f, 0.0f)); // rotate the camera around the y-axis


		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));

        for(size_t i = 0; i < meshList.size(); i++) {
            texture.UseTexture();
		    meshList[i]->RenderMesh();
        }


		glUseProgram(0);

		glfwSwapBuffers(mainWindow);
 

    // if(gameState.getCurrentGameState() == PLAN) {
    //     if(clock.timerSeconds <= 0) {
    //         gameState.evolveState(GAME);
    //         deltaClock = clock.elapsedTime;
    //         this->clockText.setString("Execution");
    //     } else {
    //         this->clockText.setString(to_string(clock.timerSeconds));   
    //     }
    // }

    // if(gameState.getCurrentGameState() == GAME && deltaClock == clock.elapsedTime) {  
    //     deltaClock = clock.elapsedTime + delaySeconds;       
    //     bool hasMovedTroops = map->makeOneStepMovementTroops(); 
    //     if (!hasMovedTroops) {
    //         gameState.evolveState(PLAN);
    //         this->clock.startClock();
    //     }
    // }

    // map->setFogOfWar(&player.army);
    // map->clearShadows();

    // updateMousePositions();
    processPollEvents();

    // clock.update();
}

void Game::render() {
    // window->clear();

    // map->render(window);
    // map->renderShadows(window);
    // map->renderDestinationShadows(window);
    // map->renderPaths(window);

    // if (gameState.getCurrentGameState() == ARMY_SETUP) {
    //     map->renderDeployRegions(window, player.army.deployRegion);
    // }

    // map->renderTree(window);
    // mainHud.renderMainHud(window);
    // map->renderCreatureHud(window);

    // window->draw(clockText);

    // window->display();
}

void Game::processPollEvents() {
    glfwPollEvents();

    if (glfwGetKey(this->mainWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        cout<<"Event for closing the program called"<<endl;
        glfwSetWindowShouldClose(this->mainWindow, 1);
    }

		



    // if(this->selectedTile != nullptr) {
    //     map->castShadowOnTile(mousePosView, selectedTile);
    // }
    
    // while (window->pollEvent(event))
    // {
    //     switch (event.type)
    //     {
    //     case Event::Closed:
    //         cout<<"Event for closing the program called"<<endl;
    //         window->close();
    //         break;
    //     case Event::KeyPressed:
    //         if(event.key.code == Keyboard::Escape) {
    //             cout<<"Event for closing the program called"<<endl;
    //             window->close();
    //         }

    //         if(event.key.code == Keyboard::Enter) {
               
    //         }
    //     case Event::MouseButtonPressed:
    //         if (event.mouseButton.button == sf::Mouse::Right){
    //             Coordinate coordinate = map->clickEvent(mousePosView);
    //             Tile *tile = map->getTile(coordinate);
    //             if(tile->creature != nullptr) {
    //                 tile->creature->creatureHudIsActive = true;
    //                 this->currentCreatureHudActive = tile->creature;
    //             } else if (this->currentCreatureHudActive != nullptr) {
    //                 this->currentCreatureHudActive->creatureHudIsActive = false;
    //                 this->currentCreatureHudActive = nullptr;
    //             }

    //             break;
    //         } 

    //         if (gameState.getCurrentGameState() == ARMY_SETUP){
    //             if(map->deploySoldierToTile(mousePosView, player.armySetup, player.army)) {
    //                 gameState.evolveState(PLAN);
    //                 this->clock.startClock();
    //             }
    //             break;
    //         }


    //         if(gameState.getCurrentGameState() == PLAN) {
    //             if (selectedTile != nullptr) {
    //                 map->setCreatureDestination(mousePosView, selectedTile);
    //                 pathFinding = new PathFinding(map);
    //                 map->setPath(pathFinding->getPath(selectedTile));
    //                 delete pathFinding;

    //                 selectedTile->removeSelectedRender();
    //                 selectedTile = nullptr;
    //                 break;
    //             }

    //             map->selectTileWithCreature(mousePosView, &selectedTile);
    //             break;
    //         }


    //         map->clickEvent(mousePosView);
    //         break;
    //     default:
    //         break;
    //     }
    // }
}

bool Game::running() {
   return !glfwWindowShouldClose(this->mainWindow);
}

void Game::updateMousePositions()
{
    // mousePosWindow = Mouse::getPosition(*window);
    // mousePosView = window->mapPixelToCoords(mousePosWindow);
}

