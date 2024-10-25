#pragma once

#include <vector>

class Entity;
class Ball;

namespace sf 
{
	class RenderWindow;
}

class GameManager
{
	std::vector<Entity*> mEntities;
	Ball* mBall;

	sf::RenderWindow* mWindow;
	float mDeltaTime;

	GameManager();

	void addEntity(Entity* entity);

public:
	~GameManager();

	static GameManager* Instantiate();
	static GameManager* Get();
	void Update();
	void Draw();

	void setWindow(sf::RenderWindow* window);
	void setDeltaTime(float deltaTime);
	float getDeltaTime() const;

	std::vector<Entity*> GetEntities();
	Ball* GetBall();


	friend Entity;
};

