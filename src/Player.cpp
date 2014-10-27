#include "Player.h"
#include <string>

Player::Player(const char* animUp, const char* animDown, const char* animLeft, const char* animRight) : Mob::Mob(animUp, animDown, animLeft, animRight)
{
}

Player::~Player()
{
    //dtor
}

void Player::ProcessInput()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->MoveX(-this->speed);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->MoveX(this->speed);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->MoveY(this->speed);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->MoveY(-this->speed);
}
