#pragma once

struct Vector2;

// Just a simple interface for the weapons of the turret
class IWeapon
{
	virtual void Shoot(const Vector2& origin) = 0;
};
