#include "AccCommand.h"

bool AccCommand::parse(SDL_Event& event) {
	if (event.type == SDL_KEYDOWN) {
		SDL_Keycode key = event.key.keysym.sym;
		if (key == SDLK_RIGHT) {
			 arriba = true;
			return true;
			//llamar a lo correspondiente
		}
		else if (key == SDLK_LEFT) {
			arriba = false;
			return true;
			//llamar a lo correspondiente
		}
	}
	return false;
}

void AccCommand::execute() {
	if (arriba) {
		game->Accelerate();
	}
	else game->Brake();
}