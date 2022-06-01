#pragma once
#include "Engine/GameEngine.h"
#include "UsePens.h"
#include "Rock.h"
#include "Pen.h"

class PenSpawner : public GameObject

{

public:

    // Creates our HealthPack.

    PenSpawner();

    // Functions overridden from GameObject:


};
typedef std::shared_ptr<PenSpawner> PenSpawnerPtr;
