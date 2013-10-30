#include "GameObject.h"


GameObject::GameObject(Point3f pos, Quaternion rot)
	: position(pos),
	rotation(rot)
{
}


GameObject::~GameObject(void)
{
}
