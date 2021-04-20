#include <SFML/Graphics.hpp>
#include "player.h"
#include "ghost.h"
#include "pacman.h"
#include "system_renderer.h"

using namespace sf;
using namespace std;

const int gameWidth = 800;
const int gameHeight = 800;

EntityManager em;

std::shared_ptr<Scene> gameScene;
std::shared_ptr<Scene> menuScene;
std::shared_ptr<Scene> activeScene;

void Load() {
    // Load Scene-Local Assets
    gameScene.reset(new GameScene());
    menuScene.reset(new MenuScene());
    gameScene->load();
    menuScene->load();
    // Start at main menu
    activeScene = menuScene;
}

void Update(RenderWindow& window) {
    static Clock clock;
    float dt = clock.restart().asSeconds();
    activeScene->update(dt);

    // check and consume events
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            window.close();
            return;
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        window.close();
    }
}

void Render(RenderWindow& window) {
    activeScene->render();
    // flush to screen
    Renderer::render();
}

int main() {
    RenderWindow window(VideoMode(gameWidth, gameHeight), "PACMAN");
    Renderer::initialise(window);
    Load();
    while (window.isOpen()) {
        window.clear();
        Update(window);
        Render(window);
        window.display();
    }
    return 0;
}