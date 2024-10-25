#include "pch.h"
#include "Move_Action.h"
#include "Player.hpp"
#include "Ball.hpp"
#include "GameManager.hpp"
Move_Action::Move_Action(){}

void Move_Action::Start(Player* Player)
{
}

void Move_Action::Update(Player* Player)
{
	//if GetTeam
	//go to pos Ball mais eviter collision 
	//faire surface démarquation

	Player->goToPosition(sf::Vector2f(Player->getPosition().x+10.f, Player->getPosition().y));

}

void Move_Action::End(Player* Player)
{
}

Move_Action::~Move_Action()
{
}
