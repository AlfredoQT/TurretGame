#include "..\Public\World.h"
#include "..\Public\GameObject.h"
#include "..\Public\GameObjectHandle.h"
#include "Engine\Public\Engine.h"
#include "Game\Public\COG\COGFSM.h"
#include "Game\Public\COG\COGPhysics.h"
#include "Game\Public\COG\COGTurret.h"
#include "Game\Public\COG\COGShape.h"
#include "Game\Public\COG\COGGameUI.h"
#include "Game\Public\COG\COGEnemySpawner.h"

World::World(Engine* pEngine)
{
	mEngine = pEngine;
	mGameManager = nullptr;
}

void World::Destroy()
{
	for (GameObjectHandle handle : mHandles)
	{
		if (handle.IsValid())
		{
			delete handle.Get();
		}
	}

	mHandles.clear();
}

void World::Update()
{
	// Physics
	for (COGPhysics* physics : COGPhysics::physicsComponents)
	{
		if (physics != nullptr)
		{
			physics->Simulate();
		}
	}
	// Rendering
	for (COGShape* shape : COGShape::shapeComponents)
	{
		if (shape != nullptr)
		{
			shape->Render();
		}
	}
	// Tell the FSMs to update
	for (COGFSM* fsm : COGFSM::fsmComponents)
	{
		if (fsm != nullptr)
		{
			fsm->Update();
		}
	}
	// Update the turret(s, most likely no)
	for (COGTurret* turret : COGTurret::turretComponents)
	{
		turret->Update();
	}
	// The spawner
	if (COGEnemySpawner::spawnerComponent != nullptr)
	{
		COGEnemySpawner::spawnerComponent->SpawnEnemies();
	}
	// Update the UI
	if (COGGameUI::gameUIComponent != nullptr)
	{
		COGGameUI::gameUIComponent->ShowUI();
	}
}

void World::Add(GameObjectHandle pHandle)
{
	mHandles.push_back(pHandle);
}

void World::Delete(GameObjectHandle pHandle)
{
	mHandlesToDelete.push_back(pHandle);
}

void World::FreeMemory()
{
	for (std::size_t i = 0; i < mHandlesToDelete.size(); ++i)
	{
		if (mHandlesToDelete[i].IsValid())
		{
			GameObject* gameObject = mHandlesToDelete[i].Get();
			delete gameObject;
			gameObject = nullptr;
		}
	}
	mHandlesToDelete.clear();
}

std::vector<GameObjectHandle> World::GetHandles()
{
	return mHandles;
}

Engine* World::GetEngine() const
{
	return mEngine;
}
