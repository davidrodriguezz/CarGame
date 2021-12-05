#ifndef CARGAME_GoodOBJECT_H
#define CARGAME_GoodOBJECT_H

class Game;
#include "GameObject.h"

class GoodObject : public GameObject {
protected:
	bool alive;
public:
	static int instances;
	GoodObject(Game* game) : GameObject(game) {
		alive = true;
	};
	~GoodObject() override = default;
	void update() override {};
	bool toDelete() override;
	bool wave(int value) override;
	void onEnter() override;
	void onDelete() override;
	void static reset();
};


#endif //CARGAME_GoodOBJECT_H

