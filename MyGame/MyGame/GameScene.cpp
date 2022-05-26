#include "GameScene.h"
#include "UsePens.h"
#include "MancalaBoard.h"
#include "Pen.h"
GameScene::GameScene()
{
	MancalaBoardPtr MancalaBoardSpawner = std::make_shared<MancalaBoard>();
	addGameObject(MancalaBoardSpawner);

	PenPtr PenSpawner = std::make_shared<Pen>();
	addGameObject(PenSpawner);

	UsePensPtr UsePensSpawner = std::make_shared<UsePens>();
	addGameObject(UsePensSpawner);

}

bool GameScene::getUser()
{
	return user_;
}
void GameScene::changeUser()
{
	user_ = !user_;
}

int GameScene::getScore()
{
	return score_;
}
void GameScene::increaseScore()
{
	++score_;
}


