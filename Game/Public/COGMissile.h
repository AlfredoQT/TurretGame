#pragma once

#include "Component.h"
#include "Engine\Public\Core\Types\Vector2.h"
#include "Engine\Public\Core\Types\Color.h"
#include <vector>

class GameObject;
class COGPhysics;
class COGLineRenderer;
class COGTransform;

class COGMissile : public Component
{
public:

	COGMissile(GameObject* pGO);

	static std::vector<COGMissile*> mMisComponents;

	virtual void Initialize() override;
	virtual void Destroy() override;

	void Update();

	void Launch(Vector2 pTarget, const float& pSpeed);

	void SetColor(const Color& pColor);

	bool Launched() const;

	virtual void OnCollision(COGCollider* other) override;

private:

	void DrawIdle();

	COGPhysics* mPhysics;
	COGLineRenderer* mLR;
	COGTransform* mTrans;

	bool mLaunched;

	Vector2 mTarget;

	Color mColor;

	float mSpeed;

};
