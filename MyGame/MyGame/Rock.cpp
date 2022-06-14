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

void Rock::UpdateMove(int newMove, bool isFinal)
{
	move = newMove;
	if (isFinal) {
		assignTag("movingRockFinal");
	}
	else {
		assignTag("movingRock");
	}
}
void Rock::UpdateUp() {
	if (pos.y > 200) {
		sprite.setPosition(sf::Vector2f(pos.x, pos.y - 180));
	}
	else {
		sprite.setPosition(sf::Vector2f(pos.x, pos.y + 180));
	}
}


void Rock::update(sf::Time& elapsed) {
	if (move != 0) {
		sprite.setPosition(sf::Vector2f(pos.x + move, pos.y));
		move = 0;
	}
}


sf::FloatRect Rock::getCollisionRect()
{
	return sprite.getGlobalBounds();
}
