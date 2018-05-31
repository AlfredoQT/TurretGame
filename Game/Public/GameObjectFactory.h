#pragma once

#include "Singleton.h"

class World;
class GameObject;
struct Vector2;
enum class BatteryControl : int;

class GameObjectFactory : public Singleton<GameObjectFactory>
{
public:

	GameObjectFactory();

	GameObject* CreateMissile(World* pWorld);
	GameObject* CreateMissile(World* pWorld, const Vector2& pPosition);
	GameObject* CreateBattery(World* pWorld, const Vector2& pPosition, BatteryControl control);
	GameObject* CreateFriendlyTarget(World* pWorld, const Vector2& pPosition);
	GameObject* CreateExplosion(World* pWorld, const Vector2& pPosition);
	GameObject* CreateGameManager(World* pWorld);

private:

	int mNextMissile;
	int mNextCity;
	int mNextExplosion;
	int mNextBattery;
	int mNextFriendlyTarget;
};
