#include "GameOverScene.h"
#include "GameOverMessage.h"
GameOverScene::GameOverScene(bool user)
{
	GameOverMessagePtr gameOverMessage = std::make_shared<GameOverMessage>(user);
	addGameObject(gameOverMessage); 
}