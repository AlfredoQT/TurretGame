#include "..\Public\World.h"
#include "..\Public\GameObject.h"
#include "Game\Public\GameObjectHandle.h"
#include "Engine\Public\Engine.h"

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
			delete mHandlesToDelete[i].Get();
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

void World::SetGameManager(COGGameManager * pGameManager)
{
	mGameManager = pGameManager;
}
