#include "..\Public\Component.h"
#include "..\Public\GameObject.h"

Component::Component(GameObject * pGO)
	: mGO(pGO)
{
}

void Component::Initialize()
{
}

void Component::Destroy()
{
}

GameObject * Component::GetGO() const
{
	return mGO;
}
