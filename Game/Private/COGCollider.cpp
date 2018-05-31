#include "..\Public\COGCollider.h"
#include "Game\Public\World.h"
#include "Game\Public\GameObject.h"
#include "Game\Public\GameObjectHandle.h"
#include "Game\Public\COGTransform.h"
#include "Engine\Public\Core\Types\Vector2.h"
#include "Engine\Public\Core\Types\Color.h"
#include "Engine\Public\Engine.h"

std::vector<COGCollider*> COGCollider::mColliderComponents;

COGCollider::COGCollider(GameObject * pGO)
	: Component(pGO)
	, mRadius(0.0f)
{
}

void COGCollider::Initialize()
{
	mTrans = mGO->FindComponent<COGTransform>();
	AddToComponentVector(mColliderComponents);
}

void COGCollider::Destroy()
{
	RemoveFromComponentVector(mColliderComponents);
}

void COGCollider::CheckCollision()
{
	mGO->GetWorld()->GetEngine()->DrawCircle(mTrans->GetPosition(), mRadius, Color(255, 0, 0));

	std::vector<GameObjectHandle> handles = mGO->GetWorld()->GetHandles();

	GameObjectHandle myHandle = mGO->GetHandle();
	// Look at all the handles in the world
	for (std::size_t i = 0; i < handles.size(); ++i)
	{
		if (handles[i].IsValid())
		{
			GameObject* gameObject = handles[i].Get();

			if (gameObject != mGO)
			{
				COGCollider* other = gameObject->FindComponent<COGCollider>();
				if (other != nullptr && myHandle.IsValid())
				{
					Vector2 toOther = other->GetTransform()->GetPosition() - mTrans->GetPosition();
					bool colliding = toOther.SizeSquared() <= (mRadius + other->GetRadius()) * (mRadius + other->GetRadius());
					if (colliding)
					{
						// Activate OnCollision on all components
						std::vector<Component*> components = mGO->GetComponents();
						for (std::size_t i = 0; i < components.size(); ++i)
						{
							if (myHandle.IsValid())
							{
								components[i]->OnCollision(other);
							}
						}
					}
				}
			}
		}
	}
}

float COGCollider::GetRadius()
{
	return mRadius;
}

void COGCollider::SetRadius(const float & pRadius)
{
	mRadius = pRadius;
}

const COGTransform * COGCollider::GetTransform() const
{
	return mTrans;
}
