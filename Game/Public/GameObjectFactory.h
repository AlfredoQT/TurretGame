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

	// All gameobjects have a transform
	GameObject* InstantiateTurret(const Vector2& pPosition);

private:

	int mNextID;
	World* mWorld;
};
