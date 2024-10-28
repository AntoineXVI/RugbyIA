#pragma once

#include "Entity.hpp"
#include <SFML/Graphics/CircleShape.hpp>

class Player;

class Ball : public Entity
{
    Player* mAttacker;
public:
    Ball(const sf::Vector2f& position, Player* player);
    //faire la passe qui change player et augment sa vitesse jusqu'à collision player devient mattacker
    Player* GetAttacker();
    void SetSpeed(float speed);
    void SetAttacker(Player* player);
    ~Ball();

    void Update() override;
    Context::Team GetTeam() override;
    Context::State GetState() override;
};
