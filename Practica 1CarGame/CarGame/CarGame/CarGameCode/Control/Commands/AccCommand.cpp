#include "AccCommand.h"

bool AccCommand::parse(SDL_Event& event) {
	if (event.type == SDL_KEYDOWN) {
		SDL_Keycode key = event.key.keysym.sym;
		if (key == SDLK_RIGHT) {
			bool arriba = true;
			//llamar a lo correspondiente
		}
		else if (key == SDLK_LEFT) {
			bool arriba = false;
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