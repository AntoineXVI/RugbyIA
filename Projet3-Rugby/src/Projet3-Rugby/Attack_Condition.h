#pragma once
#include "Condition.hpp"
class Player;

class Attack_Condition : public Condition
{

    //map
public:
    Attack_Condition();
    bool Test(Player* player) override;
    ~Attack_Condition();
};