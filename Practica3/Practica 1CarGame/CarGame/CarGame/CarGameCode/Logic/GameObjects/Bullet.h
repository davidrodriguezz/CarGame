#pragma once
#include <iostream>
#include "GameObject.h"

class Bullet: public GameObject()
{
public:
	Bullet();
	~Bullet();



private:
	void move() {
		this->pos = { pos.getX+15, pos.getY() };
	}

};

