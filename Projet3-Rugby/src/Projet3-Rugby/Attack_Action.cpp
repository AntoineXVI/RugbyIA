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
	player->goToPosition(sf::Vector2f(GameManager::Get()->GetBall()->getPosition().x-dir,player->getPosition().y));
}

void Attack_Action::End(Player* player)
{
}

Attack_Action::~Attack_Action()
{
}
