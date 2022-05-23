#pragma once
#include "Engine/GameEngine.h"
class MancalaBoard : public GameObject
{
public:
	// Creates our HealthPack.
	MancalaBoard();
	// Functions overridden from GameObject:
	void draw();
private:
	sf::Sprite sprite;
};
typedef std::shared_ptr<MancalaBoard> MancalaBoardPtr;
