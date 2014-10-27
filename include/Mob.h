#ifndef MOB_H
#define MOB_H

#include <string>
#include <SFML/Graphics.hpp>

class Mob
{
    public:
        Mob(const char* animUp, const char* animDown, const char* animLeft, const char* animRight);
        virtual ~Mob();
        void Draw(int x, int y, sf::RenderWindow* rw, float scale);
        void GoTo(int x, int y);
        void MoveX(float x);
        void MoveY(float y);
        float speed;
        float x;
        float y;
    protected:
    private:
        char* name;
        sf::Texture animDownte;
        sf::Texture animUpte;
        sf::Texture animLeftte;
        sf::Texture animRightte;
        sf::Sprite baseSprite;

};

#endif // MOB_H
