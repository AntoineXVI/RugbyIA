#pragma once
#include "Action.hpp"
class Player;

class Attack_Action : Action
{
public:
    void Start(Player* Player);
    void Update(Player* Player);
    void End(Player* Player);
};