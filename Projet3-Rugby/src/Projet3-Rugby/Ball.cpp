#include "pch.h"
#include "Ball.hpp"
#include "Player.hpp"

Ball::Ball(const sf::Vector2f& position, Player* player)
{
    sf::CircleShape* shape = new sf::CircleShape();
    mAttacker = player;
    mSpeed = 60.f;
    mSize = 30.f;
    shape->setRadius(mSize / 2.f);
    shape->setFillColor(sf::Color::Yellow);
    shape->setOrigin(mSize / 2.f, mSize / 2.f);
    shape->setPosition(position);
    mShape = shape;
}

Player* Ball::GetAttacker()
{
    return mAttacker;
}

void Ball::SetSpeed(float speed)
{
    mSpeed = speed;
}

void Ball::SetAttacker(Player* player)
{
    mAttacker = player;
}

Ball::~Ball()
{
}

void Ball::Start()
{
}

void Ball::Update()
{
    if (!mAttacker)
    {
        Entity::Update();
        return;
    }
    else
    {
        mSpeed = 0;
        mDirection = sf::Vector2f(0,0);
    }

    setPosition(mAttacker->getPosition());
}

Context::Team Ball::GetTeam()
{
    return Context::Team();
}

Context::State Ball::GetState()
{
    return Context::State();
}

std::string Ball::GetStateStr()
{
    return std::string();
}

bool Ball::isInvicible()
{
    return false;
}
