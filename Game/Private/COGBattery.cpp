#include "..\Public\COGBattery.h"
#include "Game\Public\COGMissile.h"
#include "Game\Public\GameObjectHandle.h"
#include "Game\Public\GameObject.h"
#include "Game\Public\GameObjectFactory.h"
#include "Game\Public\World.h"

std::vector<COGBattery*> COGBattery::mBatComponents;

void COGBattery::ListenForCharge()
{
	if (Input::Instance()->IsKeyPressed(mShootInput))
	{
		COGMissile* missile = FindMissileInHandles();
		// Launch if it's not been launched
		if (missile != nullptr)
		{
			GameObjectFactory::Instance()->CreateFriendlyTarget(mGO->GetWorld(), Input::Instance()->GetMousePosition());
			missile->Launch(Input::Instance()->GetMousePosition(), 50.0f);
		}
	}
}

COGBattery::COGBattery(GameObject * pGO)
	: Component(pGO)
{
}

void COGBattery::Initialize()
{
	AddToComponentVector(mBatComponents);
}


void COGBattery::Destroy()
{
	RemoveFromComponentVector(mBatComponents);
}

void COGBattery::SetControl(BatteryControl pControl)
{
	switch (pControl)
	{
	case BatteryControl::ONE:
		mShootInput = KeyCode::Alpha1;
		break;
	case BatteryControl::TWO:
		mShootInput = KeyCode::Alpha2;
		break;
	case BatteryControl::THREE:
		mShootInput = KeyCode::Alpha3;
		break;
	default:
		break;
	}
}

void COGBattery::AddMissile(GameObjectHandle pHandle)
{
	mMissiles.push_back(pHandle);
}

COGMissile* COGBattery::FindMissileInHandles()
{
	for (std::size_t i = 0; i < mMissiles.size(); ++i)
	{
		// This shit is so powerful
		if (mMissiles[i].IsValid())
		{
			COGMissile* missile = mMissiles[i].Get()->FindComponent<COGMissile>();
			// Found
			if (missile != nullptr && !missile->Launched())
			{
				return missile;
			}
		}
	}
	return nullptr;
}
