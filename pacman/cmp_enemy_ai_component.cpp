#pragma once
#include "cmp_enemy_ai_component.h"
#include "system_renderer.h"

using namespace sf;

void EnemyAIComponent::update(double dt) {
    float horizontalDirection = 0.0f;
    float verticalDirection = 0.0f;
    int temp1 = rand() % 1;
    int temp2 = rand() % 1;
    if (temp1 == 0) {
        horizontalDirection--;
    }
    else {
        horizontalDirection++;
    }
    if (temp2 == 0) {
        verticalDirection--;
    }
    else {
        verticalDirection++;
    }
    move(Vector2f(horizontalDirection * _speed * dt, verticalDirection * _speed * dt));
}

EnemyAIComponent::EnemyAIComponent(Entity* p) : ActorMovementComponent(p) {}