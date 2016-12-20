#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));
	
	Floor.color = Grey;
	Floor.size = { 1000,0,1000 };
	Floor.SetPos(0, 0, 0);

	//track
	AddWall(10, 2, 1, 0, 1, 100, Red);
	AddWall(10, 2, 1, 10, 1, 100, Black);
	AddWall(10, 2, 1, 20, 1, 100, Red);
	AddWall(10, 2, 1, 30, 1, 100, Black);
	AddWall(10, 2, 1, 40, 1, 100, Red);
	AddWall(10, 2, 1, 50, 1, 100, Black);
	AddWall(10, 2, 1, 60, 1, 100, Red);
	AddWall(10, 2, 1, 70, 1, 100, Black);
	AddWall(10, 2, 1, 80, 1, 100, Red);
	AddWall(10, 2, 1, 90, 1, 100, Black);
	AddWall(10, 2, 1, 100, 1, 100, Red);
	AddWall(10, 2, 1, 110, 1, 100, Black);
	AddWall(10, 2, 1, 120, 1, 100, Red);
	AddWall(10, 2, 1, 130, 1, 100, Black);
	AddWall(10, 2, 1, 140, 1, 100, Red);
	AddWall(10, 2, 1, 150, 1, 100, Black);

	AddWall(10, 2, 1, 0, 1, 130, Red);
	AddWall(10, 2, 1, 10, 1, 130, Black);
	AddWall(10, 2, 1, 20, 1, 130, Red);
	AddWall(10, 2, 1, 30, 1, 130, Black);
	//AddWall(10, 2, 1, 40, 1, 130, Red);
	//AddWall(10, 2, 1, 50, 1, 130, Black);
	AddWall(10, 2, 1, 60, 1, 130, Red);
	AddWall(10, 2, 1, 70, 1, 130, Black);
	AddWall(10, 2, 1, 80, 1, 130, Red);
	AddWall(10, 2, 1, 90, 1, 130, Black);
	AddWall(10, 2, 1, 100, 1, 130, Red);
	AddWall(10, 2, 1, 110, 1, 130, Black);
	//AddWall(10, 2, 1, 120, 1, 130, Red);
	//AddWall(10, 2, 1, 130, 1, 130, Black);
	AddWall(10, 2, 1, 140, 1, 130, Red);
	AddWall(10, 2, 1, 150, 1, 130, Black);
	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	//Plane p(0, 1, 0, 0);
	//p.Render();
	Floor.Render();

	for (int i = 0; i < wall.Count(); i++) {
		wall[i].Render();
	}
	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

void ModuleSceneIntro::AddWall(uint size_x, uint size_y, uint size_z, uint pos_x, uint pos_y, uint pos_z, Color color) {

	Cube w1;
	w1.size.Set(size_x, size_y, size_z);
	w1.SetPos(pos_x, pos_y, pos_z);
	w1.color = color;
	wall.PushBack(w1);
	App->physics->AddBody(wall[wall.Count()-1], 0);
}
