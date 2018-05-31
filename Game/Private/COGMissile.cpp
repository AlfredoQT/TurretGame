#include "..\Public\COGMissile.h"
#include "Game\Public\COGLineRenderer.h"
#include "Game\Public\GameObject.h"
#include "Game\Public\World.h"
#include "Engine\Public\Engine.h"
#include "Game\Public\COGPhysics.h"
#include "Game\Public\COGTransform.h"
#include "Game\Public\COGCollider.h"
#include "Engine\Public\Utils\Debug.h"
#include "Game\Public\GameObjectHandle.h"

std::vector<COGMissile*> COGMissile::mMisComponents;

COGMissile::COGMissile(GameObject * pGO)
	: Component(pGO)
{
}

void COGMissile::Initialize()
{
	mLR = mGO->FindComponent<COGLineRenderer>();
	mPhysics = mGO->FindComponent<COGPhysics>();
	mTrans = mGO->FindComponent<COGTransform>();
	mLaunched = false;
	AddToComponentVector(mMisComponents);
}

void COGMissile::Destroy()
{
	RemoveFromComponentVector(mMisComponents);
}

void COGMissile::Update()
{
	if (!mLaunched)
	{
		DrawIdle();
		return;
	}
	// Set the end position of the line renderer
	mLR->SetPoint(1, mTrans->GetPosition());
}

void COGMissile::Launch(Vector2 pTarget, const float& pSpeed)
{
	mLaunched = true;
	mTarget = pTarget;
	mSpeed = pSpeed;

	// Add the points to the line renderer
	mLR->AddPoint(mTrans->GetPosition());
	mLR->AddPoint(mTrans->GetPosition());

	// Set the velocity
	mPhysics->SetVelocity((pTarget - mTrans->GetPosition()).Normalized() * pSpeed);
}

void COGMissile::SetColor(const Color & pColor)
{
	mColor = pColor;
	mLR->SetColor(pColor);
}

bool COGMissile::Launched() const
{
	return mLaunched;
}

void COGMissile::OnCollision(COGCollider * other)
{
	if (other->GetOwner()->GetTag().compare("FT") == 0)
	{
		mGO->GetWorld()->Delete(mGO->GetHandle());
	}
}

void COGMissile::DrawIdle()
{
	// Kind of like an inverted y
	mGO->GetWorld()->GetEngine()->DrawLine(mTrans->GetPosition(), Vector2(mTrans->GetPosition().x, mTrans->GetPosition().y - 4), mColor);
	mGO->GetWorld()->GetEngine()->DrawLine(mTrans->GetPosition(), Vector2(mTrans->GetPosition().x - 3, mTrans->GetPosition().y + 4), mColor);
	mGO->GetWorld()->GetEngine()->DrawLine(mTrans->GetPosition(), Vector2(mTrans->GetPosition().x + 3, mTrans->GetPosition().y + 4), mColor);
}
