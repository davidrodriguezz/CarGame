//
// Created by eys on 20/8/21.
//

#include "Game.h"
#include "GameObjectGenerator.h"
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
	tiempo = SDL_GetTicks();
    car = new Car(this);
    car->setDimension(CAR_WIDTH, CAR_HEIGHT);
    car->setPosition(car->getWidth(), height/ 2.0);
    GameObjectGenerator::generate(this, numpiedras);
    

    setFinishPosition();
    setFinishDimension(GOAL_WIDTH, GOAL_HEIGHT);
}

string Game::getGameName() {
    return name;
}

Game::~Game() {
    cout << "[DEBUG] deleting game" << endl;
    for (GameObject* wall : obstacles) {
        delete wall;
        wall = nullptr;
    }
	delete car;
    car = nullptr;
    delete font;
    font = nullptr;
    delete textureContainer;
    textureContainer = nullptr;
}

void Game::update(int& play){
    if (car != nullptr) {
        car->update();
        
    }
    for (int i = 0; i < obstacles.size(); i++) {
       /* if (wall != nullptr) {*/
           obstacles[i]->update();
        //}
    }
    

	//for (int i = 0; i < obstacles.size(); i++) {
 //       if (obstacles[i]->isOutOfGame(car)) {				//borra las piedras cuando el coche las supera
	//		delete obstacles[i];
 //           obstacles.erase(obstacles.begin()+i);
	//	}
	//	else if (SDL_HasIntersection(&obstacles[i]->getCollider(), &car->getCollider())) {			//si chocamos con una 
	//		car->lessLive();
	//		delete obstacles[i];
	//		obstacles.erase(obstacles.begin() + i);
	//		car->setNullVel();
	//	}
 //      
 //   }
    if (SDL_HasIntersection(&getFinishCollider(), &car->getCollider())) {
        play = 1;
		for (int x = 0; x < obstacles.size(); x++) {
			delete obstacles[x];
			obstacles[x] = nullptr;
			obstacles.erase(obstacles.begin() + x);

		}
		obstacles.clear();
		delete car;
		car = nullptr;

    }
	else if (car->getLives() == 0) {				//si el jugador llega a la meta o pierde todas las vidas, destruye todas las entitades
        play = 0;
		for (int x = 0; x < obstacles.size(); x++) {
			delete obstacles[x];
			obstacles[x] = nullptr;
			obstacles.erase(obstacles.begin() + x);

		}
		obstacles.clear();
        delete car;
        car = nullptr;
	}
}

void Game::draw() {				//dibuja cada una de las entidades del juego, meduante código defensivo
    if (car != nullptr) {
        car->draw();
    }

    
	for (GameObject* wall : obstacles) {
        if (wall != nullptr) {
            wall->draw();
        }
	}
	if (car != nullptr) {
		drawFinishLine();
		drawInfo(tiempo);
	}

}

void Game::drawInfo(int time) {				//dibuja la info del juego

   
        int x = font->getSize() / 2;
        int y = font->getSize() / 2;
        int n = 0;
		int i = 0;
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
        string s4 = "Timer: " + to_string(int(SDL_GetTicks()-time));
        renderText(s4, x + 100 * n + 20, y);
        n++;
        rect = { 100 * n, 0, getWindowWidth(),
                         int(font->getSize() * 1.8) };
        string s5 = "Obstacles: "+ to_string(int(obstacles.size()));
        renderText(s5, x + 100 * n + 20, y);
   // }
    // else if (menu) {
       
       
   // }
}

void Game::drawMenuInfo() {				//dibuja la informacion del menú
    int x = font->getSize() / 2;
    int y = font->getSize() / 2;
    int n = 0;

     SDL_Rect rect = { getWindowWidth()/3, getWindowHeight()/3, getWindowWidth()*2/3, getWindowHeight()*2/3 };

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

void Game::drawGameOverInfo() {				//escribe la información de derrota
    int x = font->getSize() / 2;
    int y = font->getSize() / 2;
    int n = 1;

    SDL_Rect rect = { getWindowWidth() / 3, getWindowHeight() / 3, getWindowWidth()*2 / 3, getWindowHeight()*2 / 3 };

    string s = "GameOver";
    renderText(s, x + getWindowWidth() * 2 / 5, getWindowHeight() / 3 + y + 25 * n);
}

void Game::drawGameOverInfo2(int tiempo) {				//escribe la información de victoria
    int x = font->getSize() / 2;
    int y = font->getSize() / 2;
    int n = 0;

    SDL_Rect rect = { getWindowWidth() / 3, getWindowHeight() / 3, getWindowWidth()*2 / 3, getWindowHeight()*2 / 3 };

    string s = "Congratulations!";

    renderText(s, x + getWindowWidth() * 2 / 5, getWindowHeight() / 3 + y);
    n++;

    string s1 = "User wins";
    renderText(s1, x + getWindowWidth() * 2 / 5, getWindowHeight() / 3 + y + 25 * n);
    n++;

    string s2 = "Time: " + to_string(tiempo) + " ms";
    renderText(s2, x + getWindowWidth() * 2 / 5, getWindowHeight() / 3 + y + 25 * n);
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

void Game::setCarUp() {				//sube el coche
    car->setCarUp();
}

void Game::setCarDown() {				//baja el coche
    car->setCarDown();
}

void Game::Accelerate() {					//acelera el coche
    car->Accelerate();
}


void Game::Brake() {				//frena el coche
    car->Brake();
}

void Game::drawFinishLine() {				//dibuja la línea de meta
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

bool Game::isOutOfGame(GameObject* obj) {

   return obj->pos.getX() <= getOrigin().getX();
    
}


//bool Game::CollisionRR(SDL_Rect obj1, SDL_Rect obj2) {
//    SDL_Rect* solape=new SDL_Rect(obj1);					//comprueba la colisión entre los diferentes objetos del juego
//    SDL_Rect* objA;
//    SDL_Rect* objB;
//    objA =new SDL_Rect (obj1);
//    objB =new SDL_Rect (obj2);
//    if (SDL_IntersectRect(objA, objB, solape)) {
//        delete objA;
//        delete objB;
//        delete solape;
//        objA = nullptr;
//        objB = nullptr;
//        solape = nullptr;
//        return true;
//    }
//    else {
//        delete objA;
//        delete objB;
//        delete solape;
//        objA = nullptr;
//        objB = nullptr;
//        solape = nullptr;
//        return false;
//    }
//    
//}

