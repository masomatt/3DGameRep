#include "zenilib.h"
#include "GameObject.h"

using namespace Zeni;
using namespace Zeni::Collision;

#pragma once
class PhysicsObject : public GameObject
{
public:
	PhysicsObject(Point3f pos = Point3f(0,0,0), Quaternion rot = Quaternion(), float m = 10);
	~PhysicsObject(void);
	void addImpulse(Vector3f impulse);
	void updatePhysics(float timeStep);

	float mass;
	float resistence;
	Vector3f momentum;

	Sphere bounding;

};

