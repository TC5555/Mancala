#pragma once
#include "Engine/GameEngine.h"
class Pen : public GameObject
{
public:
	// Creates our HealthPack.
	Pen(sf::Vector2f pos);
	// Functions overridden from GameObject:
	void draw();
	int getPool();

private:
	sf::Sprite sprite;

};
typedef std::shared_ptr<Pen> PenPtr;
