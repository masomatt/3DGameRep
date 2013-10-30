#include "zenilib.h"
#include "PhysicsObject.h"

#pragma once
class Ship : public PhysicsObject
{
public:
	Ship(Point3f pos = Point3f(0,0,0), Quaternion rot = Quaternion(), float m = 10, float pitch = 10, float roll = 5, float accel = 20);
	~Ship(void);
	float pitchSpeed;
	float rollSpeed;
	float accelSpeed;
	static Model * model;
	Camera* camera;
	void pitch(float dir, float timeStep);
	void roll(float dir, float timeStep);
	void accel(float dir, float timeStep);
	Camera* getCamera();
	void render();
};

