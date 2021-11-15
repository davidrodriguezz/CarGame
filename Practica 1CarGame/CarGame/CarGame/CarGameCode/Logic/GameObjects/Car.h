//
// Created by eys on 21/8/21.
//

#ifndef CARGAME_CAR_H
#define CARGAME_CAR_H



#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "GameObject.h"

class Car : GameObject{

private:

    const double ACCELERATION = 1.3;
    const double DECELERATION = 0.9;
    const int VSPEED = 5;
    const int MAX_SPEED = 10;
    const int INITIAL_POWER = 3;

    
    int w, h;
   
    //Texture *texture;
   
    int lives=3;

    float currentVel = VSPEED;

public:
    Point2D<double> pos;

    Car(Game* game);
    ~Car();

    void draw();
    void update();
    void drawTexture(Texture* texture);

    void setDimension(int width, int height);

    double getX() {return pos.getX();};
    double getY() {return pos.getY();};
    int getWidth() {return w;};
    int getHeight() {return h;};

    void setPosition(double x, double y);

    void setCarUp();
    void setCarDown();
    void Accelerate();
    void Brake();

    float Car::getVel()						//getters y setters de distintas variables
    {
        return currentVel;
    }

    int Car::getLives()
    {
        return lives;
    }
	void setInitialPower(const int INITIAL_POWER) {
		lives = INITIAL_POWER;
	}
	void lessLive() {
		lives--;
	}
    void addLive() {
		lives++;
	}
	void setNullVel(float n = 0.1f) {
		currentVel = n;
	}

    SDL_Rect getCollider();
};


#endif //CARGAME_CAR_H
