#include "Rock.h"

#include "GameScene.h"



Rock::Rock(sf::Vector2f pos)
{
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
	isfinal = isFinal;
}



void Rock::update(sf::Time& elapsed) {
	if (move > 0) {
		if (sprite.getPosition().y < 300) {
			sprite.setPosition(sf::Vector2f(sprite.getPosition().x - 100, sprite.getPosition().y));
		}
		else {
			sprite.setPosition(sf::Vector2f(sprite.getPosition().x + 100, sprite.getPosition().y));
		}
		if (sprite.getPosition().x > 700) {
			sprite.setPosition(sf::Vector2f(sprite.getPosition().x, 100));
		}
		if (sprite.getPosition().x < 100) {
			sprite.setPosition(sf::Vector2f(sprite.getPosition().x, 400));
		}
		move--;
	}
	if (move == 0) {
		if (isfinal) {
			assignTag("movingRockFinal");
		}
		else {
			assignTag("movingRock");
		}
		move--;
	}
}


sf::Vector2f Rock::getPos()
{
	return sprite.getPosition();
}


sf::FloatRect Rock::getCollisionRect()
{
	return sprite.getGlobalBounds();
}
