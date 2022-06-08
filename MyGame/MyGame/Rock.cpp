#include "Rock.h"

#include "GameScene.h"



Rock::Rock(sf::Vector2f pos)
{
	this->pos = pos;
    sprite.setTexture(GAME.getTexture("Resources/Rock.png"));
	sprite.setPosition(pos);
	assignTag("rock");

}

void Rock::draw()
{
    
    GAME.getRenderWindow().draw(sprite);

}

void Rock::UpdateMove(int newMove)
{
	move = newMove;
	assignTag("movingRock");
}


void Rock::update(sf::Time& elapsed) {
	if (move > 0) {
		sprite.setPosition(sf::Vector2f(pos.x - .01 * move, pos.y));
		move - 10;
	}
}


sf::FloatRect Rock::getCollisionRect()
{
	return sprite.getGlobalBounds();
}
