#pragma once
#include "Condition.hpp"
class Player;

class Move_Condition : public Condition
{
public:
    Move_Condition();
    bool Test(Player* Player);
    ~Move_Condition();
};