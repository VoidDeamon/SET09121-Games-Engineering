#pragma once
#include "cmp_actor_movement.h"

class EnemyAIComponent : public ActorMovementComponent {
protected:

public:
    explicit EnemyAIComponent(Entity* p);

    void render() override {};
    void update(double dt) override;
};