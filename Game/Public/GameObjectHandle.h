#pragma once

#include <cstddef>

class GameObject;

class GameObjectHandle
{
public:

	GameObjectHandle(std::size_t pHash);

	bool IsValid();

	GameObject* Get();

private:

	std::size_t mHash;
};
