#include "pch.h"
#include "Ball.hpp"
#include "Player.hpp"

Ball::Ball(const sf::Vector2f& position, Player* player)
{
    sf::CircleShape* shape = new sf::CircleShape();
    mAttacker = player;
    mSpeed = 30.f;
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

Ball::~Ball()
{
}

void Ball::Update()
{
    
    goToPosition(mAttacker->getPosition());
    Entity::Update();
}
