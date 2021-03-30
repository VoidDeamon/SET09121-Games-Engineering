#pragma once
#include "entity.h"

class Ghost : public Entity {
private:
	float _speed;

public:
	void Update(double dt) override;
	Ghost();
	void Render() const override;
};