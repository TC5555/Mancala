#include "UsePen.h"
#include "GameScene.h"


using namespace std;
UsePen::UsePen(sf::Vector2f pos)
{
    sprite.setTexture(GAME.getTexture("Resources/UsePen.png"));
    assignTag("UsePen");
    sprite.setPosition(pos);
    setCollisionCheckEnabled(true);
    
   
    RockPtr MakeRock;
    
    MakeRock = std::make_shared<Rock>(sf::Vector2f(pos.x+40, pos.y+40));
    Rocks.push_back(MakeRock);
    
    
    MakeRock = std::make_shared<Rock>(sf::Vector2f(pos.x + 40, pos.y + 60));
    Rocks.push_back(MakeRock);

    
    MakeRock = std::make_shared<Rock>(sf::Vector2f(pos.x + 40, pos.y + 80));
    Rocks.push_back(MakeRock);

    
    MakeRock = std::make_shared<Rock>(sf::Vector2f(pos.x + 40, pos.y + 100));
    Rocks.push_back(MakeRock);


}

void UsePen::draw()
{
    GAME.getRenderWindow().draw(sprite);
   
   
}

void UsePen::MUpdate() {
    !Mdisable;
}


void UsePen::update(sf::Time& elapsed) {
    Scene& scene = GAME.getCurrentScene();
    if (!rockmade) {
     
        scene.addGameObject(Rocks.at(Rocks.size() - 1));
        scene.addGameObject(Rocks.at(Rocks.size() - 2));
        scene.addGameObject(Rocks.at(Rocks.size() - 3));
        scene.addGameObject(Rocks.at(Rocks.size() - 4));
        rockmade = true;
    }
    if(Game){}
    if (sprite.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(GAME.getRenderWindow()))) {
        sprite.setTexture(GAME.getTexture("Resources/UsePenHighlighted.png"));
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            int i = 0;
            while (i < Rocks.size()) {
                Rocks.at(i)->UpdateMove(100*i + 100);
                i++;
            }
        }
    }
    else {
        sprite.setTexture(GAME.getTexture("Resources/UsePen.png"));
    }
}


sf::FloatRect UsePen::getCollisionRect()
{
    return sprite.getGlobalBounds();
}

void UsePen::handleCollision(GameObject& otherGameObject)
{
    if (otherGameObject.hasTag("movingRock"))
    {
        pool++;
        Rocks.push_back((RockPtr&)otherGameObject);

       
    }
   
}