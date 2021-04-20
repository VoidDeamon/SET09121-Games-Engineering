#pragma once
#include "cmp_actor_movement.h"

class PlayerMovementComponent : public ActorMovementComponent {
protected:

public:
    explicit PlayerMovementComponent(Entity* p);

    void render() override {};
    void update(double dt) override;
};