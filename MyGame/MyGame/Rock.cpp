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

void Rock::update(sf::Time& elapsed) {
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite.getPosition();
	GameScene& scene = (GameScene&)GAME.getCurrentScene();

	sprite.setPosition(sf::Vector2f(pos.x - .1 * msElapsed, pos.y));
}


sf::FloatRect Rock::getCollisionRect()
{
	return sprite.getGlobalBounds();
}

void Rock::handleCollision(GameObject& otherGameObject)
{
	if (otherGameObject.hasTag("ship"))
	{

		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		scene.decreaseLives();

		// Added to Update the damage level of the ship to show a more damages show on next update.
		//((Ship&)otherGameObject).updateDamageLevel(scene.getLives());
		makeDead();
	}
	if (otherGameObject.hasTag("laser"))
	{
		sf::Vector2f pos = sprite.getPosition();
		float x = pos.x;
		float y = pos.y;
		sf::FloatRect bounds = sprite.getGlobalBounds();
		float explosionX;
		float explosionY;


	//	GAME.getCurrentScene().addGameObject(explosion);
		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		scene.increaseScore();
		otherGameObject.makeDead();
		makeDead();

		if (scene.getScore() == 20)
		{
			scene.BigMeteorUnlock();
		}

		if (scene.getScore() == 50)
		{
			scene.HealthPackUnlock();
		}
	}
}