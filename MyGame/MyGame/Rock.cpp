#include "Rock.h"

#include "GameScene.h"



Rock::Rock()

{

    sprite.setTexture(GAME.getTexture("Resources/Rock.png"));



}

void Rock::draw()

{
   
    GAME.getRenderWindow().draw(sprite);

}