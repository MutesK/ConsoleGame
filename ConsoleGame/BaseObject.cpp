#include "BaseObject.h"



CBaseObject::CBaseObject(int _x, int _y, int _type)
	:m_X(_x), m_Y(_y), m_Object_Type(_type)
{
}


CBaseObject::~CBaseObject()
{
}

int CBaseObject::getX()
{
	return m_X;
}

int CBaseObject::getY()
{
	return m_Y;
}

int CBaseObject::getType()
{
	return m_Object_Type;
}



