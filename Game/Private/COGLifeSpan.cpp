#include "..\Public\COGLifeSpan.h"
#include "Game\Public\GameObject.h"
#include "Game\Public\World.h"
#include "Engine\Public\Core\Time.h"
#include "Game\Public\GameObjectHandle.h"

std::vector<COGLifeSpan*> COGLifeSpan::mLSComponents;

COGLifeSpan::COGLifeSpan(GameObject* pGO)
	: Component(pGO)
	, mTimeLeft(-1.0f)
{
}

void COGLifeSpan::SetTimeLeft(const float & pTimeLeft)
{
	mTimeLeft = pTimeLeft;
	mDuration = pTimeLeft;
}

void COGLifeSpan::Update()
{
	if (mTimeLeft < 0.0f)
	{
		mGO->GetWorld()->Delete(mGO->GetHandle());
	}

	mTimeLeft -= Time::deltaTime;
}

float COGLifeSpan::GetTimeLeft() const
{
	return mTimeLeft;
}

float COGLifeSpan::GetDuration() const
{
	return mDuration;
}

void COGLifeSpan::Initialize()
{
	AddToComponentVector(mLSComponents);
}

void COGLifeSpan::Destroy()
{
	RemoveFromComponentVector(mLSComponents);
}
