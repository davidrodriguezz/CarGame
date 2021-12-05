#include "Oil.h"
#include <iostream>
#include <time.h>
#include "../Game.h"

Oil::Oil(Game* game) :BadObject(game) {

	w = OIL_WIDTH;
	h = OIL_HEIGHT;
}

Oil::~Oil() {

}

void Oil::update() {

}

void Oil::draw() {
	drawTexture(game->getTexture(oilTexture));
}

int Oil::piedrasEnJuego() {

	return numOil;
}

void Oil::drawTexture(Texture* texture) {
	int dX = game->getOrigin().getX();
	int dY = game->getOrigin().getY();

	SDL_Rect c = getCollider();
	SDL_Rect textureBox = { c.x + dX, c.y + dY, c.w, c.h };
	texture->render(textureBox);
}

SDL_Rect Oil::getCollider() {
	return { int(getX() - getWidth()),
			 int(getY() - getHeight() / 2),
			 getWidth(),
			 getHeight() };
}

bool Oil::receiveCarCollision(Car* car) {
	if(car->getVel()>0.5f)
	car->reduceSpeed(0.7);
	return false;
}

