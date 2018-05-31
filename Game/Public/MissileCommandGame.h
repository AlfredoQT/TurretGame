#pragma once

#include "IGame.h"

class Engine;
class World;

class MissileCommandGame : public IGame
{
public:

	MissileCommandGame();

	void Init(Engine* pEngine) override;
	void Run() override;
	void End() override;

private:

	World* mWorld;

};
