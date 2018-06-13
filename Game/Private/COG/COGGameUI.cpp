#include "..\..\Public\COG\COGGameUI.h"
#include "Game\Public\COG\COGTurret.h"
#include "Game\Public\COG\COGHealth.h"
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
	if (mTurret != nullptr)
	{
		// Get the current weapon
		IWeapon* currentWeapon = mTurret->GetCurrentWeapon();

		// Color
		Color white = Color(255, 255, 255);

		// Draw the name
		mGO->GetWorld()->GetEngine()->DrawText("04B_03.ttf", 32, currentWeapon->Type(), Vector2(0.0f, 0.0f), white);

		// Draw the description
		mGO->GetWorld()->GetEngine()->DrawText("36daythk.ttf", 20, currentWeapon->Instructions(), Vector2(0.0f, 50.0f), white);

		// Some instructions
		mGO->GetWorld()->GetEngine()->DrawText("36daythk.ttf", 20, "Controls", Vector2(0.0f, 450.0f), white);
		mGO->GetWorld()->GetEngine()->DrawText("36daythk.ttf", 20, "1. Sniper", Vector2(0.0f, 480.0f), white);
		mGO->GetWorld()->GetEngine()->DrawText("36daythk.ttf", 20, "2. Shotgun", Vector2(0.0f, 510.0f), white);
		mGO->GetWorld()->GetEngine()->DrawText("36daythk.ttf", 20, "3. Machine Gun", Vector2(0.0f, 540.0f), white);

		// Health component
		COGHealth* health = mTurret->GetGO()->FindComponent<COGHealth>();

		if (health != nullptr)
		{
			mGO->GetWorld()->GetEngine()->DrawText("36daythk.ttf", 20, "Health " + std::to_string(static_cast<int>(health->GetCurrentHealth())), Vector2(650.0f, 50.0f), white);
		}
	}
}
