#include "Coin.h"
#include <iostream>
#include <time.h>
#include "../Game.h"



Coin::Coin(Game* game) :GoodObject(game) {
	w = COIN_WIDTH;
	h = COIN_HEIGHT;
}

Coin::~Coin() {

}

void Coin::update() {

}

void Coin::draw() {
	drawTexture(game->getTexture(coinTexture));
}

int Coin::PUEnJuego() {

	return numC;
}

void Coin::drawTexture(Texture* texture) {
	int dX = game->getOrigin().getX();
	int dY = game->getOrigin().getY();

	SDL_Rect c = getCollider();
	SDL_Rect textureBox = { c.x + dX, c.y + dY, c.w, c.h };
	texture->render(textureBox);
}

SDL_Rect Coin::getCollider() {
	return { int(getX() - getWidth()),
			 int(getY() - getHeight() / 2),
			 getWidth(),
			 getHeight() };
}

bool Coin::receiveCarCollision(Car* car) {
	car->setCoins(1);
	return true;
}
