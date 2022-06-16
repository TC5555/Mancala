#pragma once
#include "Engine/GameEngine.h"
#include "Rock.h" 
class Pen : public GameObject
{
public:
	// Creates our HealthPack.
	Pen(sf::Vector2f pos);
	// Functions overridden from GameObject:
	void draw();
	int getPool();
	void handleCollision(GameObject& otherGameObject);
	sf::FloatRect getCollisionRect();
private:
	std::vector<RockPtr> Rocks;
	sf::Sprite sprite;
	sf::Vector2f pos;
	int rocksmade = 0;
};
typedef std::shared_ptr<Pen> PenPtr;
