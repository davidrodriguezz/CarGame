#pragma once
#include <iostream>
#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "../../Logic/GameObjects/Car.h"
#include "GameObject.h"
#include "BadObject.h"
class SuperRock : public BadObject
{
private:
	int numPiedras = 5;
	int piedrasEnJuego();

	const unsigned int SUPERROCK_WIDTH = 120;
	const unsigned  int SUPERROCK_HEIGHT = 60;

	public:
		bool pasado = false;

		SuperRock(Game* game);
		~SuperRock();
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
		bool isOutOfGame();
		bool receiveCarCollision(Car* car) override;
};

