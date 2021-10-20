//
// Created by eys on 20/8/21.
//

#include "Game.h"
#include <time.h>
Game::Game(string name, int width, int height, int roadLength) {
    this->name = name;
    this->roadLength = roadLength;
    this->width = width;
    this->height = height;
    doExit = false;
    font = new Font("../Images/Monospace.ttf", 12);
   
}

void Game::startGame() {
    srand(time(NULL));
    car = new Car(this);
    car->setDimension(CAR_WIDTH, CAR_HEIGHT);
    car->setPosition(car->getWidth(), height/ 2.0);
    for (int i = 0; i < numpiedras; i++) {
        Wall* wall = new Wall(this);
        wall->setDimension(ROCK_WIDTH, ROCK_HEIGHT);
        wall->setPosition();
        obstacles.push_back(wall);

    }
    setFinishPosition();
    setFinishDimension(GOAL_WIDTH, GOAL_HEIGHT);
}

string Game::getGameName() {
    return name;
}

Game::~Game() {
    cout << "[DEBUG] deleting game" << endl;
    for (Wall* wall : obstacles) {
        delete wall;
    }
}

void Game::update(){
    car->update();
    //int i = 0;
    //eliminar elemento del vector de piedras desde aqui despues de comprobar que se ha ido 
    //investigar como eliminar posiciones de vector (sin que pete cuando lo hace) (erase)
    for (Wall* wall : obstacles) {
        if (wall->isOutOfGame(car)) {
            //obstacles.erase();
       }
       // i++;
    }
    if (CollisionRR(getFinishCollider(), car->getCollider())) {
        setUserExit();
        
    }
}

void Game::draw(){
    car->draw();
    for (Wall* wall : obstacles) {
        wall->draw();
        
    }
    drawFinishLine();
    drawInfo();
}

void Game::drawInfo() {

   
        int x = font->getSize() / 2;
        int y = font->getSize() / 2;
        int n = 0;
    /*if ( playing) {*/
        SDL_Rect rect = { 100 * n, 0, getWindowWidth(),
                         int(font->getSize() * 1.8) };
        Box(rect, BLACK).render(renderer);

        string s = "Pos: " + to_string(int(car->getX())) + " "
            + to_string(int(car->getY()));
        renderText(s, x, y);
        n++;
        rect = { 100 * n, 0, getWindowWidth(),
                         int(font->getSize() * 1.8) };
        string s1 = "Distance: " + to_string(int(roadLength - car->getX()));
        renderText(s1, x + 100 * n, y);
        n++;
        rect = { 100 * n, 0, getWindowWidth(),
                         int(font->getSize() * 1.8) };
        string s2 = "Speed: " + to_string(int(car->getVel()));
        renderText(s2, x + 100 * n + 20, y);
        n++;
        rect = { 100 * n, 0, getWindowWidth(),
                         int(font->getSize() * 1.8) };
        string s3 = "Power: " + to_string(int(car->getLives()));
        renderText(s3, x + 100 * n + 20, y);
        n++;
        rect = { 100 * n, 0, getWindowWidth(),
                         int(font->getSize() * 1.8) };
        string s4 = "Timer: " + to_string(int(SDL_GetTicks()));
        renderText(s4, x + 100 * n + 20, y);
        n++;
        rect = { 100 * n, 0, getWindowWidth(),
                         int(font->getSize() * 1.8) };
        string s5 = "Obstacles: " /* to_string(int(obstacles.size())); */;
        renderText(s5, x + 100 * n + 20, y);
   // }
    // else if (menu) {
       
       
   // }
}

void Game::drawMenuInfo() {
    int x = font->getSize() / 2;
    int y = font->getSize() / 2;
    int n = 0;

     SDL_Rect rect = { getWindowWidth()/3, getWindowHeight()/3, getWindowWidth()*2/3,
                        getWindowHeight()*2/3 };

        string s = "Welcome to Super Cars";

        renderText(s, x+ getWindowWidth() *2/5 , getWindowHeight() / 3 +y);
        n++;

        string s1 = "Level:0 ";
        renderText(s1, x + getWindowWidth() *2/5, getWindowHeight() / 3+ y + 25 * n);
        n++;

        string s2 = "Press space to start";
        renderText(s2, x + getWindowWidth()*2/5, getWindowHeight() / 3+ y + 25 * n);
        n++;
}

void Game::setUserExit() {
    doExit = true;
}

bool Game::isUserExit() {
    return doExit;
}

int Game::getWindowWidth(){
    return width;
}

int Game::getWindowHeight() {
    return height;
}

SDL_Renderer *Game::getRenderer() {
    return renderer;
}

void Game::setRenderer(SDL_Renderer *_renderer) {
    renderer = _renderer;
}

void Game::loadTextures() {
    if(renderer == nullptr)
        throw string("Renderer is null");

    textureContainer = new TextureContainer(renderer);
}

void Game::renderText(string text, int x, int y, SDL_Color color){
    font->render(renderer, text.c_str(), x, y, color);
}

bool Game::doQuit() {
    return isUserExit();
}

Texture *Game::getTexture(TextureName name) {
    return textureContainer->getTexture(name);
}

Point2D<int> Game::getOrigin() {
    return {int(-(car->getX() - car->getWidth())), 0};
}

void Game::setCarUp() {
    car->setCarUp();
}

void Game::setCarDown() {
    car->setCarDown();
}

void Game::Accelerate() {
    car->Accelerate();
}


void Game::Brake() {
    car->Brake();
}

void Game::drawFinishLine() {
    drawFinishTexture(getTexture(goalTexture));
}

void Game::setFinishPosition() {
    int posFinalX = 5000;
    int posFinalY = getWindowHeight()/2;
    posF = Point2D<double>(posFinalX, posFinalY);
}

void Game::setFinishDimension(int width, int height) {
    wf = width;
    hf = height;
}



void Game::drawFinishTexture(Texture* texture) {
    
    int dX = getOrigin().getX();
    int dY = getOrigin().getY();
    
    SDL_Rect c = getFinishCollider();
    SDL_Rect textureBox = { c.x + dX, c.y + dY, c.w, c.h };
    texture->render(textureBox);
}

SDL_Rect Game::getFinishCollider() {
    return { int(posF.getX() - wf),
             int(posF.getY() - hf/2),
             wf,
             hf };
}


bool Game::CollisionRR(SDL_Rect obj1, SDL_Rect obj2) {
    SDL_Rect* solape=new SDL_Rect(obj1);
    SDL_Rect* objA;
    SDL_Rect* objB;
    objA =new SDL_Rect (obj1);
    objB =new SDL_Rect (obj2);
    if (SDL_IntersectRect(objA, objB, solape)) {
        delete objA;
        delete objB;
        delete solape;
        return true;
    }
    else {
        delete objA;
        delete objB;
        delete solape;
        return false;
    }
    
}
//bool Game::CollisionRC(SDL_Rect* rock, SDL_Rect* car) {
//    if (SDL_IntersectRect(rock, car, solape)) {
//        return true;
//    }
//}

//Las colisiones las comprobamos desde game

//La linea de meta la creamos desde game (hecho,solo el renderizado)

//en view controller hay que comprobar que pase por los otros estados

//eliminar las piedras desde el update

//si queremos seguir jugando depues del game over debe volver al menu y crearse de nuevo (no hay que cerrarlo,vaya)
//destruyendo primero todo antes de empezar otra vez
