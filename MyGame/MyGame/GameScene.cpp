#include "GameScene.h"
#include "MancalaBoard.h"
#include "PenSpawner.h"

GameScene::GameScene()
{
	MancalaBoardPtr MancalaBoardSpawner = std::make_shared<MancalaBoard>();
	addGameObject(MancalaBoardSpawner);

	PenSpawnerPtr PenSpawner = std::make_shared<PenSpawner>();
	addGameObject(PenSpawner);

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


