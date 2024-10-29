#include "pch.h"
#include "Defend_Condition.h"
#include "Player.hpp"
#include "Ball.hpp"
#include "GameManager.hpp"

Defend_Condition::Defend_Condition()
{
}

bool Defend_Condition::Test(Player* player)
{
	Player* attack = GameManager::Get()->GetBall()->GetAttacker();
	if (attack == nullptr) {
		return false;
	}

	if(attack->GetTeam() != player->GetTeam())
	{
		return true;
	}
	return false;
}

Defend_Condition::~Defend_Condition()
{
}
