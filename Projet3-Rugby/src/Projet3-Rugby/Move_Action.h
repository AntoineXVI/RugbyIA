#pragma once
#include "Action.hpp"
class Player;

class Move_Action : public Action
{
public:
    Move_Action();
    void Start(Player* Player);
    void Update(Player* Player);
    void End(Player* Player);
    ~Move_Action();
};