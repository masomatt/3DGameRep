#include "PhysicsObject.h"


PhysicsObject::PhysicsObject(Point3f pos, Quaternion rot, float m)
	:GameObject(pos, rot),
	mass(m)
{
}


PhysicsObject::~PhysicsObject(void)
{
}

void PhysicsObject::addImpulse(Vector3f impulse){
	momentum += impulse;
}

void PhysicsObject::updatePhysics(float timeStep){
	momentum -= resistence * timeStep * rotation.get_rotation().first * (momentum / mass).magnitude();
	position += momentum / mass * timeStep;
}