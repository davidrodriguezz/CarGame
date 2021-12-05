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

class Coin : public GoodObject {
private:
	int numC = 10;
	int PUEnJuego();

	const unsigned int COIN_WIDTH = 30;
	const unsigned  int COIN_HEIGHT = 30;

public:
	bool pasado = false;

	Coin(Game* game);
	~Coin();
	void draw();
	void update();
	void setPosition();
	void setDimension(int width, int height);
	SDL_Rect getCollider();
	void drawTexture(Texture* texture);
	bool receiveCarCollision(Car* car) override;

};

