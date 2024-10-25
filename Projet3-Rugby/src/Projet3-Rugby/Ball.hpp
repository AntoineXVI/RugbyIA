#pragma once

#include "Entity.hpp"
#include <SFML/Graphics/CircleShape.hpp>

class Player;

class Ball : public Entity
{
    Player* mAttacker;
public:
    Ball(const sf::Vector2f& position, Player* player);
    //faire la passe qui change player et augment sa vitesse jusqu'� collision player devient mattacker
    Player* GetAttacker();
    ~Ball();

    void Update() override;
};
