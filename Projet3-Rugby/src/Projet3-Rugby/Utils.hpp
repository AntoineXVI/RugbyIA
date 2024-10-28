#pragma once
#include "Entity.hpp"
#include <SFML/System/Vector2.hpp>

namespace Utils
{
	sf::Vector2f Vector2Normalize(const sf::Vector2f& vector);
	float GetDeltaTime();
	bool isCollide(Entity* objI, Entity* objII);
}