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
	
	if (GameManager::Get()->GetBall()->GetAttacker()->GetTeam() == player->GetTeam())
	{
		if(GameManager::Get()->GetBall()->GetAttacker()!=player)
		{
			return true;
		}
		
	}
	return false;
}

Attack_Condition::~Attack_Condition()
{
}
