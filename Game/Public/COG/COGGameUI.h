#pragma once

#include "Component.h"

class GameObject;
class COGTurret;

class COGGameUI : public Component
{
public:

	static COGGameUI* gameUIComponent;

	COGGameUI(GameObject* pGO);

	virtual void Initialize() override;
	virtual void Destroy() override;

	// We need to have access to the turret component
	void SetTurret(COGTurret* pTurret);
	
	// To draw the stuff
	void ShowUI();

private:

	COGTurret * mTurret;

};
