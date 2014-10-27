#include "Tile.h"
#include "SFML/Graphics.hpp"

Tile::Tile(sf::Texture& texture, bool isSolid, bool isLightEmmiter)
{
    baseSprite.setTexture(texture);
    this->isSolid = isSolid;
    this->isLightEmmiter = isLightEmmiter;
}

Tile::~Tile()
{
}

void Tile::Draw(int x, int y, sf::RenderWindow* rw, float scale)
{
    baseSprite.setPosition(x, y);
    baseSprite.setScale(scale, scale);
    rw->draw(baseSprite);
}

