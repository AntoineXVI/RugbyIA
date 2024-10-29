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

    bool isCollideCircle(Entity* objI, Entity* objII)
    {
        if (objII == nullptr) {
            return false;
        }

        sf::Vector2f posI = objI->getPosition();
        sf::Vector2f posII = objII->getPosition();
        float radiusI = objI->GetSize() / 2;
        float radiusII = objII->GetSize() / 2;

        float dx = posI.x - posII.x;
        float dy = posI.y - posII.y;
        float distanceSquared = dx * dx + dy * dy;

        float radiusSum = radiusI + radiusII;
        return distanceSquared <= (radiusSum * radiusSum);
    }

    int isPlayerClicked(sf::Vector2f mousePosition, std::vector<Entity*> entities)
    {
        for (int i = 0; i < entities.size(); i++)
        {
            auto playerPos = entities[i]->getPosition();
            if (mousePosition.x > (int)playerPos.x && mousePosition.x < (int)playerPos.x + entities[i]->GetSize())
            {
                if (mousePosition.y > (int)playerPos.y && mousePosition.y < (int)playerPos.y + entities[i]->GetSize())
                {
                    std::cout << "player " << i << " clicked\n";
                    return i;
                }
            }
        }
        return -1; //not player on click
    }
}
