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
    setCollisionCheckEnabled(true);
    
   
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

    if (sprite.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(GAME.getRenderWindow())) && !scene.getMouse()) {
        if (scene.getUser() && sprite.getPosition().y > 100) {
            sprite.setTexture(GAME.getTexture("Resources/UsePenHighlighted.png"));
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                
                scene.updateMouse();
                int i = 0;
               
                int rounds = ((700) - ((sprite.getGlobalBounds().left + sprite.getGlobalBounds().width) - 90))/100;
                    while (i < Rocks.size() - 1 && rounds>0) {

                    Rocks.at(i)->UpdateMove(100 * i + 100, false);
                    i++;
                    rounds--;
                }
                Rocks.at(i)->UpdateMove(100 * i + 100, true);

                clearVector = true;
            }
        }
        else if (!scene.getUser() && sprite.getPosition().y < 100) {
            sprite.setTexture(GAME.getTexture("Resources/UsePenHighlighted.png"));
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                scene.updateMouse();
                int i = 0;
                while (i < Rocks.size() - 1) {

                    Rocks.at(i)->UpdateMove(-100 * i -100, false);
                    i++;
                }
                Rocks.at(i)->UpdateMove(-100 * i -100, true);

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

       
        otherGameObject.makeDead();

        RockPtr MakeRock;

        MakeRock = std::make_shared<Rock>(sf::Vector2f(rand()%65 + pos.x, rand() % 160 + pos.y));
        Rocks.push_back(MakeRock);       
       
    }
    if (otherGameObject.hasTag("movingRockFinal")) {
 
        otherGameObject.makeDead();
        RockPtr MakeRock;

        MakeRock = std::make_shared<Rock>(sf::Vector2f(rand() % 65 + pos.x, rand() % 160 + pos.y));
        Rocks.push_back(MakeRock);

        GameScene& scene = (GameScene&)GAME.getCurrentScene();
        scene.updateMouse();
        scene.changeUser();
    
    }
   
}