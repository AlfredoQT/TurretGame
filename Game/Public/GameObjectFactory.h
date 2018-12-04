#pragma once

#include "Singleton.h"
#include "Engine\Public\Core\Types\Color.h"
#include <string>

class World;
class GameObject;
struct Vector2;
struct Color;
class GameObjectHandle;

// A library of methods to create game objects
class GameObjectFactory : public Singleton<GameObjectFactory>
{
public:

	GameObjectFactory();

	void SetWorld(World* pWorld);

	// The main guy right here
	GameObject* InstantiateTurret(const Vector2& pPosition);

	GameObject* InstantiateBullet(const Vector2& pOrigin, const Vector2& pDir, const float& pSpeed, const std::string& pTag, const std::string& pTargetTag, const Color& color = Color(255,255,255));

	// I guess there's a more elegant way to pass the turret, but since I'm initalizing the game objects in here, this is the best for now
	// Although I should move the initialize the world
	GameObject* InstantiateUI(const GameObjectHandle& pTurret);

	GameObject* InstantiateEnemySpawner(const GameObjectHandle& pTarget);

private:

	int mNextID;
	World* mWorld;
};
