#pragma once
#include "Condition.hpp"
class Player;

class GetBall_Condition : public Condition
{
public:
    GetBall_Condition();
    bool Test(Player* player) override;
    ~GetBall_Condition();
};