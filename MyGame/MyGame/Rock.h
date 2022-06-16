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
    sf::Vector2f getPos();
    //void handleCollision(GameObject& otherGameObject);

private:
    sf::Vector2f pos;
    sf::Sprite sprite;
    int move = -1;
    bool isfinal;
};

typedef std::shared_ptr <Rock> RockPtr;