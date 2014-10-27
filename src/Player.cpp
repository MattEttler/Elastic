#include "Player.h"
#include <SFML/System/Time.hpp>
#include <string>
#include <iostream>

Player::Player(const char* animUp, const char* animDown, const char* animLeft, const char* animRight) : Mob::Mob(animUp, animDown, animLeft, animRight)
{
    // load texture (spritesheet)
    if (!spriteSheet.loadFromFile("images/Eli.png"))
    {
        std::cout << "Failed to load player spritesheet!" << std::endl;
    }

    // set up the animations for all four directions (set spritesheet and push frames)
    walkingAnimationDown.setSpriteSheet(spriteSheet);
    walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(64, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect( 0, 0, 32, 32));

    walkingAnimationLeft.setSpriteSheet(spriteSheet);
    walkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
    walkingAnimationLeft.addFrame(sf::IntRect(64, 32, 32, 32));
    walkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
    walkingAnimationLeft.addFrame(sf::IntRect( 0, 32, 32, 32));

    walkingAnimationRight.setSpriteSheet(spriteSheet);
    walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect(64, 64, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect( 0, 64, 32, 32));

    walkingAnimationUp.setSpriteSheet(spriteSheet);
    walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect(64, 96, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect( 0, 96, 32, 32));

    currentAnimation = &walkingAnimationDown;

    // set up AnimatedSprite
    animatedSprite = AnimatedSprite(sf::seconds(0.2), true, false);
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

void Player::MoveX(float x)
{
    if(x > 0)
    {
        currentAnimation = &walkingAnimationRight;
    }
    else
    {
        currentAnimation = &walkingAnimationLeft;
    }
    Mob::MoveX(x);
}

void Player::MoveY(float y)
{
    if(y > 0)
    {
        currentAnimation = &walkingAnimationDown;
    }
    else
    {
        currentAnimation = &walkingAnimationUp;
    }
    Mob::MoveY(y);
}

void Player::Draw(int xOffset, int yOffset, sf::RenderWindow* rw, sf::Time& frameTime)
{
    animatedSprite.setPosition(xOffset, yOffset);
    animatedSprite.play(*currentAnimation);
    animatedSprite.update(frameTime);
    rw->draw(animatedSprite);
}
