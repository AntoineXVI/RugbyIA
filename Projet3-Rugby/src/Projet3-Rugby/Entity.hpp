#pragma once
#include <iostream>
#include <string>
#include <SFML/System/Vector2.hpp>
#include "Context.hpp"

namespace sf 
{
	class Shape;
}

class Entity
{
protected:
    sf::Vector2f mDirection;
    float mSize;
	float mSpeed;

	sf::Shape* mShape;

    Entity();

public:
    virtual void Update();

    ~Entity();
    void setDirection(const sf::Vector2f& direction);
    const sf::Vector2f& getDirection() const;
    void goToPosition(const sf::Vector2f& position);

    void setPosition(const sf::Vector2f& position);
    const sf::Vector2f& getPosition() const;

    const sf::Shape& getShape();
    float GetSize();
    virtual Context::Team GetTeam()=0;
    virtual Context::State GetState()=0;
    virtual std::string GetStateStr() = 0;
};
