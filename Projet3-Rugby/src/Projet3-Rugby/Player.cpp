#include "pch.h"
#include "Player.hpp"
#include "Behaviour.hpp"
#include "GameManager.hpp"
#include "Context.hpp"
#include "Utils.hpp"
#include "Ball.hpp"
#include <chrono>

#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>

Player::Player(const sf::Vector2f& position, Behaviour* behaviour, Context::Team team) :
    mState(Context::State::Idle)
{
	invicibility = false;
    mBehaviour = behaviour;
	mSize = 50.f;
	mSpeed = 60.f;
	mTeam = team;
    sf::CircleShape* shape = new sf::CircleShape(10);
	shape->setRadius(mSize / 2.f);
	if (mTeam == Context::Team::Blue) {
		shape->setFillColor(sf::Color::Blue);
	}
	if (mTeam == Context::Team::Red) {
		shape->setFillColor(sf::Color::Red);
	}
	shape->setOrigin(mSize / 2.f, mSize / 2.f);
	shape->setPosition(position);

    mShape = shape;

	if (position.y < 360) {
		mPost = Context::Post::Top;
	}
	if (position.y == 360) {
		mPost = Context::Post::Mid;
	}
	if (position.y > 360) {
		mPost = Context::Post::Bot;
	}
}

Player::~Player()
{
}

void Player::Start()
{
	mBehaviour->Start(this);
}

void Player::Update()
{
	if (std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::system_clock::now().time_since_epoch()).count() >= mFullTime)
	{
		invicibility = false;
	}
	if (invicibility) {
		mSpeed = 90.f;
		mShape->setFillColor(sf::Color::Magenta);
	}
	else {
		mSpeed = 60.f;
		if (mTeam == Context::Team::Blue) {
			mShape->setFillColor(sf::Color::Blue);
		}
		if (mTeam == Context::Team::Red) {
			mShape->setFillColor(sf::Color::Red);
		}
	}
	mBehaviour->Update(this);
	Entity::Update();
	Collider();	
}

Context::Team Player::GetTeam() 
{
	return mTeam;
}

Context::Post Player::GetPost()
{
	return mPost;
}

Context::State Player::GetState()
{
    return mState;
}

std::string Player::GetStateStr()
{
	switch (mState) {
	case Context::State::Attack:
		return "Attack";
	case Context::State::Defend:
		return "Defend";
	case Context::State::GetBall:
		return "GetBall";
	case Context::State::EnemyNear:
		return "EnemyNear";
	case Context::State::Idle:
		return "Idle";
	case Context::State::Move:
		return "Move";
	}
	

}

void  Player::Collider()
{
	if (!invicibility) {
		float dt = GameManager::Get()->getDeltaTime();
		sf::Vector2f newPosition;
		auto players = GameManager::Get()->GetEntities();
		for (int i = 0; i < players.size() - 1; i++)
		{
			if (players[i] != this) {
				
					if (Utils::isCollide(this, players[i]))
					{
						if (players[i]->GetState() == Context::State::GetBall || players[i]->GetState() == Context::State::EnemyNear) //si players[i] a la balle
						{
							if (!players[i]->isInvicible()) {
								GameManager::Get()->GetBall()->SetAttacker(this);
							}
						}
						//else if (this->GetState() == Context::State::GetBall) //si this a la balle
						//{
						//	GameManager::Get()->GetBall()->SetAttacker((Player*)players[i]);
						//}

						int DirX;
						int DirY;
						if (players[i]->getPosition().x - this->getPosition().x > 0)
						{
							DirX = 1;
						}
						else
						{
							DirX = -1;
						}
						if (players[i]->getPosition().y - this->getPosition().y > 0)
						{
							DirY = 1;
						}
						else
						{
							DirY = -1;
						}
						newPosition.x -= dt * mSpeed * DirX;
						newPosition.y -= dt * mSpeed * DirY;
					}
				
			}
		}
		mShape->move(newPosition);
	}
}

void Player::setState(Context::State new_state) 
{
    mState = new_state;
}

void Player::Timer()
{
	invicibility = true;
	mFullTime = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::system_clock::now().time_since_epoch() + std::chrono::seconds(1)).count();
}

bool Player::isInvicible()
{
	return invicibility;
}
