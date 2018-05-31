#include "..\Public\GameObjectFactory.h"
#include "Game\Public\GameObject.h"
#include "Game\Public\World.h"
#include "Game\Public\GameObjectHandle.h"
#include "Game\Public\COGPhysics.h"
#include "Game\Public\COGTransform.h"
#include "Game\Public\COGLineRenderer.h"
#include "Game\Public\COGBattery.h"
#include "Engine\Public\Core\Types\Vector2.h"
#include "Game\Public\COGMissile.h"
#include "Engine\Public\Core\Types\Color.h"
#include "Game\Public\COGBoxShape.h"
#include "Game\Public\COGCircleShape.h"
#include "Game\Public\COGGameManager.h"
#include "Game\Public\COGCollider.h"
#include "Game\Public\Random.h"
#include "Game\Public\COGTargetShape.h"
#include "Game\Public\COGLifeSpan.h"
#include "Game\Public\COGExplosion.h"
#include <string>

// Singleton
GameObjectFactory* Singleton<GameObjectFactory>::mSingleton = nullptr;

GameObjectFactory::GameObjectFactory()
	: mNextMissile(-1)
	, mNextCity(-1)
	, mNextExplosion(-1)
	, mNextBattery(-1)
	, mNextFriendlyTarget(-1)
{
}

GameObject* GameObjectFactory::CreateMissile(World* pWorld)
{
	GameObject* missile = new GameObject(pWorld, std::hash<std::string>{}("Mi-" + (++mNextMissile) + std::to_string(Random::Instance()->NextFloat())));
	missile->AddComponent(new COGTransform(missile));
	missile->AddComponent(new COGPhysics(missile));
	missile->AddComponent(new COGLineRenderer(missile));
	missile->AddComponent(new COGMissile(missile));

	COGCollider* collider = new COGCollider(missile);
	collider->SetRadius(7.0f);

	missile->AddComponent(collider);

	pWorld->Add(missile->GetHandle());

	missile->Initialize();

	return missile;
}

GameObject* GameObjectFactory::CreateMissile(World* pWorld, const Vector2& pPosition)
{
	GameObject* missile = new GameObject(pWorld, std::hash<std::string>{}("Mi-" + (++mNextMissile) + std::to_string(Random::Instance()->NextFloat())));

	COGTransform* transform = new COGTransform(missile);
	transform->SetPosition(pPosition);

	missile->AddComponent(transform);
	missile->AddComponent(new COGPhysics(missile));
	missile->AddComponent(new COGMissile(missile));
	missile->AddComponent(new COGLineRenderer(missile));

	COGCollider* collider = new COGCollider(missile);
	collider->SetRadius(7.0f);

	missile->AddComponent(collider);

	pWorld->Add(missile->GetHandle());

	missile->Initialize();

	return missile;
}

GameObject * GameObjectFactory::CreateBattery(World * pWorld, const Vector2 & pPosition, BatteryControl control)
{
	GameObject* battery = new GameObject(pWorld, std::hash<std::string>{}("Ba-" + (++mNextBattery) + std::to_string(Random::Instance()->NextFloat())));

	COGTransform* transform = new COGTransform(battery);
	transform->SetPosition(pPosition);

	battery->AddComponent(transform);

	COGBattery* cogBattery = new COGBattery(battery);
	cogBattery->SetControl(control);

	battery->AddComponent(cogBattery);

	COGBoxShape* cogBox = new COGBoxShape(battery);
	cogBox->SetWidth(80.0f);
	cogBox->SetHeight(44.0f);

	battery->AddComponent(cogBox);


	// The positions for the missiles
	Vector2 missilePos[10];
	missilePos[0] = Vector2(pPosition.x - 7, pPosition.y - 10);
	missilePos[1] = Vector2(pPosition.x + 7, pPosition.y - 10);
	missilePos[2] = Vector2(pPosition.x, pPosition.y);
	missilePos[3] = Vector2(pPosition.x - 12, pPosition.y);
	missilePos[4] = Vector2(pPosition.x + 12, pPosition.y);
	missilePos[5] = Vector2(pPosition.x - 24, pPosition.y + 10);
	missilePos[6] = Vector2(pPosition.x + 24, pPosition.y + 10);
	missilePos[7] = Vector2(pPosition.x, pPosition.y + 10);
	missilePos[8] = Vector2(pPosition.x - 12, pPosition.y + 10);
	missilePos[9] = Vector2(pPosition.x + 12, pPosition.y + 10);

	// Add the missiles
	for (int i = 0; i < 10; ++i)
	{
		GameObject* missile = CreateMissile(pWorld, missilePos[i]);
		missile->SetTag("FM");

		// Set the color of the missile component
		COGMissile* cogMissile = missile->FindComponent<COGMissile>();
		if (cogMissile != nullptr)
		{
			// I like blue
			cogMissile->SetColor(Color(0, 0, 255));

			// Add the handle to the battery
			cogBattery->AddMissile(missile->GetHandle());
		}
	}

	pWorld->Add(battery->GetHandle());

	battery->Initialize();

	return battery;
}

GameObject * GameObjectFactory::CreateFriendlyTarget(World * pWorld, const Vector2 & pPosition)
{
	GameObject* fT = new GameObject(pWorld, std::hash<std::string>{}("Ft-" + (++mNextFriendlyTarget) + std::to_string(Random::Instance()->NextFloat())));
	COGTransform* transform = new COGTransform(fT);
	transform->SetPosition(pPosition);
	fT->AddComponent(transform);

	COGCollider* collider = new COGCollider(fT);
	collider->SetRadius(7.0f);

	fT->AddComponent(new COGTargetShape(fT));

	fT->AddComponent(collider);

	fT->SetTag("FT");

	pWorld->Add(fT->GetHandle());

	fT->Initialize();

	return fT;
}

GameObject * GameObjectFactory::CreateExplosion(World * pWorld, const Vector2 & pPosition)
{
	GameObject* fT = new GameObject(pWorld, std::hash<std::string>{}("Exp-" + (++mNextExplosion) + std::to_string(Random::Instance()->NextFloat())));
	COGTransform* transform = new COGTransform(fT);
	transform->SetPosition(pPosition);
	fT->AddComponent(transform);

	COGLifeSpan* lfC = new COGLifeSpan(fT);
	lfC->SetTimeLeft(4.0f);

	fT->AddComponent(lfC);

	fT->AddComponent(new COGCollider(fT));

	fT->AddComponent(new COGExplosion(fT));
	
	fT->AddComponent(new COGCircleShape(fT));

	pWorld->Add(fT->GetHandle());

	fT->Initialize();
	return fT;
}

GameObject* GameObjectFactory::CreateGameManager(World* pWorld)
{
	GameObject* gameManager = new GameObject(pWorld, std::hash<std::string>{}("Manager"));

	gameManager->AddComponent(new COGGameManager(gameManager));

	pWorld->Add(gameManager->GetHandle());

	gameManager->Initialize();

	return gameManager;
}
