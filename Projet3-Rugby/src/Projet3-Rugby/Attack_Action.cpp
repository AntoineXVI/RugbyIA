#include "pch.h"
#include "Attack_Action.h"
#include "Player.hpp"
#include "Ball.hpp"
#include "GameManager.hpp"

Attack_Action::Attack_Action()
{
}

void Attack_Action::Start(Player* player)
{
}

void Attack_Action::Update(Player* player)
{
	int dir = mDirection[player->GetTeam()];
	if (GameManager::Get()->GetBall()->GetAttacker() == nullptr) {
		return;
	}
	player->goToPosition(sf::Vector2f(GameManager::Get()->GetBall()->GetAttacker()->getPosition().x-dir,player->getPosition().y));
	if (player->GetTeam() == Context::Team::Blue) {
		if (player->getPosition().x <= GameManager::Get()->GetBall()->GetAttacker()->getPosition().x - dir) {
			player->getShape().setOutlineThickness(2);
			player->getShape().setOutlineColor(sf::Color(250, 150, 100));
		}
		else 
		{
			player->getShape().setOutlineThickness(0);
		}
	}
	if (player->GetTeam() == Context::Team::Red) {
		if (player->getPosition().x >= GameManager::Get()->GetBall()->GetAttacker()->getPosition().x - dir) {
			player->getShape().setOutlineThickness(2);
			player->getShape().setOutlineColor(sf::Color(250, 150, 100));

		}
		else {
			player->getShape().setOutlineThickness(0);
		}
	}
	
	
}

void Attack_Action::End(Player* player)
{
}

Attack_Action::~Attack_Action()
{
}
