#include "Pen.h"
#include "GameScene.h"

Pen::Pen(sf::Vector2f pos)
{
    this->pos = pos;
	sprite.setTexture(GAME.getTexture("Resources/Pen.png"));
	assignTag("Pens");
	sprite.setPosition(pos);
}
void Pen::draw()
{
    while (Rocks.size() != rocksmade) {

        GameScene& scene = (GameScene&)GAME.getCurrentScene();
        scene.addGameObject(Rocks.at(rocksmade));
        rocksmade++;
    }
	GAME.getRenderWindow().draw(sprite);
}
sf::FloatRect Pen::getCollisionRect()
{
    return sprite.getGlobalBounds();
}
void Pen::handleCollision(GameObject& otherGameObject)
{
    if (otherGameObject.hasTag("movingRock"))
    {
        if (Rocks.empty()) {
            GameScene& scene = (GameScene&)GAME.getCurrentScene();
            scene.emptyPens(-1);
        }

        otherGameObject.makeDead();

        RockPtr MakeRock;

        MakeRock = std::make_shared<Rock>(sf::Vector2f(sprite.getPosition().x,  pos.y));
        Rocks.push_back(MakeRock);

    }
    if (otherGameObject.hasTag("movingRockFinal")) {

        otherGameObject.makeDead();
        RockPtr MakeRock;

        MakeRock = std::make_shared<Rock>(sf::Vector2f(sprite.getPosition().x,pos.y));
        Rocks.push_back(MakeRock);

        GameScene& scene = (GameScene&)GAME.getCurrentScene();

        if (Rocks.empty()) {

            scene.emptyPens(-1);
        }
        else {
            scene.changeUser();
        }
        scene.updateMouse();

    }

}