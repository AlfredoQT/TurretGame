#include "..\..\Public\COG\COGTurret.h"
#include "..\..\Public\GameObject.h"
#include "..\..\Public\COG\COGFSM.h"
#include "..\..\Public\Weapons\MachineGun.h"
#include "..\..\Public\Weapons\Sniper.h"
#include "..\..\Public\Weapons\Shotgun.h"
#include "..\..\Public\COG\COGTransform.h"
#include "..\..\Public\FSMSniperTurretState.h"

// The components
std::vector<COGTurret*> COGTurret::turretComponents;

COGTurret::COGTurret(GameObject * pGO)
	: Component(pGO)
	, mCurrentWeapon(0)
{
	// This is the default weapon
	mWeapons.push_back(new Sniper());
	mWeapons.push_back(new Shotgun());
	mWeapons.push_back(new MachineGun());
}

void COGTurret::Initialize()
{
	mFSM = mGO->FindComponent<COGFSM>();
	// The initial state
	mFSM->SetInitial(new FSMSniperTurretState(mFSM));
	AddToComponentVector(turretComponents);
}

void COGTurret::Destroy()
{
	RemoveFromComponentVector(turretComponents);
}

void COGTurret::Update()
{
	// Tell the weapon to shoot itself
	mWeapons[mCurrentWeapon]->Shoot(Vector2());
}

void COGTurret::SetWeaponIndex(int newWeapon)
{
	// Set it to the default if it is out of range
	if (newWeapon < 0 || newWeapon >= mWeapons.size())
	{
		mCurrentWeapon = 0;
		return;
	}
	mCurrentWeapon = newWeapon;
}
