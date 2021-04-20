#pragma once
#include "cmp_player_movement.h"
#include "system_renderer.h"

using namespace sf;

void PlayerMovementComponent::update(double dt) {
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
}

PlayerMovementComponent::PlayerMovementComponent(Entity* p) : ActorMovementComponent(p) {}