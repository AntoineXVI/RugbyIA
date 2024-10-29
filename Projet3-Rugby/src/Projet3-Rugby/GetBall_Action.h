#pragma once
#include "Action.hpp"
class Player;

class GetBall_Action : public Action
{
    double mFullTime;
public:
    GetBall_Action();
    void Start(Player* player) override;
    void Update(Player* player) override;
    void End(Player* player) override;
    ~GetBall_Action();
};