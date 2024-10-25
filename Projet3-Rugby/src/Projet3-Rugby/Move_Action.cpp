#include "pch.h"
#include "Move_Action.h"
#include "Player.hpp"
#include "Ball.hpp"
#include "GameManager.hpp"
Move_Action::Move_Action(){}

void Move_Action::Start(Player* player)
{
}

void Move_Action::Update(Player* player)
{
	//if GetTeam
	//go to pos Ball mais eviter collision 
	//faire surface démarquation

	player->goToPosition(sf::Vector2f(player->getPosition().x+10.f, player->getPosition().y));

}

void Move_Action::End(Player* player)
{
}

Move_Action::~Move_Action()
{
}
