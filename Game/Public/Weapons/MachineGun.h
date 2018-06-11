#pragma once

#include "IWeapon.h"

struct Vector2;

class MachineGun : public IWeapon
{
public:

	virtual std::string Type() const override;

	virtual void Shoot(const Vector2& origin) override;

};
