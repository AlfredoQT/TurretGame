#include "..\Public\COGTransform.h"

COGTransform::COGTransform(GameObject* pGO)
	: Component(pGO)
{
}

Vector2 COGTransform::GetPosition() const
{
	return mPosition;
}

void COGTransform::SetPosition(const Vector2 & pPosition)
{
	mPosition = pPosition;
}
