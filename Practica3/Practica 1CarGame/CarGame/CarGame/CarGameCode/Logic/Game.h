//
// Created by eys on 20/8/21.
//

#ifndef CARGAME_GAME_H
#define CARGAME_GAME_H

#include <iostream>
#include <string>
#include <vector>

#include "../View/TextureContainer.h"
#include "../View/Texture.h"
#include "../View/Box.h"
#include "../View/Font.h"

#include "GameObjects/Car.h"
#include "GameObjects/Wall.h"
#include "GameObjectContainer.h"
#include "GameObjects/PowerUp.h"
#include "GameObjects/SuperRock.h"
#include "GameObjects/Truck.h"
#include "GameObjects/Oil.h"
#include "GameObjects/Coin.h"
#include "GameObjects/Turbo.h"
using namespace std;

class Game{


private:
    string name;
    bool doExit;
    int roadLength;
    int width, height;
    //Car *car = nullptr;
    Car *car = nullptr;
    //Wall *wall = nullptr;
    GameObjectContainer* goc = nullptr;

    
    TextureContainer *textureContainer;
    SDL_Renderer* renderer = nullptr;
    Font *font;
	int tiempo;
	int timerTurbo;

    int wf, hf;
    Texture* texturaF;
    
    Point2D<double> posF;
    friend class Infobar;
public:
    enum Estado { menu, playing, gameOver } estado;
    const unsigned int CAR_WIDTH = 100;
    const unsigned  int CAR_HEIGHT = 50;
    
    
    const unsigned int GOAL_WIDTH = 20;
    const unsigned  int GOAL_HEIGHT = 350;

	

    int numpiedras = 20;
    int npowerUps = 3;
	int nsuperRocks = 5;
	int nTrucks = 5;
	int nOils = 5;
	int nCoins = 10;
	int nTurbos = 3;
    vector<GameObject*> obstacles;

    Game(string name, int width, int height, int roadLength);
    ~Game();

    void startGame();
    void update(int& play);
    void draw();

    void setUserExit();
    bool isUserExit();
    bool doQuit();

    int getWindowWidth();
    int getWindowHeight();

    Point2D<int> getOrigin();

    string getGameName();

    void setRenderer(SDL_Renderer *renderer);
    void loadTextures();
    Texture *getTexture(TextureName name);
    SDL_Renderer *getRenderer();
    void renderText(string text, int x, int y, SDL_Color color={0,0,0});

    void drawInfo(int time);
    void drawMenuInfo();
    void drawGameOverInfo();
    void drawGameOverInfo2(int tiempo);

    void setCarUp();
    void setCarDown();
    void Accelerate();
    void Brake();
	int getTiempo() {			//obtiene el tiempo guardado del juego
		return tiempo;
	}

    bool isOutOfGame(GameObject* obj);

    void drawFinishLine();
    void setFinishPosition();
    void setFinishDimension(int width, int height);
    SDL_Rect getFinishCollider();
    void drawFinishTexture(Texture* texture);
   
    void CambiaEstado();
    void SetInitialState();
    void SetGameOverState();
    void drawState();

    int getCoins();
    void setCoins(int coin);
    void setInitCoins();
	void reduceSpeed(float r);
	int getTimerTurbo() {
		return timerTurbo;
	}
	void setTimerTurbo(int x) {
		timerTurbo = x;
	}
	void lessTimerTurbo(int x) {
		timerTurbo -= x;
	}
    //bool CollisionRR(SDL_Rect rock1, SDL_Rect rock2);
   
};


#endif //CARGAME_GAME_H
