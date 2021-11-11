#pragma once
#include <iostream>
#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "../../Logic/GameObjects/Car.h"
#include "GameObject.h"
//#include "../Game.h"

using namespace std;

class Game;

class PowerUp : public GameObject {
private:
	int numPU = 5;

	int w, h;
	Texture* texturaP;
	Point2D<double> posP;


	int PUEnJuego();

public:
	bool pasado = false;

	PowerUp();
	~PowerUp();
	void draw();
	void update();
	double getX() { return posP.getX(); };
	double getY() { return posP.getY(); };
	int getWidth() { return w; };
	int getHeight() { return h; };
	void setPosition();
	void setDimension(int width, int height);
	SDL_Rect getCollider();
	void drawTexture(Texture* texture);
	bool isOutOfGame();
};

