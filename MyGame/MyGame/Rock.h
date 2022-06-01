#pragma once
#include "Engine/GameEngine.h"

class Rock : public GameObject

{

public:

    // Creates our HealthPack.

    Rock(sf::Vector2f pos);

    // Functions overridden from GameObject:

    void draw();

    void update(sf::Time& elapsed);
    sf::FloatRect getCollisionRect();
    void handleCollision(GameObject& otherGameObject);

private:

    sf::Sprite sprite;


};

typedef std::shared_ptr <Rock> RockPtr;