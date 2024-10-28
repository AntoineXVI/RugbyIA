#pragma once

#include "Entity.hpp"
#include "Context.hpp"

class Behaviour;

class Player : public Entity
{
    Context::State mState;
    Context::Post mPost;
    Context::Team mTeam;
    Behaviour * mBehaviour;
public:
    Player(const sf::Vector2f& position, Behaviour* behaviour, Context::Team team);
    ~Player();

    void Update() override;

    Context::Team GetTeam() override;

    Context::Post GetPost();

    Context::State GetState() override;
    void Collider();
    void setState(Context::State);
    bool collidePlayer();
};
