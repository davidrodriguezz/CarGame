#include "Turbo.h"
#include <iostream>
#include <time.h>
#include "../Game.h"

Turbo::Turbo(Game* game) :GoodObject(game) {
	w = TURBO_WIDTH;
	h = TURBO_HEIGHT;
}

Turbo::~Turbo() {
	
}

void Turbo::update() {

}

void Turbo::draw() {
	drawTexture(game->getTexture(turboTexture));
}

int Turbo::piedrasEnJuego() {

	return numTurbo;
}

void Turbo::drawTexture(Texture* texture) {
	int dX = game->getOrigin().getX();
	int dY = game->getOrigin().getY();

	SDL_Rect c = getCollider();
	SDL_Rect textureBox = { c.x + dX, c.y + dY, c.w, c.h };
	texture->render(textureBox);
}

SDL_Rect Turbo::getCollider() {
	return { int(getX() - getWidth()),
			 int(getY() - getHeight() / 2),
			 getWidth(),
			 getHeight() };
}

bool Turbo::receiveCarCollision(Car* car) {
	car->setVel(20);
	game->setTimerTurbo(150);
	return false;
}
