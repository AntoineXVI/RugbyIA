#include "pch.h"
#include "GetBall_Action.h"
#include "Player.hpp"
#include "Ball.hpp"
#include "GameManager.hpp"

GetBall_Action::GetBall_Action()
{

}

void GetBall_Action::Start(Player* player)
{
}

void GetBall_Action::Update(Player* player)
{
	if(player->GetTeam() == Context::Team::Blue)
	{
		player->goToPosition(sf::Vector2f(player->getPosition().x + 10.f, player->getPosition().y));
	}
	if (player->GetTeam() == Context::Team::Red) {
		player->goToPosition(sf::Vector2f(player->getPosition().x - 10.f, player->getPosition().y));
	}

}

void GetBall_Action::End(Player* player)
{
}

GetBall_Action::~GetBall_Action()
{
}
