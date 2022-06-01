#include "Pen.h"
#include "GameScene.h"

Pen::Pen(sf::Vector2f pos)
{
	sprite.setTexture(GAME.getTexture("Resources/Pen.png"));
	assignTag("Pens");
	sprite.setPosition(pos);
}
void Pen::draw()
{
	GAME.getRenderWindow().draw(sprite);
}
