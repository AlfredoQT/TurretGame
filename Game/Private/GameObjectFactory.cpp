#include "..\Public\GameObjectFactory.h"
#include "..\Public\COG\COGCircleShape.h"
#include "..\Public\COG\COGLineShape.h"
#include "..\Public\COG\COGFSM.h"
#include "..\Public\COG\COGTurret.h"
#include "..\Public\COG\COGPhysics.h"
#include "..\Public\World.h"
#include "..\Public\GameObject.h"
#include "..\Public\GameObjectHandle.h"
#include "..\Public\Random.h"
#include "..\Public\COG\COGTransform.h"
#include "Engine\Public\Core\Types\Vector2.h"
#include "Engine\Public\Core\Types\Color.h"

// Singleton
GameObjectFactory* Singleton<GameObjectFactory>::mSingleton = nullptr;

GameObjectFactory::GameObjectFactory()
	: mWorld(nullptr)
	, mNextID(-1)
{
}

void GameObjectFactory::SetWorld(World * pWorld)
{
	mWorld = pWorld;
}

GameObject * GameObjectFactory::InstantiateTurret(const Vector2 & pPosition)
{
	// Do nothing if there's no world set
	if (mWorld == nullptr)
	{
		return nullptr;
	}
	GameObject* gameObject = new GameObject(mWorld, std::hash<std::string>{}("Turret" + (++mNextID) + std::to_string(Random::Instance()->NextFloat())));

	COGTransform* transform = new COGTransform(gameObject);
	transform->GetPosition() = pPosition;
	gameObject->AddComponent(transform); // Maybe I should add the component in the component constructor?

	// Turret color
	Color white = Color(255, 255, 255);

	COGLineShape* lineShape = new COGLineShape(gameObject);
	lineShape->SetColor(white);
	gameObject->AddComponent(lineShape);

	COGCircleShape* circleShape = new COGCircleShape(gameObject);
	circleShape->SetColor(white);
	circleShape->SetRadius(30.0f);
	gameObject->AddComponent(circleShape);

	// We are going to need this for checking collisions with this guy
	COGPhysics* physics = new COGPhysics(gameObject);
	physics->SetGenerateCollisionEvents(true);
	physics->GetRadius() = 30.0f;
	gameObject->AddComponent(physics);

	// The finite state machine
	COGFSM* fsm = new COGFSM(gameObject);
	gameObject->AddComponent(fsm);

	// The main one
	COGTurret* turret = new COGTurret(gameObject);
	gameObject->AddComponent(turret);

	// Store the handle
	mWorld->Add(gameObject->GetHandle());

	// Init the object
	gameObject->Initialize();

	return gameObject;
}

GameObject * GameObjectFactory:: InstantiateBullet(const Vector2 & pOrigin, const Vector2 & pDir, const float & pSpeed)
{
	// Do nothing if there's no world set
	if (mWorld == nullptr)
	{
		return nullptr;
	}
	GameObject* gameObject = new GameObject(mWorld, std::hash<std::string>{}("Turret" + (++mNextID) + std::to_string(Random::Instance()->NextFloat())));

	COGTransform* transform = new COGTransform(gameObject);
	transform->GetPosition() = pOrigin;
	gameObject->AddComponent(transform); // Maybe I should add the component in the component constructor?

										 // Turret color
	Color white = Color(255, 255, 255);

	COGCircleShape* circleShape = new COGCircleShape(gameObject);
	circleShape->SetColor(white);
	circleShape->SetRadius(7.0f);
	gameObject->AddComponent(circleShape);

	// We are going to need this for checking collisions with this guy
	COGPhysics* physics = new COGPhysics(gameObject);
	physics->SetGenerateCollisionEvents(true);
	physics->GetRadius() = 7.0f;
	physics->GetVelocity() = Vector2(pDir.x, pDir.y) * pSpeed;
	gameObject->AddComponent(physics);

	// Store the handle
	mWorld->Add(gameObject->GetHandle());

	// Init the object
	gameObject->Initialize();

	return gameObject;
}
