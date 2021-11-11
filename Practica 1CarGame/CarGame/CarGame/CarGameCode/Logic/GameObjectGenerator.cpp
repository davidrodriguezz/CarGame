#include <iostream>
#include "GameObjectGenerator.h"



Point2D<int> GameObjectGenerator::generateRandomPosition(Game* game, GameObject* o) {
	Point2D<int> posP;
	int posPiedraX = rand() % 5000;
	int posPiedraY = rand() % 300 + 30;
	posP = Point2D<int>(posPiedraX, posPiedraY);
	return  posP;

}


void GameObjectGenerator::addInRandomPosition(Game* game, GameObject* o,int i) {

        o = new Wall(game);
        o->setDimension(game->ROCK_WIDTH, game->ROCK_HEIGHT);
        o->setPosition(generateRandomPosition(game,o).getX(),generateRandomPosition(game,o).getY());
        bool solapa = false;
        if (i == 0) {						//comprobamos si se pueden dibujar las piedras, si no la eliminamos
            game->obstacles.push_back(o);
        }
        else {
            for (int j = 1; j < game->obstacles.size(); j++) {
                // if (SDL_HasIntersection(&wall->getCollider(),&obstacles[j]->getCollider())) {
                if (SDL_HasIntersection(&o->getCollider(), &game->obstacles[j]->getCollider())) {
                    solapa = true;
                }
            }
            if (!solapa) {
                game->obstacles.push_back(o);
            }
            else delete o;
        }
    

}