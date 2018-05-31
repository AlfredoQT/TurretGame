#pragma once

#include "Component.h"
#include <vector>

class GameObject;
class COGTransform;

// For now, just a circle collider
class COGCollider : public Component
{
public:

	static std::vector<COGCollider*> mColliderComponents;

	COGCollider(GameObject* pGO);

	virtual void Initialize() override;
	virtual void Destroy() override;

	virtual void CheckCollision();

	float GetRadius();
	void SetRadius(const float& pRadius);

	const COGTransform* GetTransform() const;

private:

	float mRadius;

	COGTransform* mTrans;
};
