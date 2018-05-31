#include "..\Public\COGExplosion.h"
#include "Game\Public\COGLifeSpan.h"
#include "Game\Public\COGCircleShape.h"
#include "Game\Public\World.h"
#include "Game\Public\GameObject.h"
#include "Engine\Public\Engine.h"
#include "Engine\Public\Core\Types\Color.h"
#include "Game\Public\Random.h"
#include "Game\Public\COGCollider.h"
#include "Game\Public\Crossfade.h"

std::vector<COGExplosion*> COGExplosion::mExpComponents;

COGExplosion::COGExplosion(GameObject * pGO)
	: Component(pGO)
{
}

void COGExplosion::Update()
{
	mShape->SetColor(Color(Random::Instance()->NextInt(200, 255), Random::Instance()->NextInt(200, 255), Random::Instance()->NextInt(200, 255)));
	float radius = Crossfade::Mix(Crossfade::Arch2, Crossfade::Arch2, mLife->GetTimeLeft() / mLife->GetDuration())  * (25.0f - 8.0f) + 8.0f;
	mShape->SetRadius(radius);
	mCol->SetRadius(radius);
}

void COGExplosion::Initialize()
{
	mLife = mGO->FindComponent<COGLifeSpan>();
	mShape = mGO->FindComponent<COGCircleShape>();
	mCol = mGO->FindComponent<COGCollider>();
	AddToComponentVector(mExpComponents);
}

void COGExplosion::Destroy()
{
	RemoveFromComponentVector(mExpComponents);
}
