#include "Wall.h"
#include <iostream>
#include <time.h>
#include "../Game.h"



Wall::Wall(Game *game) {
	this->game = game;
	texturaP = nullptr;
}

Wall::~Wall() {
	
}

bool Wall::isOutOfGame(Car* car) {
	
	return posP.getX() <= car->getX()-car->getWidth();
}

void Wall::draw() {
	drawTexture(game->getTexture(rockTexture));
}



int Wall::piedrasEnJuego() {
	
	return numPiedras;
}

void Wall::setPosition() {
	int posPiedraX =rand()%5000;
	int posPiedraY =rand()% 300 + 30;
	posP = Point2D<double>(posPiedraX,posPiedraY);
}

void Wall::setDimension(int width,int height) {
	w = width;
	h = height;
}



void Wall::drawTexture(Texture* texture) {
	int dX = game->getOrigin().getX();
    int dY = game->getOrigin().getY();

	SDL_Rect c = getCollider();
	SDL_Rect textureBox = { c.x + dX, c.y + dY, c.w, c.h };
	texture->render(textureBox);
}

SDL_Rect Wall::getCollider() {
	return { int(getX() - getWidth()),
			 int(getY() - getHeight() / 2),
			 getWidth(),
			 getHeight() };
}