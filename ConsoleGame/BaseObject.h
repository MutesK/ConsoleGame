#pragma once
class CBaseObject
{
public:
	enum e_OBJECT_TYPE
	{
		e_PLAYER = 0,
		e_ENEMY,
		e_BULLET_P,
		e_BULLET_E
	};

	CBaseObject(int _x, int _y, int _type);

	int getX();
	int getY();
	int getType();

	bool dieFlag = false;

	

	virtual ~CBaseObject();
	virtual bool Action() = 0;
	virtual void Draw() = 0;

protected:
	int m_X;
	int m_Y;

	int m_Object_Type;

};

