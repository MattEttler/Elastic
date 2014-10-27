#include <vector>
#include <iostream>
#include "Level.h"
#include "Tile.h"

Level::Level(int w, int h)
{
	SetDimensions(w, h);
	this->w = w;
	this->h = h;
}

Level::~Level()
{

}

int Level::GetHeight()
{
	return h;
}

int Level::GetWidth()
{
	return w;
}

void Level::SetDimensions(int w, int h)
{
	//w rows
	map.resize(w);

	//Each row has h columns of null Tile pointers
	for(int i = 0; i < w; i++)
	{
		map.at(i).resize(h, 0);
	}
}

void Level::AddTile(int x, int y, unsigned int tileType)
{
	map[x][y] = tileType;
}

unsigned int Level::GetTile(int x, int y)
{
	return map[x][y];
}

void Level::LoadLevel()
{
	//Eventually we'll write code to load level data from a
	//file, but for now we'll just make it all up.
}

