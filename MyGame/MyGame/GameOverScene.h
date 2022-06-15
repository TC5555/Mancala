#pragma once
#include "Engine/GameEngine.h"
class GameOverScene : public Scene
{
public:
	// Creates our Scene.
	GameOverScene(bool user);
};
typedef std::shared_ptr<GameOverScene> GameOverScenePtr;
