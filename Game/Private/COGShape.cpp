#include "..\Public\COGShape.h"
#include "Game\Public\GameObject.h"
#include "Game\Public\COGTransform.h"

std::vector<COGShape*> COGShape::mShapeComponents;

COGShape::COGShape(GameObject * pGO)
	: Component(pGO)
{
}

void COGShape::Initialize()
{
	mTrans = mGO->FindComponent<COGTransform>();
	AddToComponentVector(mShapeComponents);
}

void COGShape::Destroy()
{
	RemoveFromComponentVector(mShapeComponents);
}

void COGShape::SetColor(const Color & pColor)
{
	mColor = pColor;
}
