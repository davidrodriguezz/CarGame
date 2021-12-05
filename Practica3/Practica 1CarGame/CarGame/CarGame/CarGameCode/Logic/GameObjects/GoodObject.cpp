#include "GoodObject.h"
#include "../Game.h"
// TODO: add includes


void  GoodObject::onEnter() {
	instances += 1;
};

void  GoodObject::onDelete() {
	instances -= 1;
};

void GoodObject::reset() {
	instances = 0;
};

bool GoodObject::toDelete() {
	return !alive||game->isOutOfGame(this);
}

bool GoodObject::wave(int value)
{
	this->pos= { pos.getX() - value, pos.getY() };
	return false;
}


int GoodObject::instances = 0;
