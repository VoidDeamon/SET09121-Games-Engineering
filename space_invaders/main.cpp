#include <SFML/Graphics.hpp>
#include <iostream>
#include "ship.h"
#include "bullet.h"

using namespace sf;
using namespace std;

const int gameWidth = 800;
const int gameHeight = 600;
sf::Texture spritesheet;
sf::Sprite invader;
std::vector<Ship*> ships;
Ship* player;

int invader_rows = 25;
int invader_columns = 5;

void Load() {
    if (!spritesheet.loadFromFile("res/img/invaders_sheet.png")) {
        cerr << "Failed to load spritesheet!" << std::endl;
    }
    invader.setTexture(spritesheet);
    invader.setTextureRect(sf::IntRect(0, 0, 32, 32));

    Invader::speed = 20.0f;
    Player::speed = 40.0f;

    auto pla = new Player();
    ships.push_back(pla);
    player = pla;
    for (int r = 0; r < invader_rows; ++r) {
        auto rect = IntRect(0, 0, 32, 32);
        for (int c = 0; c < invader_columns; ++c) {
            Vector2f position = Vector2f(25.0f * r, 25.0f * c);
            auto inv = new Invader(rect, position);
            ships.push_back(inv);
        }
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
    for (auto& s : ships) {
        s->Update(dt);
    };
    Bullet::Update(dt);
}

void Render(RenderWindow& window) {
    for (const auto s : ships) {
        window.draw(*s);
    }
    Bullet::Render(window);
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