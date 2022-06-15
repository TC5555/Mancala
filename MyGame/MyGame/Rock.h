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
    void UpdateMove(int newMove, bool isFinal);

    //void handleCollision(GameObject& otherGameObject);

private:
    sf::Vector2f pos;
    sf::Sprite sprite;
    int move = 0;

};

typedef std::shared_ptr <Rock> RockPtr;