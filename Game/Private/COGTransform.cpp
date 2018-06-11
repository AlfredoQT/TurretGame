#include "..\Public\COGTransform.h"

COGTransform::COGTransform(GameObject* pGO)
	: Component(pGO)
{
}

Vector2& COGTransform::GetPosition()
{
	return mPosition;
}
