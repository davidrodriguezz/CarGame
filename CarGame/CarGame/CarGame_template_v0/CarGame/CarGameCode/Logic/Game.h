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



using namespace std;

class Game{


private:
    string name;
    bool doExit;
    int roadLength;
    int width, height;
    Car *car = nullptr;
    Wall *wall = nullptr;
   
    int numpiedras = 20;
    vector<Wall*> obstacles;
    TextureContainer *textureContainer;
    SDL_Renderer* renderer = nullptr;
    Font *font;
   

    int wf, hf;
    Texture* texturaF;
    
    Point2D<double> posF;
    
public:
    const unsigned int CAR_WIDTH = 100;
    const unsigned  int CAR_HEIGHT = 50;
    
    const unsigned int ROCK_WIDTH = 30;
    const unsigned  int ROCK_HEIGHT = 30;
    
    const unsigned int GOAL_WIDTH = 20;
    const unsigned  int GOAL_HEIGHT = 350;

    Game(string name, int width, int height, int roadLength);
    ~Game();

    void startGame();
    void update();
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

    void drawInfo();
    void drawMenuInfo();


    void setCarUp();
    void setCarDown();
    void Accelerate();
    void Brake();

    void drawFinishLine();
    void setFinishPosition();
    void setFinishDimension(int width, int height);
    SDL_Rect getFinishCollider();
    void drawFinishTexture(Texture* texture);
   
    bool CollisionRR(SDL_Rect rock1, SDL_Rect rock2);
    //bool CollisionRC(SDL_Rect* rock, SDL_Rect* car);
};


#endif //CARGAME_GAME_H
