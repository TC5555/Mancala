#pragma once
#include "Engine/GameEngine.h"

class Rock : public GameObject

{

public:

    // Creates our HealthPack.

    Rock();

    // Functions overridden from GameObject:

    void draw();

    int getPool();

   
private:

    sf::Sprite sprite;


};

typedef std::shared_ptr <Rock> RockPtr;