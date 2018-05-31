#pragma once

#include "Component.h"
#include "Input.h"
#include <vector>

enum class BatteryControl : int
{
	ONE = 0,
	TWO,
	THREE
};

class GameObject;
class GameObjectHandle;
class COGMissile;

class COGBattery : public Component
{
public:

	COGBattery(GameObject* pGO);

	static std::vector<COGBattery*> mBatComponents;

	virtual void Initialize() override;
	virtual void Destroy() override;

	std::vector<GameObjectHandle> mMissiles;

	void ListenForCharge();

	void SetControl(BatteryControl pControl);

	void AddMissile(GameObjectHandle pHandle);

private:

	COGMissile * FindMissileInHandles();

	KeyCode mShootInput;

};
