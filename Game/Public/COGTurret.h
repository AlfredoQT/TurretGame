#pragma once

#include "Component.h"

class COGFSM;
class GameObject;

class COGTurret : public Component
{
public:

	COGTurret(GameObject* pGO);

	// Just in case I want many
	static std::vector<COGTurret*> turretComponents;

	virtual void Initialize() override;
	virtual void Destroy() override;

	// This should be called every frame
	virtual void Update();

	// This will be modified by each state
	void SetWeaponIndex(int newWeapon);

private:

	// The state machine of the turret
	COGFSM* mFSM;

	// This thing will dictate the state of the turret
	int mCurrentWeapon;

};