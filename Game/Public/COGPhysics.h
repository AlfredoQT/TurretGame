#pragma once

#include "Component.h"
#include "Engine\Public\Core\Types\Vector2.h"
#include <vector>

class GameObject;
class COGTransform;

class COGPhysics : public Component
{
public:

	static std::vector<COGPhysics*> mPhysicsComponents;

	COGPhysics(GameObject* pGO);

	virtual void Initialize() override;

	virtual void Destroy() override;

	Vector2 GetVelocity() const;
	void SetVelocity(const Vector2& pVelocity);

	void Update();

private:

	Vector2 mVelocity;

	COGTransform* mTransform;

};
