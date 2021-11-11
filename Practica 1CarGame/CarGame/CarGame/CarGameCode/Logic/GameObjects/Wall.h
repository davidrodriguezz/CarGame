#pragma once
#include <iostream>
#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "../../Logic/GameObjects/Car.h"
#include "GameObject.h"
//#include "../Game.h"

using namespace std;



class Wall : public GameObject{
private:
	int numPiedras = 20;
	
	//int w, h;
	////Texture* texturaP;
	//Point2D<double> posP;
	
	
	
	
	void quitarvida();
	int piedrasEnJuego();

public:
	bool pasado = false;

	Wall(Game* game);
	~Wall();
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
};