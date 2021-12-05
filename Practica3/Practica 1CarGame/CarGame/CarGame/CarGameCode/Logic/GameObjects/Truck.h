#pragma once
#include <iostream>
#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "../../Logic/GameObjects/Car.h"
#include "GameObject.h"
#include "BadObject.h"
using namespace std;
class Truck : public BadObject
{
private:
	int numTrucks = 5;
	int piedrasEnJuego();

	const unsigned int CAMION_WIDTH = 90;
	const unsigned  int CAMION_HEIGHT = 50;

public:
	bool pasado = false;

	Truck(Game* game);
	~Truck();
	void draw();
	void update();
	void setDimension(int width, int height);
	SDL_Rect getCollider();
	void drawTexture(Texture* texture);
	bool isOutOfGame();
	bool receiveCarCollision(Car* car) override;
	void YOLO();
};

