#pragma once

#include "Singleton.h"

class World;
class GameObject;
struct Vector2;

// A library of methods to create game objects
class GameObjectFactory : public Singleton<GameObjectFactory>
{
public:

	GameObjectFactory();

	void SetWorld(World* pWorld);

	// The main guy right here
	GameObject* InstantiateTurret(const Vector2& pPosition);

	GameObject* InstantiateBullet(const Vector2& pOrigin, const Vector2& pDir, const float& pSpeed);

private:

	int mNextID;
	World* mWorld;
};
