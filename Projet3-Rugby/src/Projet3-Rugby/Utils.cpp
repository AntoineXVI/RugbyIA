#include "pch.h"
#include "Utils.hpp"
#include <vector>

#include <cmath>

namespace Utils 
{

    sf::Vector2f Vector2Normalize(const sf::Vector2f& vector)
    {
        float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);

        if (magnitude == 0) {
            return { 0, 0 };
        }

        sf::Vector2f normalized = { vector.x / magnitude, vector.y / magnitude };

        return normalized;
    }

    float GetDeltaTime()
    {
        return 0.016f;
    }

    bool isCollide(Entity* objI, Entity* objII)
    {
        std::vector<sf::Vector2f> AllPoint;
        AllPoint.push_back({ objI->getPosition().x,objI->getPosition().y });
        AllPoint.push_back({ objI->getPosition().x + objI->GetSize(),objI->getPosition().y });
        AllPoint.push_back({ objI->getPosition().x,objI->getPosition().y + objI->GetSize() });
        AllPoint.push_back({ objI->getPosition().x + objI->GetSize(),objI->getPosition().y + objI->GetSize() });
        AllPoint.push_back({ objI->getPosition().x + objI->GetSize() / 2,objI->getPosition().y + objI->GetSize() / 2 });
        for (sf::Vector2f Point : AllPoint)
        {
            if (Point.x >= objII->getPosition().x && Point.x <= objII->getPosition().x + objII->GetSize())
            {
                if (Point.y >= objII->getPosition().y && Point.y <= objII->getPosition().y + objII->GetSize())
                {
                    return true;
                }
            }
        }

        return false;
    }
}
