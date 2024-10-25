#include "pch.h"
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
#include <random>
namespace 
{
static GameManager* mInstance = nullptr;
}

GameManager::GameManager()
{
    Behaviour * behaviour = new Behaviour();

	Transition* moveTransition = new Transition();
	moveTransition->setTargetState(Context::State::Move);
	moveTransition->addCondition(new Move_Condition());

	Action* moveAction = new Move_Action();

	behaviour->AddAction(Context::State::Move, moveAction);
	//behaviour->AddTransition(Context::State::Idle, moveTransition);

	// init behaviour here:
	// example code:
	//  Action * action = new ExampleAction();
	//  behaviour->AddAction(Context::State::ExampleState);
	//  Transition * example_transition = new Transition();
	//  example_transition->setTargetState(Context::State::OtherState);
	//  example_transition->addCondition(new ExampleCondition());
	//  behaviour->AddTransition(Context::State::ExampleState, example_transition);

	Player* p7 = new Player(sf::Vector2f(50, 50), behaviour, Context::Team::Blue);
    Player* p1 = new Player(sf::Vector2f(100, 150), behaviour, Context::Team::Blue);
	
	Player* p3 = new Player(sf::Vector2f(200, 360), behaviour, Context::Team::Blue);

	Player* p5 = new Player(sf::Vector2f(100, 570), behaviour, Context::Team::Blue);
	Player* p8 = new Player(sf::Vector2f(50, 670), behaviour, Context::Team::Blue);
    


	Player* p9 = new Player(sf::Vector2f(1230, 50), behaviour, Context::Team::Red);
	Player* p2 = new Player(sf::Vector2f(1180, 100), behaviour, Context::Team::Red);

	Player* p4 = new Player(sf::Vector2f(1080, 360), behaviour, Context::Team::Red);

	Player* p6 = new Player(sf::Vector2f(1180, 620), behaviour, Context::Team::Red);
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
	std::uniform_int_distribution<> dist(1, mEntities.size()-1);
	int ballchoice = dist(gen);
	std::cout << ballchoice << std::endl;


	Ball* ball = new Ball(sf::Vector2f(mEntities[ballchoice - 1]->getPosition().x, mEntities[ballchoice-1]->getPosition().y));
	mEntities.push_back(ball);

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
}

void GameManager::Draw()
{
	for (Entity* entity : mEntities)
	{
		mWindow->draw(entity->getShape());
	}
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

void GameManager::addEntity(Entity* entity)
{
	mEntities.push_back(entity);
}
