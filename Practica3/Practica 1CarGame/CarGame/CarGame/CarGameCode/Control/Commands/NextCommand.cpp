#include "NextCommand.h"
#include <SDL_keycode.h>

bool NextCommand::parse(SDL_Event& event) {
	if (event.type == SDL_KEYDOWN) {
		SDL_Keycode key = event.key.keysym.sym;
		if (key == SDLK_SPACE) {
			return true;
			//llamar a lo correspondiente
		}
	}
	return false;
}

void NextCommand::execute() {
	game->CambiaEstado();
}
