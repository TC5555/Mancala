#include "UsePen.h"
#include "GameScene.h"


using namespace std;
UsePen::UsePen(sf::Vector2f pos)
{
    this->pos = pos;
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

void UsePen::update(sf::Time& elapsed) {
    printf("%i", Rocks.size());

    GameScene& scene = (GameScene&) GAME.getCurrentScene();
    while(Rocks.size() != rocksmade) {
        scene.addGameObject(Rocks.at(rocksmade));
        rocksmade++;
    }
    if (scene.getUser() && sprite.getPosition().y > 100 && !scene.getMouse()) {
        if (sprite.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(GAME.getRenderWindow()))) {
            sprite.setTexture(GAME.getTexture("Resources/UsePenHighlighted.png"));
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                setCollisionCheckEnabled(false);

                int i = 0;
                while (i < Rocks.size()) {
                    Rocks.at(i)->UpdateMove(100 * i + 100);
                    i++;
                }
            }
        }
        else {
            sprite.setTexture(GAME.getTexture("Resources/UsePen.png"));
        }
    }
    else if (!scene.getUser() && sprite.getPosition().y < 100 && !scene.getMouse()) {
        sprite.setTexture(GAME.getTexture("Resources/UsePenHighlighted.png"));
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            int i = 0;
            while (i < Rocks.size()) {
                Rocks.at(i)->UpdateMove(50 * i);
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

       
        otherGameObject.makeDead();

        RockPtr MakeRock;

        MakeRock = std::make_shared<Rock>(sf::Vector2f(pos.x + 40, pos.y + 140));
        Rocks.push_back(MakeRock);

       
    }
   
}