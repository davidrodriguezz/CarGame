//#define CARGAME_HelpCOMMAND_H
#pragma once

#include "Command.h"

class HelpCommand : public Command {

public:
	const string INFO_STRING = "[H] to Help";

	HelpCommand() {
		info_string = INFO_STRING;
	};
	~HelpCommand() = default;
	bool parse(SDL_Event& event) override;
	void execute() override;
};


//#endif //CARGAME_HelpCOMMAND_H

