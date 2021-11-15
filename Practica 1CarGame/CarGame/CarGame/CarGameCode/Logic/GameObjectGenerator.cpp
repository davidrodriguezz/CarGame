#include <iostream>
#include "GameObjectGenerator.h"




Point2D<int> GameObjectGenerator::generateRandomPosition(Game* game, GameObject* o) {
	Point2D<int> posP;
	int posPiedraX = rand() % 5000;
	int posPiedraY = rand() % 300 + 30;
	posP = Point2D<int>(posPiedraX, posPiedraY);
	return  posP;

}


void GameObjectGenerator::addInRandomPosition(Game* game, GameObject* o,GameObjectContainer* goc) {

       
        
        o->setDimension(game->ROCK_WIDTH, game->ROCK_HEIGHT);
        o->setPosition(generateRandomPosition(game,o).getX(),generateRandomPosition(game,o).getY());
        
        bool solapa = false;
        //if (i == 0) {						//comprobamos si se pueden dibujar las piedras, si no la eliminamos
        //    //game->obstacles.push_back(o);
        //    goc->add(o);
        //}
        //else {
            
        if (goc->hasCollision(o)) {
              solapa = true;
        }
            
        if (!solapa) {
                //game->obstacles.push_back(o);
                goc->add(o);
        }
        else delete o;
       // }
    

}