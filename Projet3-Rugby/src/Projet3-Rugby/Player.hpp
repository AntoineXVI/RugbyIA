#pragma once

#include "Entity.hpp"
#include "Context.hpp"

class Behaviour;

class Player : public Entity
{
    Context::State mState;
    Context::Team mTeam;
    Behaviour * mBehaviour;
public:
    Player(const sf::Vector2f& position, Behaviour* behaviour, Context::Team team);
    ~Player();

    void Update() override;

    Context::Team GetTeam() const;

    Context::State getState() const;
    void setState(Context::State);
};
