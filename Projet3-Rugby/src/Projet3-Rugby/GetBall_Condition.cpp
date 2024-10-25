#include "pch.h"
#include "GetBall_Condition.h"
#include "Ball.hpp"
#include "GameManager.hpp"

GetBall_Condition::GetBall_Condition()
{
}

bool GetBall_Condition::Test(Player* player)
{
	if (GameManager::Get()->GetBall()->GetAttacker() == player) {
		return true;
	}
	
}



GetBall_Condition::~GetBall_Condition()
{
}
