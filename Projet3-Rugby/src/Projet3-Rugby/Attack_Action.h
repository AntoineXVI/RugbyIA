#pragma once
#include "Action.hpp"
#include "Context.hpp"
#include <map>
class Player;

class Attack_Action : public Action
{
    std::map<Context::Team, int> mDirection{ {Context::Team::Blue,150},{Context::Team::Red,-150} };

public:
    Attack_Action();
    void Start(Player* player);
    void Update(Player* player);
    void End(Player* player);
    ~Attack_Action();
};