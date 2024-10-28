#include "pch.h"
#include "EnemyNear_Action.h"
#include "Player.hpp"
#include "Ball.hpp"
#include "GameManager.hpp"
#include <random>
#include "Context.hpp"

EnemyNear_Action::EnemyNear_Action()
{

}

void EnemyNear_Action::Start(Player* player)
{
}

void EnemyNear_Action::Update(Player* player)
{
	//player->goToPosition(sf::Vector2f(player->getPosition().x+10, player->getPosition().y+10));
	//faire une passe
	bool pass = false;
	while (!pass)
	{
		std::vector<Entity*> team;
		std::vector<Entity*> entities = GameManager::Get()->GetEntities();
		for (int i = 0; i < entities.size(); i++) {
			if (player->GetTeam() == Context::Team::Blue) {
				if (entities[i]->getPosition().x <= (player->getPosition().x - 150))
				{
					team.push_back(entities[i]);
				}
			}
			if (player->GetTeam() == Context::Team::Red) {
				if (entities[i]->getPosition().x >= (player->getPosition().x + 150))
				{
					team.push_back(entities[i]);
				}
			}

		}
		if (team.empty()) {
			return;
		}
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dist(0, team.size()-1);
		int ballchoice = dist(gen);

		if (team[ballchoice]->GetTeam() == player->GetTeam())
		{
			//GameManager::Get()->GetBall()->SetAttacker((Player*)team[0]);
			GameManager::Get()->GetBall()->SetSpeed(120);
			GameManager::Get()->GetBall()->goToPosition(team[0]->getPosition());
			team[0]->setDirection(sf::Vector2f{0.f, 0.f});
			GameManager::Get()->GetBall()->SetAttacker(nullptr);
			//GameManager::Get()->GetBall()->goToPosition(GameManager::Get()->GetEntities()[ballchoice]->getPosition());
			pass = true;
		}
		
	}
	
}

void EnemyNear_Action::End(Player* player)
{
}

EnemyNear_Action::~EnemyNear_Action()
{
}
