#include "PenSpawner.h"
#include "GameScene.h"

PenSpawner::PenSpawner() {
	PenPtr MakePen = std::make_shared<Pen>(sf::Vector2f(100, 50));
	GAME.getCurrentScene().addGameObject(MakePen);

	
}