#pragma once
#ifndef CARGAME_MoveCOMMAND_H
#define CARGAME_MoveCOMMAND_H

#include "Command.h"

class MoveCommand : public Command {

public:
	

	const string INFO_STRING = "[UP/DOWN] to Move";

	MoveCommand() {
		info_string = INFO_STRING;
	};
	~MoveCommand() = default;
	bool parse(SDL_Event& event) override;
	void execute() override;
};


#endif //CARGAME_MoveCOMMAND_H
