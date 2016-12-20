#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"

struct PhysVehicle3D;

#define MAX_ACCELERATION 10000.0f
#define TURN_DEGREES 15.0f * DEGTORAD
#define BRAKE_POWER 200.0f

class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

public:
	btVector3 player_pos;
	PhysVehicle3D* vehicle;
	float fuel = 100;
	float turn;
	float acceleration;
	float brake;
};