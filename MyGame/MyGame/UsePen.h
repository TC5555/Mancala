#pragma once
#include "Engine/GameEngine.h"
#include "Rock.h" 
#include "GameScene.h"
class UsePen : public GameObject

{

public:

    // Creates our HealthPack.

    UsePen(sf::Vector2f pos);

    // Functions overridden from GameObject:

    void draw();


    void mouseUpdate();
    void UsePen::update(sf::Time& elapsed);
    void handleCollision(GameObject& otherGameObject);
    sf::FloatRect getCollisionRect();
  
private:
    sf::Text text_;

    sf::Sprite sprite;
    int pressed = NULL;
    std::vector<RockPtr> Rocks;
    int rocksmade = 0;
    sf::Vector2f pos;
    bool clearVector = false;
    bool newRock;
};

typedef std::shared_ptr<UsePen> UsePenPtr;