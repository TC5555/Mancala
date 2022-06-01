#include "UsePens.h"

#include "GameScene.h"



UsePens::UsePens(sf::Vector2f pos)

{
    sprite.setTexture(GAME.getTexture("Resources/UsePen.png"));
    assignTag("UsePens");
    sprite.setPosition(pos);


}

void UsePens::draw()
{
    GAME.getRenderWindow().draw(sprite);

}

void UsePens::MUpdate() {
    !Mdisable;
}


void UsePens::update(sf::Time& elapsed) {

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&& Mdisable){ 
        GameScene& scene = (GameScene&)GAME.getCurrentScene();
        if (scene.getUser()) {
            if (User1Sprite1.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(GAME.getRenderWindow()))) {
                MUpdate();
                pressed = 1;
                setCollisionCheckEnabled(true);
            }
            else if (User1Sprite2.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(GAME.getRenderWindow()))) {
                scene.changeUser();
                printf("as");
            }
            else if (User1Sprite3.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(GAME.getRenderWindow()))) {
                scene.changeUser();
                printf("as");
            }
            else if (User1Sprite4.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(GAME.getRenderWindow()))) {
                scene.changeUser();
                printf("as");
            }
            else if (User1Sprite5.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(GAME.getRenderWindow()))) {
                scene.changeUser();
                printf("as");
            }
            else if (User1Sprite6.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(GAME.getRenderWindow()))) {
                scene.changeUser();
                printf("as");
            }
        }
            else {
                if (User2Sprite1.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(GAME.getRenderWindow()))) {
                    scene.changeUser();
                    printf("sa");
                }
                else if (User2Sprite2.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(GAME.getRenderWindow()))) {
                    scene.changeUser();
                    printf("sa");
                }
                else if (User2Sprite3.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(GAME.getRenderWindow()))) {
                    scene.changeUser();
                    printf("sa");
                }
                else if (User2Sprite4.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(GAME.getRenderWindow()))) {
                    scene.changeUser();
                    printf("sa");
                }
                else if (User2Sprite5.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(GAME.getRenderWindow()))) {
                    scene.changeUser();
                    printf("sa");
                }
                else if (User2Sprite6.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(GAME.getRenderWindow()))) {
                    scene.changeUser();
                    printf("sa");
                }
            }
        }
    }

void UsePens::handleCollision(GameObject& otherGameObject)
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
       /* sf::Vector2f pos = sprite.getPosition();
        float x = pos.x;
        float y = pos.y;
        sf::FloatRect bounds = sprite.getGlobalBounds();
        float explosionX;
        float explosionY;*/


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