#pragma once

#include "Component.h"

class GameObject;

class COGGameManager : public Component
{
public:


	static COGGameManager* mGameManagerComponent;
	
	COGGameManager(GameObject* pGO);

	virtual void Initialize() override;

	void Update();

};
	