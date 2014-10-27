#include "Engine.h"
#include "Camera.h"
#include <SFML\Graphics.hpp>
#include <iostream>

Engine::Engine()
{

}

Engine::~Engine()
{
	delete window;
	//this is so that the 'window = new sf::RenderWindow' is removed from memory when the engine stops)
	delete texturemanager;
	//this is so that the texturemanager is also deleted once the engine is stopped
	delete camera;
	delete currentLevel;
}

bool Engine::Init()
{
	texturemanager = new TextureManager();
	window = new sf::RenderWindow(sf::VideoMode(800, 600, 32), "RPG");
	window->setFramerateLimit(60);
	camera = new Camera();
	camera->w = 800;
	camera->h = 600;
	circle.setRadius(4);
	circle.setFillColor(sf::Color::Blue);
    circle.setOutlineColor(sf::Color::Magenta);
    circle.setOutlineThickness(5);

	tileScale = 3;

	if(!window)
		return false;

	LoadTextures();
	LoadLevel();

	return true;
}

void Engine::LoadLevel()
{
	//Temporary level for testing
	currentLevel = new Level(50, 50);

	unsigned int tile;
	Tile* grassTile = new Tile(texturemanager->GetTexture(0), false, false);
    Engine::tileTypes.push_back(grassTile);
	Tile* DirtTile = new Tile(texturemanager->GetTexture(1), false, false);
	Engine::tileTypes.push_back(DirtTile);
	Tile* ClayTile = new Tile(texturemanager->GetTexture(2), true, false);
	Engine::tileTypes.push_back(ClayTile);
	std::cout << Engine::tileTypes.size();

	for(int y = 0; y < currentLevel->GetHeight(); y++)
	{
		for(int x = 0; x < currentLevel->GetWidth(); x++)
		{
			if(y % 3 == 0 || x % 3 == 0)
				tile = 0;
			else
				tile = 2;

			currentLevel->AddTile(x, y, tile);
		}
	}
}

void Engine::LoadTextures()
{

	sf::Texture texture;
	texture.loadFromFile("images/GrassTile.png");

	texturemanager->AddTexture(texture);

	texture.loadFromFile("images/GrassCap.png");

	texturemanager->AddTexture(texture);

    texture.loadFromFile("images/ClayTile.png");

	texturemanager->AddTexture(texture);

	player = new Player("images/Jacob/Jacob_DownWalk.png","images/Jacob.png","images/Jacob.png","images/Jacob.png");
}

void Engine::RenderFrame()
{
	Tile* tile = Engine::tileTypes[0];

	window->clear();

	//Loop through and draw each tile
	//We're keeping track of two variables in each loop. How many tiles
	//we've drawn (x and y), and which tile on the map we're drawing (tileX
	//and tileY)
	tileSize = 16;
	for(int y = 0; y < currentLevel->GetHeight(); y++)
	{
		for(int x = 0; x < currentLevel->GetWidth(); x++)
		{
			//Get the tile we're drawing
			//tile = Engine::tileTypes[currentLevel->GetTile(x, y)];

            tile->Draw(((x * tileSize) * tileScale) - camera->x, ((y * tileSize) * tileScale) - camera->y, window, tileScale);
		}
	}

    player->Draw(player->x - camera->x, player->y - camera->y, window, tileScale/2);

    //Flips the display
	window->display();
}

void Engine::ProcessInput()
{
	sf::Event evt;
    player->ProcessInput();

	//Loop through all window events
	while(window->pollEvent(evt))
	{
		if(evt.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window->close();
	}
}

void Engine::Update()
{
    if(player->x < (camera->w/4 + camera->x) && camera->x > 0)
    {
        camera->x-=player->speed;
    }
    if(player->x > (camera->w + camera->x) - (camera->w/4) && (camera->x + camera->w) < (currentLevel->GetWidth()*tileSize) * tileScale)
    {
        camera->x+=player->speed;
    }
    if(player->y < (camera->h/4 + camera->y) && camera->y > 0)
    {
        camera->y-=player->speed;
    }
    if(player->y > (camera->h + camera->y) - (camera->h/4) && (camera->y + camera->h) < (currentLevel->GetHeight()*tileSize) * tileScale)
    {
        camera->y+=player->speed;
    }

    camera->WalkWithPlayer(player->x, player->y);
}

void Engine::MainLoop()
{
	//Loop until our window is closed
	while(window->isOpen())
	{
		ProcessInput();
		Update();
		RenderFrame();
	}
}

void Engine::Go()
{
	if(!Init())
		throw "Could not initialize Engine";
	MainLoop();
}

