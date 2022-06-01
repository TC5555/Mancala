#pragma once
#include "Engine/GameEngine.h"

class UsePens : public GameObject

{

public:

    // Creates our HealthPack.

    UsePens(sf::Vector2f pos);

    // Functions overridden from GameObject:

    void draw();


    void MUpdate();
    void UsePens::update(sf::Time& elapsed);
    void handleCollision(GameObject& otherGameObject);

private:
    bool Mdisable = false;
    sf::Sprite sprite;
    int pressed = NULL;


};

typedef std::shared_ptr<UsePens> UsePensPtr;