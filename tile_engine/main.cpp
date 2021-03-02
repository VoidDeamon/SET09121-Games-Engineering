#include <SFML/Graphics.hpp>
#include "player.h"
#include "LevelSystem.h"

using namespace sf;
using namespace std;

const int gameWidth = 800;
const int gameHeight = 500;

Player player;

void Load() {
    player.setPosition(Vector2f(150,150));
    ls::loadLevelFile("res/maze_2.txt");
    // Print the level to the console
    for (size_t y = 0; y < ls::getHeight(); ++y) {
        for (size_t x = 0; x < ls::getWidth(); ++x) {
            cout << ls::getTile({ x, y });
        }
        cout << endl;
    }
}

void Update(RenderWindow& window) {
    // Reset clock, recalculate deltatime
    static Clock clock;
    float dt = clock.restart().asSeconds();
    // check and consume events
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            window.close();
            return;
        }
    }

    // Quit Via ESC Key
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        window.close();
    }

    player.Update(dt);
}


void Render(RenderWindow& window) {
    // Draw Everything
    player.Render(window);
    ls::Render(window);
}

int main() {
    RenderWindow window(VideoMode(gameWidth, gameHeight), "TILE ENGINE");
    Load();
    while (window.isOpen()) {
        window.clear();
        Update(window);
        Render(window);
        window.display();
    }
    return 0;
}