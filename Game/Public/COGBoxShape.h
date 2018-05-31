#pragma once

#include "COGShape.h"

class COGBoxShape : public COGShape
{
public:

	COGBoxShape(GameObject* pGO);

	virtual void Render() override;

	void SetWidth(const float& pWidth);
	void SetHeight(const float& pHeight);

private:

	float mWidth;
	float mHeight;

};
