#include "player.h"
using namespace sf;
using namespace std;

void Player::Update(double dt) {
    //Move in four directions based on keys
    float horizontalDirection = 0.0f;
    float verticalDirection = 0.0f;
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        horizontalDirection--;
    }
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        horizontalDirection++;
    }
    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        verticalDirection--;
    }
    if (Keyboard::isKeyPressed(Keyboard::Down)) {
        verticalDirection++;
    }
    move(Vector2f(horizontalDirection * _speed * dt, verticalDirection * _speed * dt));

        Entity::Update(dt);
}

Player::Player()
    : _speed(200.0f), Entity(make_unique<CircleShape>(25.f)) {
    _shape->setFillColor(Color::Magenta);
    _shape->setOrigin(Vector2f(25.f, 25.f));
}

void Player::Render(sf::RenderWindow& window) const {
    window.draw(*_shape);
}