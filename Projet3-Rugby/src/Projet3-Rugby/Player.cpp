#include "pch.h"
#include "Player.hpp"
#include "Behaviour.hpp"

#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>

Player::Player(const sf::Vector2f& position, Behaviour* behaviour, Context::Team team) :
    mState(Context::State::Idle)
{
    mBehaviour = behaviour;
	mSize = 50.f;
	mSpeed = 30.f;
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
}

Player::~Player()
{
}

void Player::Update()
{
	mBehaviour->Update(this);
	Entity::Update();
}

Context::Team Player::GetTeam() const
{
	return mTeam;
}

Context::State Player::getState() const
{
    return mState;
}

void Player::setState(Context::State new_state) 
{
    mState = new_state;
}