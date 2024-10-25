#pragma once
#include "Condition.hpp"
class Player;

class Defend_Condition : public Condition
{
public:
    Defend_Condition() ;
    bool Test(Player* player)override;
    ~Defend_Condition();
};