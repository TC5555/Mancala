#include "GameScene.h"
#include "MancalaBoard.h"
#include "Pen.h"
#include "UsePen.h"
#include "Rock.h"

GameScene::GameScene()
{
	MancalaBoardPtr MancalaBoardSpawner = std::make_shared<MancalaBoard>();
	addGameObject(MancalaBoardSpawner);
	/////////////////////////////////////////////////////////////////////////
	PenPtr MakePen = std::make_shared<Pen>(sf::Vector2f(10, 50));
	addGameObject(MakePen);
	MakePen = std::make_shared<Pen>(sf::Vector2f(690, 50));
	addGameObject(MakePen);
	/////////////////////////////////////////////////////////////////////////
	UsePenPtr MakeUsePens = std::make_shared<UsePen>(sf::Vector2f(110, 50));
	addGameObject(MakeUsePens);
	MakeUsePens = std::make_shared<UsePen>(sf::Vector2f(210, 50));
	addGameObject(MakeUsePens);
	MakeUsePens = std::make_shared<UsePen>(sf::Vector2f(310, 50));
	addGameObject(MakeUsePens);
	MakeUsePens = std::make_shared<UsePen>(sf::Vector2f(410, 50));
	addGameObject(MakeUsePens);
	MakeUsePens = std::make_shared<UsePen>(sf::Vector2f(510, 50));
	addGameObject(MakeUsePens);
	MakeUsePens = std::make_shared<UsePen>(sf::Vector2f(610, 50));
	addGameObject(MakeUsePens);


	MakeUsePens = std::make_shared<UsePen>(sf::Vector2f(110, 270));
	addGameObject(MakeUsePens);
	MakeUsePens = std::make_shared<UsePen>(sf::Vector2f(210, 270));
	addGameObject(MakeUsePens);
	MakeUsePens = std::make_shared<UsePen>(sf::Vector2f(310, 270));
	addGameObject(MakeUsePens);
	MakeUsePens = std::make_shared<UsePen>(sf::Vector2f(410, 270));
	addGameObject(MakeUsePens);
	MakeUsePens = std::make_shared<UsePen>(sf::Vector2f(510, 270));
	addGameObject(MakeUsePens);
	MakeUsePens = std::make_shared<UsePen>(sf::Vector2f(610, 270));
	addGameObject(MakeUsePens);
	//////////////////////////////////////////////////////////////////

} 

bool GameScene::getUser()
{
	return user_;
}
void GameScene::changeUser()
{
	user_ = !user_;
}

bool GameScene::getMouse()
{
	return mouseDisabled;
}


void GameScene::updateMouse()
{
	mouseDisabled = !mouseDisabled;
}

int GameScene::getScore()
{
	return score_;
}
void GameScene::increaseScore()
{
	++score_;
}

