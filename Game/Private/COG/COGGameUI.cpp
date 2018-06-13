#include "..\..\Public\COG\COGGameUI.h"
#include "Game\Public\COG\COGTurret.h"
#include "Engine\Public\Engine.h"
#include "Game\Public\GameObject.h"
#include "Game\Public\World.h"
#include "Game\Public\Weapons\IWeapon.h"
#include "Engine\Public\Core\Types\Color.h"
#include "Engine\Public\Core\Types\Vector2.h"

COGGameUI* COGGameUI::gameUIComponent = nullptr;

COGGameUI::COGGameUI(GameObject* pGO)
	: Component(pGO)
{
}

void COGGameUI::Initialize()
{
	// Set the static variable
	gameUIComponent = this;
}

void COGGameUI::Destroy()
{
}

void COGGameUI::SetTurret(COGTurret* pTurret)
{
	mTurret = pTurret;
}

void COGGameUI::ShowUI()
{
	// Get the current weapon
	IWeapon* currentWeapon = mTurret->GetCurrentWeapon();

	// Color
	Color white = Color(255, 255, 255);

	// Draw the name
	mGO->GetWorld()->GetEngine()->DrawText("36daythk.ttf", 20, currentWeapon->Type(), Vector2(0.0f, 0.0f), white);

	// Draw the description
	mGO->GetWorld()->GetEngine()->DrawText("04B_03.ttf", 14, currentWeapon->Instructions(), Vector2(0.0f, 100.0f), white);
}
