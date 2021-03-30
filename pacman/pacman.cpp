#include "pacman.h"
#include "player.h"
#include "ghost.h"
using namespace std;
using namespace sf;

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
	//Set up the text element here!
}

void GameScene::load() {
	for (int i = 0; i < 4; i++) {
		auto ghost = make_shared<Ghost>();
		ghost->setPosition(Vector2f(100, 100));
		_ents.list.push_back(ghost);
	}
	auto player = make_shared<Player>();
	_ents.list.push_back(player);
}

void GameScene::update(double dt) {
	if (Keyboard::isKeyPressed(Keyboard::Tab)) {
		activeScene = menuScene;
	}
	Scene::update(dt);
	//...
}

void GameScene::render() {
	Scene::render();
}