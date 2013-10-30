#include "zenilib.h"

using namespace Zeni;

#pragma once
class GameObject
{
public:
	GameObject(Point3f pos = Point3f(0,0,0), Quaternion rot = Quaternion());
	virtual ~GameObject(void);
	Quaternion rotation;
	Point3f position;

};

