#include "Rock.h"

#include "GameScene.h"



Rock::Rock(sf::Vector2f pos)
{
	this->pos = pos;
    sprite.setTexture(GAME.getTexture("Resources/Rock.png"));
	sprite.setPosition( pos.x, pos.y);
	assignTag("rock");

}

void Rock::draw()
{
    
    GAME.getRenderWindow().draw(sprite);

}

void Rock::UpdateMove(int newMove)
{
	if (hasTag("movingRock")) {
		assignTag("Rock");
	}
	else {
	move = newMove;
	assignTag("movingRock");
}
}



void Rock::update(sf::Time& elapsed) {
	if (move > 0) {
		sprite.setPosition(sf::Vector2f(pos.x + move, pos.y));
		move = 0;
	}
}


sf::FloatRect Rock::getCollisionRect()
{
	return sprite.getGlobalBounds();
}
