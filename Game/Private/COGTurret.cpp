#include "..\Public\COGTurret.h"
#include "..\Public\GameObject.h"

COGTurret::COGTurret(GameObject * pGO)
	: Component(pGO)
{
}

void COGTurret::Initialize()
{
	mFSM = mGO->FindComponent<COGFSM>();
	AddToComponentVector(turretComponents);
}

void COGTurret::Destroy()
{
	RemoveFromComponentVector(turretComponents);
}

void COGTurret::Update()
{
}

void COGTurret::SetWeaponIndex(int newWeapon)
{
	mCurrentWeapon = newWeapon;
}
