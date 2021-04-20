#pragma once
#include "ecm.h"

class PickupComponent : public Component {
public:
    explicit PickupComponent(Entity* p);
    PickupComponent() = delete;

    void update(double dt) override;
};