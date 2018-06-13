#include "..\..\Public\Weapons\Shotgun.h"
#include "..\..\Public\Input.h"
#include "Engine\Public\Utils\Debug.h"
#include "Engine\Public\Core\Types\Vector2.h"

std::string Shotgun::Type() const
{
	return "Shotgun";
}

void Shotgun::Shoot(const Vector2& origin, const Vector2& dir)
{
	if (Input::Instance()->IsMouseButtonPressed(MouseButton::LEFT))
	{
		Debug::OutputLine("Shotgun!!!");
	}
}
