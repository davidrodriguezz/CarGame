#include "Truck.h"
#include <iostream>
#include <time.h>
#include "../Game.h"

Truck::Truck(Game* game) :BadObject(game) {
	w = CAMION_WIDTH;
	h = CAMION_HEIGHT;
}

Truck::~Truck() {

}

void Truck::update() {
	this->YOLO();
}

void Truck::draw() {
	drawTexture(game->getTexture(truckTexture));
}

int Truck::piedrasEnJuego() {

	return numTrucks;
}

void Truck::drawTexture(Texture* texture) {
	int dX = game->getOrigin().getX();
	int dY = game->getOrigin().getY();

	SDL_Rect c = getCollider();
	SDL_Rect textureBox = { c.x + dX, c.y + dY, c.w, c.h };
	texture->render(textureBox);
}

SDL_Rect Truck::getCollider() {
	return { int(getX() - getWidth()),
			 int(getY() - getHeight() / 2),
			 getWidth(),
			 getHeight() };
}

bool Truck::receiveCarCollision(Car* car) {
	car->lessLive();
	car->setNullVel();
	return true;
}

void Truck::YOLO() {
	this->pos = { pos.getX() - 5, pos.getY() };
	
}