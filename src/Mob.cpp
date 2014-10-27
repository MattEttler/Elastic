#include "Mob.h"
#include <string>

Mob::Mob(const char* animUp, const char* animDown, const char* animLeft, const char* animRight)
{
    this->animUpte.loadFromFile(animUp);
    this->animDownte.loadFromFile(animDown);
    this->animLeftte.loadFromFile(animLeft);
    this->animRightte.loadFromFile(animRight);
    baseSprite.setTexture(this->animUpte);
    x = 0;
    y = 0;
    name = "Mob";
    speed = 2;
}

Mob::~Mob()
{
}

void Mob::Draw(int xOffset, int yOffset, sf::RenderWindow* rw, float scale)
{
    baseSprite.setPosition(xOffset, yOffset);
    baseSprite.setScale(scale, scale);
    rw->draw(baseSprite);
}

void Mob::GoTo(int nx, int ny)
{
    x = nx;
    y = ny;
}

void Mob::MoveX(float nx)
{
    x += nx;
}

void Mob::MoveY(float ny)
{
    y += ny;
}
