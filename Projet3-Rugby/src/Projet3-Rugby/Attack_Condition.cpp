#include "pch.h"
#include "Attack_Condition.h"
#include "Player.hpp"
#include "Ball.hpp"
#include "GameManager.hpp"

Attack_Condition::Attack_Condition()
{
}

bool Attack_Condition::Test(Player* player)
{
	Player* attack = GameManager::Get()->GetBall()->GetAttacker();
	if (attack == nullptr) {
		return false;
	}
	if (attack->GetTeam() == player->GetTeam())
	{
		if(attack !=player)
		{
			return true;
		}
		
	}
	return false;
}

Attack_Condition::~Attack_Condition()
{
}
