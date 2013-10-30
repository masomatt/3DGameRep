#include "Ship.h"
#include "zeni/Model.h"

Ship::Ship(Point3f pos, Quaternion rot, float m, float pitch, float roll, float accel)
	:PhysicsObject(pos, rot, m),
	pitchSpeed(pitch),
	rollSpeed(roll),
	accelSpeed(accel)
{
	if(model == NULL){
		model = new Model("models/crate.3ds");
	}
	camera = new Camera(position,
             Quaternion(),
             1.0f, 10000.0f);
}


Ship::~Ship(void)
{
}

void Ship::pitch(float dir, float timeStep){
	rotation *= Quaternion::Axis_Angle(Vector3f(1,0,0),pitchSpeed * dir * timeStep);
}

void Ship::roll(float dir, float timeStep){
	rotation *= Quaternion::Axis_Angle(Vector3f(0,0,1), rollSpeed * dir * timeStep);
}

void Ship::accel(float dir, float timeStep){
	addImpulse(dir * rotation.get_rotation().first * accelSpeed * timeStep);
}

void Ship::render(){
	const std::pair<Vector3f, float> rot = rotation.get_rotation();

    model->set_translate(position);
    model->set_scale(Vector3f(1,1,1));
    model->set_rotate(rot.second, rot.first);

    model->render();
}

Camera* Ship::getCamera(){
	camera->orientation = rotation;
	camera->position = position - 10 * rotation.get_rotation().first;
	return camera;
}