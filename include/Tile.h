#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

class Tile{
private:
sf::Sprite baseSprite;

public:
Tile(sf::Texture& texture, bool isSolid, bool isLightEmmiter);
~Tile();
void Draw(int x, int y, sf::RenderWindow* rw, float scale);

bool isSolid;
bool isLightEmmiter;

};
#endif
