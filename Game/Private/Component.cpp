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

void Component::OnCollision(COGCollider * pOther)
{
}

GameObject * Component::GetOwner() const
{
	return mGO;
}
