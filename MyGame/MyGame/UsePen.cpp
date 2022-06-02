#include "UsePen.h"
#include "Rock.h"
#include "GameScene.h"



UsePen::UsePen(sf::Vector2f pos)

{
    sprite.setTexture(GAME.getTexture("Resources/UsePen.png"));
    assignTag("UsePen");
    sprite.setPosition(pos);
    setCollisionCheckEnabled(true);


}

void UsePen::draw()
{
    GAME.getRenderWindow().draw(sprite);

}

void UsePen::MUpdate() {
    !Mdisable;
}


void UsePen::update(sf::Time& elapsed) {
    if (sprite.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(GAME.getRenderWindow()))) {
        sprite.setTexture(GAME.getTexture("Resources/UsePenHighlighted.png"));
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
    if (otherGameObject.hasTag("rock") && sf::Mouse::isButtonPressed(sf::Mouse::Left) && sprite.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(GAME.getRenderWindow())))
    {
        ((Rock&)otherGameObject).UpdateMove();    
       
    }
   
}