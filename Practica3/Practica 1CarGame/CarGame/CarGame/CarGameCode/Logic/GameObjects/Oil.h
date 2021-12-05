#pragma once
#include <iostream>
#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "../../Logic/GameObjects/Car.h"
#include "GameObject.h"
#include "BadObject.h"
class Oil : public BadObject
{
private:
	int numOil = 5;
	int piedrasEnJuego();

	const unsigned int OIL_WIDTH = 40;
	const unsigned  int OIL_HEIGHT = 40;

public:
	bool pasado = false;

	Oil(Game* game);
	~Oil();
	void draw();
	void update();
	void setPosition();
	void setDimension(int width, int height);
	SDL_Rect getCollider();
	void drawTexture(Texture* texture);
	bool isOutOfGame();
	bool receiveCarCollision(Car* car) override;
};

