#include "Rock.h"

#include "GameScene.h"



Rock::Rock(sf::Vector2f pos)

{

    sprite.setTexture(GAME.getTexture("Resources/Rock.png"));
	sprite.setPosition(pos);
	assignTag("rock");

}

void Rock::draw()
{
    
    GAME.getRenderWindow().draw(sprite);

}

void Rock::UpdateMove()
{
	!move;
	makeDead();
}


void Rock::update(sf::Time& elapsed) {
	if (move) {
		printf("hi");
	}
	//int msElapsed = elapsed.asMilliseconds();
	//sf::Vector2f pos = sprite.getPosition();
	//GameScene& scene = (GameScene&)GAME.getCurrentScene();

	//sprite.setPosition(sf::Vector2f(pos.x - .1 * msElapsed, pos.y));
}


sf::FloatRect Rock::getCollisionRect()
{
	return sprite.getGlobalBounds();
}
