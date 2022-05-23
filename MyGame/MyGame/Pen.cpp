#include "Pen.h"
#include "GameScene.h"

Pen::Pen()
{
	sprite.setTexture(GAME.getTexture("Resources/Pen.png"));
	sprite.setPosition(sf::Vector2f(25, 100));
}
void Pen::draw()
{
		sprite.setPosition(sf::Vector2f(25, 100));
	GAME.getRenderWindow().draw(sprite);
	
	sprite.setPosition(sf::Vector2f(675, 100));
	GAME.getRenderWindow().draw(sprite);
}
