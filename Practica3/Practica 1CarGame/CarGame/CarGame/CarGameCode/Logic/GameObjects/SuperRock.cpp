#include "SuperRock.h"
#include <iostream>
#include <time.h>
#include "../Game.h"

SuperRock::SuperRock(Game* game) :BadObject(game) {

}

SuperRock::~SuperRock() {

}

void SuperRock::update() {

}

void SuperRock::draw() {
	drawTexture(game->getTexture(superRockTexture));
}

int SuperRock::piedrasEnJuego() {

	return numPiedras;
}

void SuperRock::drawTexture(Texture* texture) {
	int dX = game->getOrigin().getX();
	int dY = game->getOrigin().getY();

	SDL_Rect c = getCollider();
	SDL_Rect textureBox = { c.x + dX, c.y + dY, c.w, c.h };
	texture->render(textureBox);
}

SDL_Rect SuperRock::getCollider() {
	return { int(getX() - getWidth()),
			 int(getY() - getHeight() / 2),
			 getWidth(),
			 getHeight() };
}

bool SuperRock::receiveCarCollision(Car* car) {
	car->setLives(-2);
	car->setNullVel();
	return true;
}
