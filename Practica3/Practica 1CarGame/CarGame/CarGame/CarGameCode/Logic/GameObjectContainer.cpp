#include <iostream>
#include "GameObjectContainer.h"
#include "GameObjects/GameObject.h"

using namespace std;

void GameObjectContainer :: update(){
    for (int i = 0; i < gameObjects.size(); i++) {
        /* if (wall != nullptr) {*/
        gameObjects[i]->update();
        //}
    }


}
void GameObjectContainer ::draw(){
    
    for (GameObject* go : gameObjects) {
        if (go != nullptr) {
            go->draw();
            
        }
    }

}

bool GameObjectContainer::hasCollision(GameObject* go) {
    return getCollisions(go).size() > 0;
}

vector<Collider*> GameObjectContainer::getCollisions(GameObject* go){
    vector<Collider*> collisions;
    for (auto i : gameObjects) {
        // if (SDL_HasIntersection(&wall->getCollider(),&obstacles[j]->getCollider())) {
        if (SDL_HasIntersection(&go->getCollider(), &i->getCollider()) && i != nullptr)
        {
            collisions.push_back(i);
        }
    }
    return collisions;
}

void GameObjectContainer::add(GameObject* go) {
    gameObjects.push_back(go);
}



void GameObjectContainer::removeDead(int i) {

	delete gameObjects[i];
	gameObjects.erase(gameObjects.begin() + i);
}

