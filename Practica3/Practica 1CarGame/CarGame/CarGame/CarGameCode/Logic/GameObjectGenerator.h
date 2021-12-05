#ifndef CARGAME_GAMEOBJECTGENERATOR_H
#define CARGAME_GAMEOBJECTGENERATOR_H

#include "Game.h"
#include "GameObjects/GameObject.h"


class GameObjectGenerator {

    
    Point2D<int> static generateRandomPosition(Game *game, GameObject *o);
    void static addInRandomPosition(Game *game, GameObject *o,GameObjectContainer* goc);

public:
    static void generate(Game *game, GameObjectContainer* goc, int N_ROCKS = 0, int N_POWERUPS = 0,int N_SUPERROCKS=0,int N_OILS=0,int N_TURBOS=0,int N_COINS=0,int N_TRUCKS=0){
        for(int i = 0; i < N_ROCKS; i++)
            addInRandomPosition(game, new Wall(game),goc);

        for(int i = 0; i < N_POWERUPS; i++)
            addInRandomPosition(game, new PowerUp(game),goc);
   
        for (int i = 0; i < N_SUPERROCKS; i++)
            addInRandomPosition(game, new SuperRock(game), goc);

        for (int i = 0; i < N_OILS; i++)
            addInRandomPosition(game, new Oil(game), goc);

        for (int i = 0; i < N_TURBOS; i++)
            addInRandomPosition(game, new Turbo(game), goc);

        for (int i = 0; i < N_COINS; i++)
            addInRandomPosition(game, new Coin(game), goc);

        for (int i = 0; i < N_TRUCKS; i++)
            addInRandomPosition(game, new Truck(game), goc);
    }
   
};


#endif //CARGAME_GAMEOBJECTGENERATOR_H
