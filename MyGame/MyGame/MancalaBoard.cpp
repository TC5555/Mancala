#include "MancalaBoard.h"
#include "GameScene.h"

MancalaBoard::MancalaBoard()
{
	sprite.setTexture(GAME.getTexture("Resources/MancalaBackground.png"));
	assignTag("background");
}
void MancalaBoard::draw()
{
	GAME.getRenderWindow().draw(sprite);
}
