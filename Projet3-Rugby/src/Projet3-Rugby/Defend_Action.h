#pragma once
#include "Action.hpp"
class Player;

class Defend_Action : public Action
{
public:
    Defend_Action();
    void Start(Player* player) override;
    void Update(Player* player) override;
    void End(Player* player) override;
    ~Defend_Action();
};