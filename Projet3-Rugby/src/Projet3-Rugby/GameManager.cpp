#include "pch.h"
#include <SFML/Graphics.hpp>
#include "Utils.hpp"
#include "GameManager.hpp"

#include "Behaviour.hpp"

#include "Player.hpp"
#include "Ball.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <iostream>
#include "Transition.hpp"
#include "Move_Condition.h"
#include "Move_Action.h"
#include "GetBall_Condition.h"
#include "GetBall_Action.h"

#include "EnemyNear_Condition.h"
#include "EnemyNear_Action.h"

#include "Defend_Condition.h"
#include "Defend_Action.h"

#include "Attack_Condition.h"
#include "Attack_Action.h"

#include <random>
namespace 
{
static GameManager* mInstance = nullptr;
}

GameManager::GameManager()
{
	// init behaviour here:
	// example code:
	//  Action * action = new ExampleAction();
	//  behaviour->AddAction(Context::State::ExampleState);
	//  Transition * example_transition = new Transition();
	//  example_transition->setTargetState(Context::State::OtherState);
	//  example_transition->addCondition(new ExampleCondition());
	//  behaviour->AddTransition(Context::State::ExampleState, example_transition);

    Behaviour * behaviour = new Behaviour();

	// GetBallAction

	//player with the ball

	Transition* ballTransition = new Transition();
	ballTransition->setTargetState(Context::State::GetBall);
	ballTransition->addCondition(new GetBall_Condition());

	Action* ballAction = new GetBall_Action();

	behaviour->AddAction(Context::State::GetBall, ballAction);
	behaviour->AddTransition(Context::State::Idle, ballTransition);
	behaviour->AddTransition(Context::State::EnemyNear, ballTransition); 
	behaviour->AddTransition(Context::State::Defend, ballTransition);
	behaviour->AddTransition(Context::State::Attack, ballTransition);


	// EnemyNearAction

	Transition* EnemyNearTransition = new Transition();
	EnemyNearTransition->setTargetState(Context::State::EnemyNear);
	EnemyNearTransition->addCondition(new EnemyNear_Condition()); 

	Action* EnemyNearAction = new EnemyNear_Action();

	behaviour->AddAction(Context::State::EnemyNear, EnemyNearAction);
	behaviour->AddTransition(Context::State::GetBall, EnemyNearTransition);


	//defenders

	Transition* defendTransition = new Transition();
	defendTransition->setTargetState(Context::State::Defend);
	defendTransition->addCondition(new Defend_Condition());

	Action* defendAction = new Defend_Action();

	behaviour->AddAction(Context::State::Defend, defendAction);
	behaviour->AddTransition(Context::State::Idle, defendTransition);//peut etre plus
	behaviour->AddTransition(Context::State::EnemyNear, defendTransition);
	behaviour->AddTransition(Context::State::GetBall, defendTransition);
	behaviour->AddTransition(Context::State::Attack, defendTransition);


	// attacker
	Transition* attackTransition = new Transition();
	attackTransition->setTargetState(Context::State::Attack);
	attackTransition->addCondition(new Attack_Condition());

	Action* attackAction = new Attack_Action();

	behaviour->AddAction(Context::State::Attack, attackAction);
	behaviour->AddTransition(Context::State::Idle, attackTransition);//peut etre plus
	behaviour->AddTransition(Context::State::EnemyNear, attackTransition);
	behaviour->AddTransition(Context::State::GetBall, attackTransition);
	behaviour->AddTransition(Context::State::Defend, attackTransition);

	// init behaviour here:
	// example code:
	//  Action * action = new ExampleAction();
	//  behaviour->AddAction(Context::State::ExampleState);
	//  Transition * example_transition = new Transition();
	//  example_transition->setTargetState(Context::State::OtherState);
	//  example_transition->addCondition(new ExampleCondition());
	//  behaviour->AddTransition(Context::State::ExampleState, example_transition);

	Player* p1 = new Player(sf::Vector2f(50, 50), behaviour, Context::Team::Blue);
	auto result = p1->getShape().getFillColor();
    Player* p2 = new Player(sf::Vector2f(100, 150), behaviour, Context::Team::Blue);
	auto result2 = p2->getShape().getFillColor();
	 
	Player* p3 = new Player(sf::Vector2f(200, 360), behaviour, Context::Team::Blue);

	Player* p4 = new Player(sf::Vector2f(100, 570), behaviour, Context::Team::Blue);
	Player* p5 = new Player(sf::Vector2f(50, 670), behaviour, Context::Team::Blue);
    

	Player* p6 = new Player(sf::Vector2f(1230, 50), behaviour, Context::Team::Red);
	Player* p7 = new Player(sf::Vector2f(1180, 150), behaviour, Context::Team::Red);

	Player* p8 = new Player(sf::Vector2f(1080, 360), behaviour, Context::Team::Red);

	Player* p9 = new Player(sf::Vector2f(1180, 570), behaviour, Context::Team::Red);
	Player* p10 = new Player(sf::Vector2f(1230, 670), behaviour, Context::Team::Red);

	mEntities.push_back(p1);
    mEntities.push_back(p2);
	mEntities.push_back(p3);
	mEntities.push_back(p4);
	mEntities.push_back(p5);
	mEntities.push_back(p6);
	mEntities.push_back(p7);
	mEntities.push_back(p8);
	mEntities.push_back(p9);
	mEntities.push_back(p10);

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, mEntities.size()-1);
	int ballchoice = dist(gen);
	std::cout << ballchoice << std::endl;

	mBall = new Ball(sf::Vector2f(mEntities[ballchoice]->getPosition().x, mEntities[ballchoice]->getPosition().y), (Player*)mEntities[ballchoice]);
}

GameManager::~GameManager()
{
	for (int i = 0; i < mEntities.size(); i++)
	{
		delete mEntities[i];
	}
}

GameManager* GameManager::Instantiate()
{
	if (!mInstance)
    {
        mInstance = new GameManager();
        return mInstance;
    }
    return nullptr;
}

GameManager* GameManager::Get()
{
	return mInstance;
}

void GameManager::setWindow(sf::RenderWindow* window)
{
	mWindow = window;
}

void GameManager::Update()
{
	for (Entity* entity : mEntities)
	{
		entity->Update();
	}
	mBall->Update();

	for (int i = 0; i < mEntities.size(); i++)
	{
		//collision Joueur X Balle
		if (Utils::isCollideCircle(mEntities[i], mBall) && mEntities[i]->GetState() != Context::State::GetBall && mEntities[i]->GetState() != Context::State::Idle && mEntities[i]->GetState() != Context::State::EnemyNear && !mEntities[i]->isInvicible())
		{
			mBall->SetAttacker((Player*)mEntities[i]);
			mBall->setPosition(mEntities[i]->getPosition());
		}
	}
	Win();
}

void GameManager::Draw()
{
	if (!font.loadFromFile("../../../src/Projet3-Rugby/Hack-Regular.ttf"))
	{
		std::cout << "error font\n";
		return;
	}
	for (Entity* entity : mEntities)
	{		
		mWindow->draw(entity->getShape());

		sf::Text text(entity->GetStateStr(), font);
		text.setCharacterSize(30);
		text.setPosition(entity->getPosition());
		mWindow->draw(text);
	}
	mWindow->draw(mBall->getShape());

	sf::Text textB(std::to_string(ScoreB), font);
	textB.setCharacterSize(30);
	textB.setPosition(50,50);
	mWindow->draw(textB);
	sf::Text textR(std::to_string(ScoreR), font);
	textR.setCharacterSize(30);
	textR.setPosition(1230, 50);
	mWindow->draw(textR);
}

void GameManager::setDeltaTime(float deltaTime)
{
	mDeltaTime = deltaTime;
}

float GameManager::getDeltaTime() const
{
	return mDeltaTime;
}

std::vector<Entity*> GameManager::GetEntities()
{
	return mEntities;
}

Ball* GameManager::GetBall()
{
	return mBall;
}

void GameManager::Win()
{
	auto attacker = mBall->GetAttacker();
	if (!attacker) {
		return;
	}
	if (attacker->GetTeam() == Context::Team::Blue) {
		if (attacker->getPosition().x > 1280 - 1280 / 10) {
			ScoreB++;
			Restart(Context::Team::Blue);
		}
	}
	if (attacker->GetTeam() == Context::Team::Red) {
		if (attacker->getPosition().x < 1280 / 10) {
			ScoreR++;
			Restart(Context::Team::Red);
		}
	}

}

void GameManager::Restart(Context::Team winner)
{
	int yBlue = 360;
	int xBlue = 200;
	mEntities[0]->setPosition(sf::Vector2f(50, 50));
	mEntities[1]->setPosition(sf::Vector2f(100, 150));
	mEntities[2]->setPosition(sf::Vector2f(200, 360));
	mEntities[3]->setPosition(sf::Vector2f(100, 570));
	mEntities[4]->setPosition(sf::Vector2f(50, 670));

	mEntities[5]->setPosition(sf::Vector2f(1230, 50));
	mEntities[6]->setPosition(sf::Vector2f(1180, 150));
	mEntities[7]->setPosition(sf::Vector2f(1080, 360));
	mEntities[8]->setPosition(sf::Vector2f(1180, 570));
	mEntities[9]->setPosition(sf::Vector2f(1230, 670));


	bool ballchange = false;
	while(!ballchange)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dist(0, mEntities.size() - 1);
		int ballchoice = dist(gen);
		std::cout << ballchoice << std::endl;
		if (mEntities[ballchoice]->GetTeam() != winner) {
			mBall->SetAttacker((Player*)mEntities[ballchoice]);
			ballchange = true;
		}
	}
}

void GameManager::addEntity(Entity* entity)
{
	mEntities.push_back(entity);
}
