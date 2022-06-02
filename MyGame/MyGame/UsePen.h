#pragma once
#include "Engine/GameEngine.h"

class UsePen : public GameObject

{

public:

    // Creates our HealthPack.

    UsePen(sf::Vector2f pos);

    // Functions overridden from GameObject:

    void draw();


    void MUpdate();
    void UsePen::update(sf::Time& elapsed);
    void handleCollision(GameObject& otherGameObject);
    sf::FloatRect getCollisionRect();
  
private:
    bool Mdisable = false;
    sf::Sprite sprite;
    int pressed = NULL;


};

typedef std::shared_ptr<UsePen> UsePenPtr;