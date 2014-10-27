#ifndef PLAYER_H
#define PLAYER_H

#include "Mob.h"
#include <string>

class Player: public Mob
{
    public:
        Player(const char* animUp, const char* animDown, const char* animLeft, const char* animRight);
        virtual ~Player();
        void ProcessInput();
    protected:
    private:
};

#endif // PLAYER_H
