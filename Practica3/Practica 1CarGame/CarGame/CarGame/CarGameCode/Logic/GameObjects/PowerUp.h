#pragma once
#include <iostream>
#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "../../Logic/GameObjects/Car.h"
#include "GameObject.h"
#include "GoodObject.h"

using namespace std;

class Game;

class PowerUp : public GoodObject {
private:
	int numPU = 5;

	/*int w, h;
	Texture* texturaP;
	Point2D<double> posP;*/
	const unsigned int PU_WIDTH = 40;
	const unsigned  int PU_HEIGHT = 40;


	int PUEnJuego();

public:
	bool pasado = false;

	PowerUp(Game* game);
	~PowerUp();
	void draw();
	void update();
	/*double getX() { return posP.getX(); };
	double getY() { return posP.getY(); };
	int getWidth() { return w; };
	int getHeight() { return h; };*/
	void setPosition();
	void setDimension(int width, int height);
	SDL_Rect getCollider();
	void drawTexture(Texture* texture);
	bool receiveCarCollision(Car* car) override;

};

