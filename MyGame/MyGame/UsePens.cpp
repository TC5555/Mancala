#include "UsePens.h"

#include "GameScene.h"



UsePens::UsePens()

{

   


}

void UsePens::draw()

{
    User1Sprite1.setTexture(GAME.getTexture("Resources/UsePen.png"));
    User1Sprite1.setPosition(sf::Vector2f(135, 100));
    GAME.getRenderWindow().draw(User1Sprite1);



    User1Sprite2.setTexture(GAME.getTexture("Resources/UsePen.png"));
    User1Sprite2.setPosition(sf::Vector2f(220, 100));
    GAME.getRenderWindow().draw(User1Sprite2);



    User1Sprite3.setTexture(GAME.getTexture("Resources/UsePen.png"));
    User1Sprite3.setPosition(sf::Vector2f(305, 100));
    GAME.getRenderWindow().draw(User1Sprite3);



    User1Sprite4.setTexture(GAME.getTexture("Resources/UsePen.png"));
    User1Sprite4.setPosition(sf::Vector2f(390, 100));
    GAME.getRenderWindow().draw(User1Sprite4);
    


    User1Sprite5.setTexture(GAME.getTexture("Resources/UsePen.png"));
    User1Sprite5.setPosition(sf::Vector2f(475, 100));
    GAME.getRenderWindow().draw(User1Sprite5);



    User1Sprite6.setTexture(GAME.getTexture("Resources/UsePen.png"));
    User1Sprite6.setPosition(sf::Vector2f(560, 100));
    GAME.getRenderWindow().draw(User1Sprite6);


    ////////////////////////////////////////////////////////////////////////


    User2Sprite1.setTexture(GAME.getTexture("Resources/UsePen.png"));
    User2Sprite1.setPosition(sf::Vector2f(135, 425));
    GAME.getRenderWindow().draw(User2Sprite1);



    User2Sprite2.setTexture(GAME.getTexture("Resources/UsePen.png"));
    User2Sprite2.setPosition(sf::Vector2f(220, 425));
    GAME.getRenderWindow().draw(User2Sprite2);



    User2Sprite3.setTexture(GAME.getTexture("Resources/UsePen.png"));
    User2Sprite3.setPosition(sf::Vector2f(305, 425));
    GAME.getRenderWindow().draw(User2Sprite3);



    User2Sprite4.setTexture(GAME.getTexture("Resources/UsePen.png"));
    User2Sprite4.setPosition(sf::Vector2f(390, 425));
    GAME.getRenderWindow().draw(User2Sprite4);



    User2Sprite5.setTexture(GAME.getTexture("Resources/UsePen.png"));
    User2Sprite5.setPosition(sf::Vector2f(475, 425));
    GAME.getRenderWindow().draw(User2Sprite5);



    User2Sprite6.setTexture(GAME.getTexture("Resources/UsePen.png"));
    User2Sprite6.setPosition(sf::Vector2f(560, 425));
    GAME.getRenderWindow().draw(User2Sprite6);

    /////////////////////////////////////////////////////////////////


}

void UsePens::update(sf::Time& elapsed) {

 

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){ 
        GameScene& scene = (GameScene&)GAME.getCurrentScene();
        if (scene.getUser()) {
            if (User1Sprite1.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(GAME.getRenderWindow()))) {


                scene.changeUser();
                printf("as");
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

