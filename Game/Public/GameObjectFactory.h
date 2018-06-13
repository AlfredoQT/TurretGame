#pragma once

#include "Singleton.h"

class World;
class GameObject;
struct Vector2;
class COGTurret;
class COGTransform;

// A library of methods to create game objects
class GameObjectFactory : public Singleton<GameObjectFactory>
{
public:

	GameObjectFactory();

	void SetWorld(World* pWorld);

	// The main guy right here
	GameObject* InstantiateTurret(const Vector2& pPosition);

	GameObject* InstantiateBullet(const Vector2& pOrigin, const Vector2& pDir, const float& pSpeed);

	// I guess there's a more elegant way to pass the turret, but since I'm initalizing the game objects in here, this is the best for now
	// Although I should move the initialize the world
	GameObject* InstantiateUI(COGTurret* pTurret);

	GameObject* InstantiateEnemySpawner(COGTransform* pTarget);

private:

	int mNextID;
	World* mWorld;
};
