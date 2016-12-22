#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "Primitive.h"
#include "PhysVehicle3D.h"
#include "PhysBody3D.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled), vehicle(NULL)
{
	turn = acceleration = brake = 0.0f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	VehicleInfo car;

	// Car properties ----------------------------------------
	car.chassis_size.Set(4, 1,6);
	car.chassis_offset.Set(0,1,0);
	car.mass = 950.0f;
	car.suspensionStiffness = 100.88f;
	car.suspensionCompression = 0.83f;
	car.suspensionDamping = 1;
	car.maxSuspensionTravelCm = 200.0f;
	car.frictionSlip = 500.5;
	car.maxSuspensionForce = 700.0f;

	// Wheel properties ---------------------------------------
	float connection_height = 1.2f;
	float wheel_radius = 0.6f;
	float wheel_width = 0.5f;
	float suspensionRestLength = 1.2f;

	// Don't change anything below this line ------------------

	float half_width = car.chassis_size.x*0.7f;
	float half_length = car.chassis_size.z*0.4f;
	
	vec3 direction(0,-1,0);
	vec3 axis(-1,0,0);
	
	car.num_wheels = 4;
	car.wheels = new Wheel[4];

	// FRONT-LEFT ------------------------
	car.wheels[0].connection.Set(half_width - 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[0].direction = direction;
	car.wheels[0].axis = axis;
	car.wheels[0].suspensionRestLength = suspensionRestLength;
	car.wheels[0].radius = wheel_radius ;
	car.wheels[0].width = wheel_width;
	car.wheels[0].front = true;
	car.wheels[0].drive = true;
	car.wheels[0].brake = false;
	car.wheels[0].steering = true;

	// FRONT-RIGHT ------------------------
	car.wheels[1].connection.Set(-half_width + 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[1].direction = direction;
	car.wheels[1].axis = axis;
	car.wheels[1].suspensionRestLength = suspensionRestLength;
	car.wheels[1].radius = wheel_radius ;
	car.wheels[1].width = wheel_width;
	car.wheels[1].front = true;
	car.wheels[1].drive = true;
	car.wheels[1].brake = false;
	car.wheels[1].steering = true;

	// REAR-LEFT ------------------------
	car.wheels[2].connection.Set(half_width - 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[2].direction = direction;
	car.wheels[2].axis = axis;
	car.wheels[2].suspensionRestLength = suspensionRestLength;
	car.wheels[2].radius = wheel_radius;
	car.wheels[2].width = wheel_width;
	car.wheels[2].front = false;
	car.wheels[2].drive = false;
	car.wheels[2].brake = true;
	car.wheels[2].steering = false;

	// REAR-RIGHT ------------------------
	car.wheels[3].connection.Set(-half_width + 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[3].direction = direction;
	car.wheels[3].axis = axis;
	car.wheels[3].suspensionRestLength = suspensionRestLength;
	car.wheels[3].radius = wheel_radius;
	car.wheels[3].width = wheel_width;
	car.wheels[3].front = false;
	car.wheels[3].drive = false;
	car.wheels[3].brake = true;
	car.wheels[3].steering = false;

	vehicle = App->physics->AddVehicle(car);
	vehicle->SetPos(-52.5, 0, 257.56);
	mat4x4 matrix;
	vehicle->GetTransform(&matrix);
	matrix.rotate(180, { 0,90,0 });
	vehicle->SetTransform(&matrix);


	
	tet.size.Set(3, 0.5, 0.5);
	tet.color = Grey;
	bodycub = App->physics->AddBody(tet,0.00001);
	vec3 axis2(0, 1, -1);
	vec3 axis1(0, -1, 0);
	App->physics->AddConstraintHinge(*vehicle, *bodycub, axis2, axis1, { 0,1,0 }, { 0,5,0 }, false);

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	return true;
}

// Update: draw background
update_status ModulePlayer::Update(float dt)
{
	bodycub->GetTransform(&tet.transform);
	tet.Render();
	player_pos = vehicle->vehicle->getChassisWorldTransform().getOrigin();
	turn = acceleration = brake = 0.0f;

	if (App->input->GetKey(SDL_SCANCODE_R) == KEY_DOWN) {
		vehicle->SetPos(-10.5, 0, 120.56);
	}
	if (App->input->GetKey(SDL_SCANCODE_F) == KEY_DOWN) {
		mat4x4 matrix;
		vehicle->SetPos(-10.5, 5, 120.56);
		vehicle->GetTransform(&matrix);
		matrix.rotate(90, { 90,0,90 });
		vehicle->SetTransform(&matrix);
	}
	if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT && fuel > 0)
	{
		if (vehicle->GetKmh()/3 > 120 && App->input->GetKey(SDL_SCANCODE_LSHIFT) != KEY_REPEAT) {
			acceleration = MAX_ACCELERATION/1000;
		}
		else if (App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT){
			if (App->scene_intro->turbo > 0) {
				App->scene_intro->turbo -= 0.5;
				acceleration = MAX_ACCELERATION * 5;
			}
		}
		else {
			acceleration = MAX_ACCELERATION;
		}
		if (fuel > 0) {
			fuel -= 0.01;
		}
	}
	if(App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
	{
		if(turn < TURN_DEGREES)
			turn +=  TURN_DEGREES;
	}

	if(App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
	{
		if(turn > -TURN_DEGREES)
			turn -= TURN_DEGREES;
	}

	if(App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT && fuel>0)
	{
		if (vehicle->GetKmh() <= -30) {
			acceleration = MAX_ACCELERATION / 10;
		}
		else {
			acceleration = -MAX_ACCELERATION;
			brake = BRAKE_POWER;
		}
	}
	if (fuel > 0) {
		fuel -= 0.001;
	}
	brake = 10;

	vehicle->ApplyEngineForce(acceleration);
	vehicle->Turn(turn);
	vehicle->Brake(brake);

	vehicle->Render();
	
	float fast = App->scene_intro->fastest;
	char title[170];
	sprintf_s(title, "%.1f Km/h // Fuel: %.3f // Lap time: %i Fastest Lap: %.2f TOTAL RACETIME: %.3f // LAP %.f/5 // TURBO AT %.f", vehicle->GetKmh()/3, fuel, App->scene_intro->actual.Read()/1000, fast, App->scene_intro->total_time/1000 , App->scene_intro->lap5, App->scene_intro->turbo);
	App->window->SetTitle(title);

	return UPDATE_CONTINUE;
}



