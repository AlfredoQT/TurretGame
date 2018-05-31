#include "..\Public\COGGameManager.h"
#include "Game\Public\GameObject.h"
#include "Game\Public\GameObjectFactory.h"
#include "Game\Public\COGBattery.h"
#include "Game\Public\COGMissile.h"

COGGameManager* COGGameManager::mGameManagerComponent = nullptr;

COGGameManager::COGGameManager(GameObject * pGO)
	: Component(pGO)
{
	if (mGameManagerComponent != nullptr)
	{
		delete pGO;
	}
	else
	{
		mGameManagerComponent = this;
	}
}

void COGGameManager::Initialize()
{
	// The batteries
	GameObjectFactory::Instance()->CreateBattery(mGO->GetWorld(), Vector2(45.0f, 600.0f - 60.0f), BatteryControl::ONE);
	GameObjectFactory::Instance()->CreateBattery(mGO->GetWorld(), Vector2(400.0f, 600.0f - 60.0f), BatteryControl::TWO);
	GameObjectFactory::Instance()->CreateBattery(mGO->GetWorld(), Vector2(755.0f, 600.0f - 60.0f), BatteryControl::THREE);
}

void COGGameManager::Update()
{
}
