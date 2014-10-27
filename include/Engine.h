#ifndef _ENGINE_H
#define _ENGINE_H

#include <SFML\Graphics.hpp>

#include "TextureManager.h"
#include "Tile.h"
#include "Level.h"
#include "Camera.h"
#include "Player.h"

class Engine
{
private:
	//SFML Render Window
	sf::RenderWindow* window;
    sf::Clock frameClock;
	TextureManager* texturemanager;
	Player* player;
	sf::CircleShape circle;
	float tileScale;
    vector<Tile*> tileTypes;

	//Initializes the engine
	bool Init();
	//Main Game Loop
	void MainLoop();
	//Renders one frame
	void RenderFrame();
	//Processes user input
	void ProcessInput();
	//Updates all Engine internals
	void Update();

	//Temporary
    void LoadLevel();
	void LoadTextures();
	Tile* testTile;
	Level* currentLevel;
	Camera* camera;
	int tileSize;
	bool mouseDown;

public:

	Engine();
	~Engine();
	void Go();					//Starts the engine
};

#endif

