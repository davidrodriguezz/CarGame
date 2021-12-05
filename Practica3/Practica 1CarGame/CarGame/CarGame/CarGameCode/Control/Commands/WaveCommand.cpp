#include "WaveCommand.h"

bool WaveCommand::parse(SDL_Event& event) {
	if (event.type == SDL_KEYDOWN) {
		SDL_Keycode key = event.key.keysym.sym;
		if (key == SDLK_w) {
			return true;
			//llamar a lo correspondiente
		}
	}
	return false;
}

void WaveCommand::execute() {
	if (game->getCoins() >= 3) {
		game->setCoins(-3);
		vector<GameObject*> collisions;/// coger el vector, hacer bucle y llamar a wave()
		//Pedir vector de objetos (colliders) y hacer sus respectivos movimienyods
	}
}
