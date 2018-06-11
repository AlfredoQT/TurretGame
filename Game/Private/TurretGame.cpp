#include "..\Public\TurretGame.h"
#include "Engine\Public\Engine.h"
#include "Game\Public\InputManager.h"
#include "Game\Public\World.h"

TurretGame::TurretGame()
	: mWorld(nullptr)
{
}

void TurretGame::Init(Engine* pEngine)
{
	mWorld = new World(pEngine);
}

void TurretGame::Run()
{
	InputManager::Instance()->Update();

	mWorld->Update();

	InputManager::Instance()->LateUpdate();

	mWorld->FreeMemory();
}

void TurretGame::End()
{
	mWorld->Destroy();
}
