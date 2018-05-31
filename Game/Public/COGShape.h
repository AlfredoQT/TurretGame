#pragma once

#include "Component.h"
#include "Engine\Public\Core\Types\Color.h"
#include <vector>

class GameObject;
class COGTransform;

class COGShape : public Component
{
public:

	static std::vector<COGShape*> mShapeComponents;

	COGShape(GameObject* pGO);

	virtual void Initialize() override;
	virtual void Destroy() override;

	void SetColor(const Color& pColor);

	virtual void Render() = 0;

protected:

	COGTransform* mTrans;
	Color mColor;
};
