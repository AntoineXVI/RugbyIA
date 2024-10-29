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
	sf::Vector2f ballPos = GameManager::Get()->GetBall()->getPosition();


	if (player->GetPost() == Context::Post::Top) {

		if (ballPos.y > 360)//moitié du terrain
		{
			player->goToPosition(sf::Vector2f(ballPos.x,360));
			return;
		}
	}

	if (player->GetPost() == Context::Post::Mid) {
		if (ballPos.y < 720/4)//1er quart du terrain
		{
			player->goToPosition(sf::Vector2f(ballPos.x, 720 / 4));
			return;
		}
		if (ballPos.y > 3*(720 / 4))//4e quart du terrain
		{
			player->goToPosition(sf::Vector2f(ballPos.x, 3*(720 / 4)));
			return;
		}
	}

	if (player->GetPost() == Context::Post::Bot) {
		if (ballPos.y < 360)//moitié du terrain
		{
			player->goToPosition(sf::Vector2f(ballPos.x, 360));
			return;
		}
	}

	player->goToPosition(ballPos);

	//pour eviter l'aglutination (ça pue)
	//auto team = GameManager::Get()->GetEntities();
	//for (int i = 0; i < team.size(); i++) {
	//	if (team[i]->GetTeam() == player->GetTeam()) {
	//		if (team[i]->getPosition().x - player->getPosition().x < 50) {
	//			player->goToPosition(sf::Vector2f(team[i]->getPosition().x - 50, GameManager::Get()->GetBall()->getPosition().y));
	//		}
	//	}
	//}


}

void Defend_Action::End(Player* player)
{
}

Defend_Action::~Defend_Action()
{
}
