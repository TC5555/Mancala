#include "UsePens.h"

#include "GameScene.h"



UsePens::UsePens()

{

    User1Sprite1.setTexture(GAME.getTexture("Resources/Pen.png"));

    User1Sprite2.setTexture(GAME.getTexture("Resources/Pen.png"));

}

void UsePens::draw()

{

    User1Sprite1.setPosition(sf::Vector2f(90, 100));

    GAME.getRenderWindow().draw(User1Sprite1);



   // User1Sprite2.setPosition(sf::Vector2f(60, 50));

   // GAME.getRenderWindow().draw(User1Sprite2);

}

void UsePens::update(sf::Time& elapsed) {

 

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){ 
        GameScene& scene = (GameScene&)GAME.getCurrentScene();
        if (scene.getUser()) {
            if (User1Sprite1.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(GAME.getRenderWindow()))) {
                printf("as");
            }
            if (User1Sprite1.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(GAME.getRenderWindow()))) {
                printf("as");
            }
            if (User1Sprite1.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(GAME.getRenderWindow()))) {
                printf("as");
            }
        }
    }



}

