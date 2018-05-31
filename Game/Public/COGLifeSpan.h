#pragma once

#include "Component.h"
#include <vector>

class COGLifeSpan : public Component
{
public:

	COGLifeSpan(GameObject* pGO);

	static std::vector<COGLifeSpan*> mLSComponents;

	void SetTimeLeft(const float& pTimeLeft);

	void Update();

	float GetTimeLeft() const;
	float GetDuration() const;

	virtual void Initialize() override;
	virtual void Destroy() override;

private:

	float mDuration;
	float mTimeLeft;
};
