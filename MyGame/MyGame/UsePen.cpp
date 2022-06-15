#include "UsePen.h"
#include "GameScene.h"
#include <sstream>

using namespace std;
UsePen::UsePen(sf::Vector2f pos)
{
    this->pos = pos;
    sprite.setTexture(GAME.getTexture("Resources/UsePen.png"));
    assignTag("UsePen");
    sprite.setPosition(pos);

    
   
    RockPtr MakeRock;
    
    MakeRock = std::make_shared<Rock>(sf::Vector2f((rand() % 50+20) -20 + pos.x, (rand() % 130-50) + 50 + pos.y));
    Rocks.push_back(MakeRock);
    
    
    MakeRock = std::make_shared<Rock>(sf::Vector2f((rand() % 50+20)-20 + pos.x, (rand() % 130 - 50) + 50 + pos.y));
    Rocks.push_back(MakeRock);

    
    MakeRock = std::make_shared<Rock>(sf::Vector2f((rand() % 50+20) -20 + pos.x, (rand() % 130 - 50) + 50 + pos.y));
    Rocks.push_back(MakeRock);

    
    MakeRock = std::make_shared<Rock>(sf::Vector2f((rand() % 50+20)-20 + pos.x, (rand() % 130 - 50) + 50 + pos.y));
    Rocks.push_back(MakeRock);

    text_.setFont(GAME.getFont("Resources/Orbitron-VariableFont_wght.ttf"));
    text_.setPosition(sf::Vector2f(pos.x+40,pos.y+180));
    text_.setCharacterSize(24);
    text_.setFillColor(sf::Color::Blue);
    assignTag("score");

}

void UsePen::draw()
{
    GAME.getRenderWindow().draw(sprite);
    GAME.getRenderWindow().draw(text_);
   
}

void UsePen::update(sf::Time& elapsed) {
 


    GameScene& scene = (GameScene&)GAME.getCurrentScene();

    if (!scene.getMouse()) {
        setCollisionCheckEnabled(true);
    }

    std::stringstream stream;
    stream << Rocks.size();
    text_.setString(stream.str());


    if (clearVector) {
        clearVector = false;
        Rocks.clear();
        rocksmade = 0;
    }

    while (Rocks.size() != rocksmade) {
        scene.addGameObject(Rocks.at(rocksmade));
        rocksmade++;
    }

    if (sprite.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(GAME.getRenderWindow())) && !scene.getMouse() && !
        Rocks.empty()) {
        if (scene.getUser() && sprite.getPosition().y > 100) {
            sprite.setTexture(GAME.getTexture("Resources/UsePenHighlighted.png"));
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                
                scene.emptyPens(1);
                scene.updateMouse();
                int i = 0;
               
              
                    while (i < Rocks.size()) {

                    Rocks.at(i)->UpdateMove(i+1, false);
                    i++;
        
                }
     

                clearVector = true;
            }
        }
        else if (!scene.getUser() && sprite.getPosition().y < 100) {
            sprite.setTexture(GAME.getTexture("Resources/UsePenHighlighted.png"));
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                scene.emptyPens(1);
                scene.updateMouse();
                int i = 0;


                while (i < Rocks.size()) {

                    Rocks.at(i)->UpdateMove(i + 1, false);
                    i++;

                }


                clearVector = true;
            }
        }
    }
    else{ sprite.setTexture(GAME.getTexture("Resources/UsePen.png")); }

   
    
}

    



sf::FloatRect UsePen::getCollisionRect()
{
    return sprite.getGlobalBounds();
}

void UsePen::handleCollision(GameObject& otherGameObject)
{
    if (otherGameObject.hasTag("movingRock"))
    {
        if (Rocks.empty()) {
            GameScene& scene = (GameScene&)GAME.getCurrentScene();
            scene.emptyPens(-1);
        }
       
        otherGameObject.makeDead();

        RockPtr MakeRock;

        MakeRock = std::make_shared<Rock>(sf::Vector2f(rand()%65 + pos.x, rand() % 160 + pos.y));
        Rocks.push_back(MakeRock);       
        setCollisionCheckEnabled(false);
    }
    if (otherGameObject.hasTag("movingRockFinal")) {
 
        otherGameObject.makeDead();
        RockPtr MakeRock;

        MakeRock = std::make_shared<Rock>(sf::Vector2f(rand() % 65 + pos.x, rand() % 160 + pos.y));
        Rocks.push_back(MakeRock);

        GameScene& scene = (GameScene&)GAME.getCurrentScene();

        if (Rocks.empty()) {

            scene.emptyPens(-1);
        }
        else {
            scene.changeUser();
        }
        scene.updateMouse();
        setCollisionCheckEnabled(false);
    }
   
}