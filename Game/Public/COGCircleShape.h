#pragma once

#include "COGShape.h"

class COGCircleShape : public COGShape
{
public:

	COGCircleShape(GameObject* pGO);

	virtual void Render() override;

	void SetRadius(const float& pRadius);

private:

	float mRadius;

};
