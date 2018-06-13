#include "..\..\Public\Weapons\MachineGun.h"
#include "..\..\Public\Input.h"
#include "Engine\Public\Utils\Debug.h"
#include "Engine\Public\Core\Types\Vector2.h"

std::string MachineGun::Type() const
{
	return "Machine Gun";
}

void MachineGun::Shoot(const Vector2& origin, const Vector2& dir)
{
	// This one shoots a little different :)
	if (Input::Instance()->IsMouseButtonDown(MouseButton::LEFT))
	{
		Debug::OutputLine("MachineGun!!!");
	}
}
