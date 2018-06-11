#pragma once

#include <string>

struct Vector2;

// Just a simple interface for the weapons of the turret
class IWeapon
{
public:

	virtual std::string Type() const = 0;

	virtual void Shoot(const Vector2& origin) = 0;
};
