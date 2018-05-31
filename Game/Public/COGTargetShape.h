#pragma once

#include "COGShape.h"

class COGTargetShape : public COGShape
{
public:

	COGTargetShape(GameObject* pGO);

	virtual void Render() override;

	virtual void OnCollision(COGCollider* other) override;

private:

	bool mGeneratedExplosion;

};
