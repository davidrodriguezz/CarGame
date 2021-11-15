#ifndef CARGAME_GAMEOBJECTGENERATOR_H
#define CARGAME_GAMEOBJECTGENERATOR_H

#include "Game.h"
#include "GameObjects/GameObject.h"


class GameObjectGenerator {

    
    Point2D<int> static generateRandomPosition(Game *game, GameObject *o);
    void static addInRandomPosition(Game *game, GameObject *o,GameObjectContainer* goc);

public:
    static void generateW(Game *game, GameObjectContainer* goc, int N_ROCKS = 0){
        for(int i = 0; i < N_ROCKS; i++)
            addInRandomPosition(game, new Wall(game),goc);
    }
    static void generatePU(Game *game, GameObjectContainer* goc, int N_POWERUPS = 0){
        for(int i = 0; i < N_POWERUPS; i++)
            addInRandomPosition(game, new PowerUp(game),goc);
    }   
};


#endif //CARGAME_GAMEOBJECTGENERATOR_H
