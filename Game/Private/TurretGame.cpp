#include "..\Public\TurretGame.h"
#include "Engine\Public\Engine.h"
#include "Game\Public\InputManager.h"
#include "Game\Public\World.h"
#include "Game\Public\GameObjectFactory.h"
#include "Engine\Public\Core\Types\Vector2.h"

TurretGame::TurretGame()
	: mWorld(nullptr)
{
}

void TurretGame::Init(Engine* pEngine)
{
	mWorld = new World(pEngine);
	GameObjectFactory::Instance()->SetWorld(mWorld);
	
	// Add the turret
	GameObjectFactory::Instance()->InstantiateTurret(Vector2(50.0f, 300.0f));
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
	GameObjectFactory::DestroyInstance();
}
