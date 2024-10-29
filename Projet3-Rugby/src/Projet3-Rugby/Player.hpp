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

    double mFullTime;
    bool invicibility;
public:
    Player(const sf::Vector2f& position, Behaviour* behaviour, Context::Team team);
    ~Player();

    void Start() override;
    void Update() override;

    Context::Team GetTeam() override;

    Context::Post GetPost();

    Context::State GetState() override;
    std::string GetStateStr() override;
    void Collider();
    void setState(Context::State);
    void Timer();
    bool isInvicible() override;
};
