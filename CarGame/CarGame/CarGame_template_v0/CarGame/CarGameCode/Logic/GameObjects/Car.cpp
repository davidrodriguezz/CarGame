//
// Created by eys on 21/8/21.
//

#include "Car.h"
#include "../Game.h"

Car::Car(Game *game){
    this->game = game;
    texture = nullptr;

}

void Car::setDimension(int width, int height){
    w = width;
    h = height;
};

void  Car::setPosition(double x, double y){
    pos = Point2D<double>(x, y);
};

void Car::update() {
    pos = Point2D<double>(getX() + currentVel, getY());
}

Car::~Car(){};

void Car::draw() {
    drawTexture(game->getTexture(carTexture));
}


void Car::drawTexture(Texture *texture) {
    int dX = game->getOrigin().getX();
    int dY = game->getOrigin().getY();

    SDL_Rect c = getCollider();
    SDL_Rect textureBox = { c.x + dX, c.y + dY, c.w, c.h};
    texture->render(textureBox);
}


SDL_Rect Car::getCollider(){
    return { int(getX() - getWidth()),
             int(getY() - getHeight()/2),
             getWidth(),
             getHeight()};
}


void Car::setCarUp(){
    if (pos.getY() > 40) {
        pos.setY(pos.getY() - 5);
    }
}

void Car::setCarDown(){
    if (pos.getY() <300) {
        pos.setY(pos.getY() + 5);
    }
}

void Car::Accelerate(){
    if(currentVel<MAX_SPEED)
    currentVel *= ACCELERATION;
    if (currentVel > 10) currentVel = 10;
}


void Car::Brake(){
    currentVel *= DECELERATION;
}