#include "..\Public\COGBoxShape.h"
#include "Game\Public\GameObject.h"
#include "Engine\Public\Engine.h"
#include "Game\Public\World.h"
#include "Game\Public\COGTransform.h"

COGBoxShape::COGBoxShape(GameObject * pGO)
	: COGShape(pGO)
	, mWidth(0.0f)
	, mHeight(0.0f)
{
}

void COGBoxShape::Render()
{
	Vector2 topLeft = Vector2(mTrans->GetPosition().x - mWidth / 2.0f, mTrans->GetPosition().y - mHeight / 2.0f);
	Vector2 bottomRight = Vector2(mTrans->GetPosition().x + mWidth / 2.0f, mTrans->GetPosition().y + mHeight / 2.0f);
	mGO->GetWorld()->GetEngine()->DrawRect(topLeft, bottomRight, mColor);
}

void COGBoxShape::SetWidth(const float & pWidth)
{
	mWidth = pWidth;
}

void COGBoxShape::SetHeight(const float & pHeight)
{
	mHeight = pHeight;
}
