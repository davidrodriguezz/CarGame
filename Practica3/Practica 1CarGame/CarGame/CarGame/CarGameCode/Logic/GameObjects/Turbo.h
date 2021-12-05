#pragma once
#include <iostream>
#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "../../Logic/GameObjects/Car.h"
#include "GameObject.h"
#include "GoodObject.h"
class Turbo : public GoodObject
{
private:
	int numTurbo = 5;
	int piedrasEnJuego();
	float timer = 7500;

	const unsigned int TURBO_WIDTH = 70;
	const unsigned  int TURBO_HEIGHT = 40;

public:
	bool pasado = false;

	Turbo(Game* game);
	~Turbo();
	void draw();
	void update();
	void setPosition();
	void setDimension(int width, int height);
	SDL_Rect getCollider();
	void drawTexture(Texture* texture);
	bool isOutOfGame();
	bool receiveCarCollision(Car* car) override;
};



