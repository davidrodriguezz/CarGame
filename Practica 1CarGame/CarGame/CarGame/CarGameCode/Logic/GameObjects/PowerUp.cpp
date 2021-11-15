#include "PowerUp.h"
#include <iostream>
#include <time.h>
#include "../Game.h"



PowerUp::PowerUp(Game* game) :GoodObject(game) {
	/*this->game = game;
	texturaP = nullptr;*/
}

PowerUp::~PowerUp() {

}

void PowerUp::update() {

	/*if (isOutOfGame()) {

		pasado = true;
	}*/


}

//bool PowerUp::isOutOfGame() {
//
//	return pos.getX() <= game->getOrigin().getX();
//}

void PowerUp::draw() {
	drawTexture(game->getTexture(powerTexture));
}

int PowerUp::PUEnJuego() {

	return numPU;
}

//void PowerUp::setPosition() {
//	int posPUX = rand() % 5000;
//	int posPUY = rand() % 300 + 30;
//	posP = Point2D<double>(posPUX, posPUY);
//}
//
//void PowerUp::setDimension(int width, int height) {
//	w = width;
//	h = height;
//}



void PowerUp::drawTexture(Texture* texture) {
	int dX = game->getOrigin().getX();
	int dY = game->getOrigin().getY();

	SDL_Rect c = getCollider();
	SDL_Rect textureBox = { c.x + dX, c.y + dY, c.w, c.h };
	texture->render(textureBox);
}

SDL_Rect PowerUp::getCollider() {
	return { int(getX() - getWidth()),
			 int(getY() - getHeight() / 2),
			 getWidth(),
			 getHeight() };
}

bool PowerUp::receiveCarCollision(Car* car) {
	car->addLive();
	return true;
}
