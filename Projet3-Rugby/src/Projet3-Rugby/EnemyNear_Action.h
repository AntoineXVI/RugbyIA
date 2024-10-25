#pragma once
#include "Action.hpp"
class Player;

class EnemyNear_Action : public Action
{
public:
    EnemyNear_Action();
    void Start(Player* player) override;
    void Update(Player* player) override;
    void End(Player* player) override;
    ~EnemyNear_Action();
};