#ifndef CARGAME_GAMEOBJECTCONTAINER_H
#define CARGAME_GAMEOBJECTCONTAINER_H

#include <vector>
//#include "GameObjects/GameObject.h"
using namespace std;

class GameObject;
class Collider;

class GameObjectContainer {
    vector<GameObject*> gameObjects;
public:

    GameObjectContainer(){};
    ~GameObjectContainer()
    {
        for (auto c : gameObjects) {
            delete c;
        }
    };
    void update();
    void draw();
    //void drawDebug();
    void add(GameObject *gameObject);
    void removeDead(int i);
    bool hasCollision(GameObject *g);
    vector<Collider *> getCollisions(GameObject *g);
    GameObject* GetObject(int i) {
        return gameObjects[i];
    }
    int GetSize() {
        return gameObjects.size();
    }
};


#endif //CARGAME_GAMEOBJECTCONTAINER_H
