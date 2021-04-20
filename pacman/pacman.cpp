#include "pacman.h"
#include "player.h"
#include "ghost.h"
#include "system_renderer.h"
#include "LevelSystem.h"
#include "cmp_sprite.h"
#include "cmp_player_movement.h"
#include "cmp_enemy_ai_component.h"

#define GHOSTS_COUNT 4

using namespace std;
using namespace sf;

Font font;

void Scene::render() {
	_ents.render();
}

void Scene::update(double dt) {
	_ents.update(dt);
}

/*void Scene::load() {
	// player
	auto temp = std::make_shared<Player>();
	_ents.list.push_back(temp);
	temp->setPosition(sf::Vector2f(450.0f, 450.0f));
	// ghost
} */

std::vector<std::shared_ptr<Entity>>& Scene::getEnts() {
	return _ents.list;
}

void MenuScene::update(double dt) {
	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		activeScene = gameScene;
	}
	Scene::update(dt);
	text.setString("Almost Pacman");
}

void MenuScene::render() {
	Renderer::queue(&text);
	Scene::render();
}

void MenuScene::load() {
	font.loadFromFile("res/fonts/RobotoMono-Regular.ttf");
	text.setFont(font);
}

void GameScene::load() {
	ls::loadLevelFile("res/pacman.txt", 25.0f);

	{
		auto pl = make_shared<Entity>(this);

		pl->addComponent<PlayerMovementComponent>();
		auto s = pl->addComponent<ShapeComponent>();
		s->setShape<sf::CircleShape>(12.f);
		s->getShape().setFillColor(Color::Yellow);
		s->getShape().setOrigin(Vector2f(12.f, 12.f));

		_ents.list.push_back(pl);
	}

	const sf::Color ghost_cols[]{ {208, 62, 25},    // red Blinky
								 {219, 133, 28},   // orange Clyde
								 {70, 191, 238},   // cyan Inky
								 {234, 130, 229} }; // pink Pinky

	for (int i = 0; i < GHOSTS_COUNT; ++i) {
		auto ghost = make_shared<Entity>(this);
		auto s = ghost->addComponent<ShapeComponent>();
		s->setShape<sf::CircleShape>(12.f);
		s->getShape().setFillColor(ghost_cols[i % 4]);
		s->getShape().setOrigin(Vector2f(12.f, 12.f));
		ghost->addComponent<EnemyAIComponent>();

		_ents.list.push_back(ghost);
	}

	/*for (int i = 0; i < 4; i++) {
		auto ghost = make_shared<Entity>(this);
		ghost->setPosition(Vector2f(100, 100));
		auto s = ghost->addComponent<ShapeComponent>();
		s->setShape<sf::CircleShape>(12.f);
		_ents.list.push_back(ghost);
	}*/
	//auto player = make_shared<Entity>(this);
	//_ents.list.push_back(player);
}

void GameScene::update(double dt) {
	if (Keyboard::isKeyPressed(Keyboard::Tab)) {
		activeScene = menuScene;
	}
	Scene::update(dt);
	//...
}

void GameScene::render() {
	ls::Render(Renderer::getWindow());
	Scene::render();
}