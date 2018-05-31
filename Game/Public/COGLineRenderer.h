#pragma once

#include "Component.h"
#include "Engine\Public\Core\Types\Color.h"
#include "Engine\Public\Core\Types\Vector2.h"
#include <vector>

class GameObject;

class COGLineRenderer : public Component
{
public:

	COGLineRenderer(GameObject* pGO);

	static std::vector<COGLineRenderer*> mLRComponents;

	virtual void Initialize() override;
	virtual void Destroy() override;

	void Draw() const;

	void SetColor(const Color& pColor);

	void AddPoint(const Vector2& pPoint);

	void SetPoint(int pIndex, const Vector2& pPoint);

	std::vector<Vector2> GetPoints();

private:

	std::vector<Vector2> mPoints;
	Color mColor;

};
