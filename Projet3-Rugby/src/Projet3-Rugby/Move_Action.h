#pragma once
#include "Action.hpp"
class Player;

class Move_Action : public Action
{
public:
    Move_Action();
    void Start(Player* player) override;
    void Update(Player* player) override;
    void End(Player* player) override;
    ~Move_Action();
};