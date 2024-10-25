#include "pch.h"
#include "Defend_Action.h"
#include "Player.hpp"
#include "Ball.hpp"
#include "GameManager.hpp"

Defend_Action::Defend_Action()
{
}

void Defend_Action::Start(Player* player)
{
}

void Defend_Action::Update(Player* player)
{
	player->goToPosition(GameManager::Get()->GetBall()->getPosition());

}

void Defend_Action::End(Player* player)
{
}

Defend_Action::~Defend_Action()
{
}
