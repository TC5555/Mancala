#include "GameScene.h"
#include "MancalaBoard.h"
#include "Pen.h"
#include "UsePen.h"
#include "Rock.h"
#include "GameOverScene.h"

GameScene::GameScene()
{
	MancalaBoardPtr MancalaBoardSpawner = std::make_shared<MancalaBoard>();
	addGameObject(MancalaBoardSpawner);
	/////////////////////////////////////////////////////////////////////////
	PenPtr MakePen = std::make_shared<Pen>(sf::Vector2f(10, 50));
	addGameObject(MakePen);
	MakePen = std::make_shared<Pen>(sf::Vector2f(700, 50));
	addGameObject(MakePen);
	/////////////////////////////////////////////////////////////////////////
	UsePenPtr MakeUsePens = std::make_shared<UsePen>(sf::Vector2f(105, 50));
	addGameObject(MakeUsePens);
	MakeUsePens = std::make_shared<UsePen>(sf::Vector2f(205, 50));
	addGameObject(MakeUsePens);
	MakeUsePens = std::make_shared<UsePen>(sf::Vector2f(305, 50));
	addGameObject(MakeUsePens);
	MakeUsePens = std::make_shared<UsePen>(sf::Vector2f(405, 50));
	addGameObject(MakeUsePens);
	MakeUsePens = std::make_shared<UsePen>(sf::Vector2f(505, 50));
	addGameObject(MakeUsePens);
	MakeUsePens = std::make_shared<UsePen>(sf::Vector2f(605, 50));
	addGameObject(MakeUsePens);


	MakeUsePens = std::make_shared<UsePen>(sf::Vector2f(105, 270));
	addGameObject(MakeUsePens);
	MakeUsePens = std::make_shared<UsePen>(sf::Vector2f(205, 270));
	addGameObject(MakeUsePens);
	MakeUsePens = std::make_shared<UsePen>(sf::Vector2f(305, 270));
	addGameObject(MakeUsePens);
	MakeUsePens = std::make_shared<UsePen>(sf::Vector2f(405, 270));
	addGameObject(MakeUsePens);
	MakeUsePens = std::make_shared<UsePen>(sf::Vector2f(505, 270));
	addGameObject(MakeUsePens);
	MakeUsePens = std::make_shared<UsePen>(sf::Vector2f(605, 270));
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

void GameScene::emptyPens(int changeEmpty)
{
	if (user_) {
		empty1 += changeEmpty;
		if (empty1 == 6) {
			GameOverScenePtr gameOverScene = std::make_shared<GameOverScene>(user_);
			GAME.setScene(gameOverScene);
		}
	}
	else {
		empty2 += changeEmpty;
		if (empty2 == 6) {
			GameOverScenePtr gameOverScene = std::make_shared<GameOverScene>(user_);
			GAME.setScene(gameOverScene);
		}
	}
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

