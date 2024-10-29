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
	int ScoreR =0, ScoreB =0;

	sf::Font font;
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
	void Win();
	void Restart();

	friend Entity;
};
