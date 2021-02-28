#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

const int gameWidth = 800;
const int gameHeight = 600;
sf::Texture spritesheet;
sf::Sprite invader;

void Load() {
    if (!spritesheet.loadFromFile("res/img/invaders_sheet.png")) {
        cerr << "Failed to load spritesheet!" << std::endl;
    }
    invader.setTexture(spritesheet);
    invader.setTextureRect(sf::IntRect(0, 0, 32, 32));
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
}

void Render(RenderWindow& window) {
    window.draw(invader);
}

int main() {
    RenderWindow window(VideoMode(gameWidth, gameHeight), "SPACE INVADERS");
    Load();
    while (window.isOpen()) {
        window.clear();
        Update(window);
        Render(window);
        window.display();
    }
    return 0;
}