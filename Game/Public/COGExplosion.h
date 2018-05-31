#pragma once

#include "Component.h"
#include <vector>

class COGLifeSpan;
class COGCircleShape;
class COGCollider;

class COGExplosion : public Component
{
public:

	COGExplosion(GameObject* pGO);

	static std::vector<COGExplosion*> mExpComponents;

	void Update();

	virtual void Initialize() override;
	virtual void Destroy() override;

private:

	COGCircleShape* mShape;
	COGLifeSpan* mLife;
	COGCollider* mCol;
};
