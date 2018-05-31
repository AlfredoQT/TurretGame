#pragma once

#include "Engine\Public\Core\Types\Vector2.h"
#include "Component.h"

class GameObject;

class COGTransform : public Component
{
public:

	COGTransform(GameObject* pGO);

	Vector2 GetPosition() const;
	void SetPosition(const Vector2& pPosition);

private:

	Vector2 mPosition;

};
