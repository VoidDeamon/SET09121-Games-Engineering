#include <SFML/Graphics.hpp>
#include "player.h"

using namespace sf;
using namespace std;

const int gameWidth = 800;
const int gameHeight = 600;

Player player;

void Load() {
    player.setPosition(Vector2f(30,30));
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