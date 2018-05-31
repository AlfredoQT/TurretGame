#include "..\Public\MissileCommandGame.h"
#include "Engine\Public\Engine.h"
#include "Game\Public\InputManager.h"
#include "Game\Public\World.h"
#include "Game\Public\GameObjectFactory.h"

MissileCommandGame::MissileCommandGame()
	: mWorld(nullptr)
{
}

void MissileCommandGame::Init(Engine* pEngine)
{
	mWorld = new World(pEngine);
	GameObjectFactory::Instance()->CreateGameManager(mWorld);
}

void MissileCommandGame::Run()
{
	InputManager::Instance()->Update();

	mWorld->Update();

	InputManager::Instance()->LateUpdate();

	mWorld->FreeMemory();
}

void MissileCommandGame::End()
{
	mWorld->Destroy();
}
