#include "game.h"
#include "ship.h"
#include "bullet.h"
using namespace sf;
using namespace std;

Ship::Ship() {};

bool Invader::direction;
float Invader::speed;

float Player::speed;

Ship::Ship(IntRect ir) : Sprite() {
	_sprite = ir;
	setTexture(spritesheet);
	setTextureRect(_sprite);
};

void Ship::Update(const float& dt) {}

bool Ship::is_exploded() const {
    return _exploded;
}

void Ship::Explode() {
    setTextureRect(IntRect(128, 32, 32, 32));
    _exploded = true;
}

//Define the ship deconstructor. 
//Although we set this to pure virtual, we still have to define it.
Ship::~Ship() = default;

Invader::Invader() : Ship() {}

Invader::Invader(sf::IntRect ir, sf::Vector2f pos) : Ship(ir) {
	setOrigin(16, 16);
	setPosition(pos);
}

void Invader::Update(const float& dt) {
	Ship::Update(dt);

    static float firetime = 0.0f;
    firetime -= dt;

    move(dt * (direction ? 1.0f : -1.0f) * speed, 0);

    if ((direction && getPosition().x > gameWidth - 16) ||
        (!direction && getPosition().x < 16)) {
        direction = !direction;
        for (int i = 1; i < ships.size(); ++i) {
            ships[i]->move(0, 24);
        }
    } 
    if (firetime <= 0 && rand() % 100 == 0) {
        Bullet::Fire(getPosition(), true);
        firetime = 4.0f + (rand() % 60);
    }
}

Player::Player() : Ship(IntRect(160, 32, 32, 32)) {
    setOrigin(16, 16);
    setPosition({ gameWidth * .5f, gameHeight - 8.f });
}

void Player::Update(const float& dt) {
    Ship::Update(dt);
    float direction = 0.0f;
    static float firetime = 0.0f;
    firetime -= dt;
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        direction--;
    }
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        direction++;
    }
    move(direction * speed * dt, 0);
    if (firetime <= 0 && Keyboard::isKeyPressed(Keyboard::Up)) {
        Bullet::Fire(getPosition(), false);
        firetime = 0.7f;
    }
}