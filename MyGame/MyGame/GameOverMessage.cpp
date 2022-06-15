#include "GameOverMessage.h"
#include "GameScene.h"
#include <sstream>
GameOverMessage::GameOverMessage(bool user)
{
	text_.setFont(GAME.getFont("Resources/Orbitron-VariableFont_wght.ttf"));
	text_.setPosition(sf::Vector2f(50.0f, 50.0f));
	text_.setCharacterSize(40);
	std::stringstream stream;
	if (user) {
		text_.setFillColor(sf::Color::Red);
		stream << "GAME OVER\n\nUSER1 WINS\n\nPRESS ENTER TO CONTINUE";
		text_.setString(stream.str());
	}
	else {
		text_.setFillColor(sf::Color::Blue);
		stream << "GAME OVER\n\nUSER2 WINS\n\nPRESS ENTER TO CONTINUE";
		text_.setString(stream.str());
	}
}
void GameOverMessage::draw()
{
	GAME.getRenderWindow().draw(text_);
}
void GameOverMessage::update(sf::Time& time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		GameScenePtr scene = std::make_shared<GameScene>();
		GAME.setScene(scene);
		return;
	}
}