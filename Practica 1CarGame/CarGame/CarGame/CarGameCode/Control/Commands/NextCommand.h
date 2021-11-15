#pragma once
#ifndef CARGAME_NextCOMMAND_H
#define CARGAME_NextCOMMAND_H

#include "Command.h"

class NextCommand : public Command {

public:
	const string INFO_STRING = "[SPACE] to Start";

	NextCommand() {
		info_string = INFO_STRING;
	};
	~NextCommand() = default;
	bool parse(SDL_Event& event) override;
	void execute() override;
};


#endif //CARGAME_NextCOMMAND_H
