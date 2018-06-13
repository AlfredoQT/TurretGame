#pragma once

#include "Component.h"

class GameObject;
class COGTransform;

class COGEnemySpawner : public Component
{
public:

	static COGEnemySpawner* spawnerComponent;

	COGEnemySpawner(GameObject* pGO);

	virtual void Initialize() override;

	void SpawnEnemies();

	void SetTarget(COGTransform* pTarget);

private:

	// This time will be randomized
	float mTimeBetweenSpawns;

	// The timer for the next spawn
	float mTimeForNextSpawn;

	// The target
	COGTransform* mTarget;
};
