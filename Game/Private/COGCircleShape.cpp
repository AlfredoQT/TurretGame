#include "..\Public\COGCircleShape.h"
#include "Game\Public\GameObject.h"
#include "Engine\Public\Engine.h"
#include "Game\Public\World.h"
#include "Game\Public\COGTransform.h"

COGCircleShape::COGCircleShape(GameObject * pGO)
	: COGShape(pGO)
	, mRadius(0.0f)
{
}

void COGCircleShape::Render()
{
	mGO->GetWorld()->GetEngine()->DrawFillCircle(mTrans->GetPosition(), mRadius, mColor);
}

void COGCircleShape::SetRadius(const float & pRadius)
{
	mRadius = pRadius;
}
