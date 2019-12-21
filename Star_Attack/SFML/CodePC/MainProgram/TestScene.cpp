#include "TestScene.h"
#include "normalBullet.h"


TestScene::TestScene(ResourceManager* rm):
	GameState(rm)
{
	bh = new BulletHandler();

	
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
	}
	return state;
}

GameState * TestScene::update(const sf::Time & delta)
{
	GameState* state = this;

	bh->update(delta, rm);
	return state;
}

void TestScene::render(sf::RenderWindow & window) const
{
	bh->render(window);
}
	