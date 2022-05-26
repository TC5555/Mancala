#pragma once
#include "Engine/GameEngine.h"

class UsePens : public GameObject

{

public:

    // Creates our HealthPack.

    UsePens();

    // Functions overridden from GameObject:

    void draw();

    int getPool();

    void UsePens::update(sf::Time& elapsed);

private:

    sf::Sprite User1Sprite1, User1Sprite2, User1Sprite3, User1Sprite4, User1Sprite5, User1Sprite6, User2Sprite1, User2Sprite2, User2Sprite3, User2Sprite4, User2Sprite5, User2Sprite6;



};

typedef std::shared_ptr<UsePens> UsePensPtr;