#pragma once
#include "Condition.hpp"
class Player;

class EnemyNear_Condition : public Condition
{
public:
    EnemyNear_Condition();
    bool Test(Player* player) override;
    ~EnemyNear_Condition();
};