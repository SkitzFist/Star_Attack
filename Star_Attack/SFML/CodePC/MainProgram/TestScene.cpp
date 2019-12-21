#include "TestScene.h"
#include "normalBullet.h"
#include <string>

TestScene::TestScene(ResourceManager* rm):
	GameState(rm)
{
	bh = new BulletHandler();

	font.loadFromFile("../Fonts/Lemon.otf");
	nrOfBullets.setFont(font);
	
	sf::Vector2f pos1{
		static_cast<float>(rm->getWindowWidth() / 2),
		40.f
	};
	nrOfBullets.setPosition(pos1);
	nrOfBullets.setCharacterSize((unsigned)52);

	Bullet* bullet = new FractalBullet(rm->getRedBallTexture(), bh);
	sf::Vector2f pos{
				0,
		static_cast<float>(rm->getWindowHeight() / 2)


	};
	bullet->setPosition(pos);

	sf::Vector2f targetPos{
				static_cast<float>(rm->getWindowWidth()),
		static_cast<float>(rm->getWindowHeight() / 2)
	};

	sf::Vector2f delta{
		targetPos.x - pos.x,
		targetPos.y - pos.y
	};
	float magnitude = sqrt(delta.x * delta.x + delta.y * delta.y);
	sf::Vector2f dir{
		delta.x / magnitude,
		delta.y / magnitude
	};

	bullet->setPosition(pos);
	bullet->setDirection(dir);

	bh->addBullet(bullet);

}


TestScene::~TestScene()
{
	delete bh;
}

GameState * TestScene::handleEvent(const sf::Event & event)
{
	GameState* state = this;
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Space) {
			
		}
	}
	return state;
}

GameState * TestScene::update(const sf::Time & delta)
{
	GameState* state = this;

	bh->update(delta, rm);
	nrOfBullets.setString(std::to_string(bh->getNrOf()));
	return state;
}

void TestScene::render(sf::RenderWindow & window) const
{
	bh->render(window);
	window.draw(nrOfBullets);
}
	