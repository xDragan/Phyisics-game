#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"

#define MAX_SNAKE 2

struct PhysBody3D;
struct PhysMotor3D;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);
	void AddWall(uint size_x, uint size_y, uint size_z, float pos_x, float pos_y, float pos_z, int tag, float angle=0);
	void ModuleSceneIntro::AddBox(uint size_x, uint size_y, uint size_z, float pos_x, float pos_y, float pos_z, Color color, float angle);
	void AddSens(float size_x, float size_y, float size_z, float pos_x, float pos_y, float pos_z, uint id,float angle);
	void AddPowerUp(uint size_x, uint size_y, uint size_z, float pos_x, float pos_y, float pos_z, uint id);

public:

	PhysBody3D* pb_chassis;
	Cube p_chassis;

	PhysBody3D* pb_wheel;
	Cylinder p_wheel;

	PhysBody3D* pb_wheel2;
	Cylinder p_wheel2;

	PhysMotor3D* left_wheel;
	PhysMotor3D* right_wheel;

public:
	p2DynArray<Cube>wall;
	Cube Floor;

	
	Cube sens[6];
	PhysBody3D* sensor[6];
	Timer lap, actual;
	Uint32 fastest;

	p2DynArray<Cube>powerups;
	PhysBody3D* pu_body[5];
	int x=0;//rotation for powerups

	float turbo;
	bool start;
};
