#include "pch.h"
#include "EnemyNear_Condition.h"
#include "Player.hpp"
#include "GameManager.hpp"
#include <iostream>

EnemyNear_Condition::EnemyNear_Condition()
{
}

bool EnemyNear_Condition::Test(Player* player)
{
	auto players= GameManager::Get()->GetEntities();

	for (int i = 0; i < players.size(); i++)
	{
		if (player->GetTeam() != players[i]->GetTeam())
		{
			if (abs(players[i]->getPosition().x - player->getPosition().x) <=100) //distance inf a 30, donc defenseur a moins de 30pix de l'attaquant
			{
				std::cout << "trop pres\n";
				return true;
			}
		}
	}
	return false;
}



EnemyNear_Condition::~EnemyNear_Condition()
{
}
