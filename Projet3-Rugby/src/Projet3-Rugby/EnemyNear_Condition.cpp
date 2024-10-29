#include "pch.h"
#include "EnemyNear_Condition.h"
#include "Player.hpp"
#include "GameManager.hpp"
#include <iostream>
#include "Context.hpp"

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
			if (abs(players[i]->getPosition().x - player->getPosition().x) <=100 && abs(players[i]->getPosition().y - player->getPosition().y) <= 100) //distance inf a 30, donc defenseur a moins de 30pix de l'attaquant
			{
				if(player->GetTeam()==Context::Team::Blue && players[i]->getPosition().x> player->getPosition().x)
				{
					//std::cout << "trop pres\n";
					return true;
				}
				if (player->GetTeam() == Context::Team::Red && players[i]->getPosition().x < player->getPosition().x)
				{
					//std::cout << "trop pres\n";
					return true;
				}
			}
		}
	}
	return false;
}



EnemyNear_Condition::~EnemyNear_Condition()
{
}
