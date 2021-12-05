#pragma once
#ifndef CARGAME_AccCOMMAND_H
#define CARGAME_AccCOMMAND_H

#include "Command.h"

class AccCommand : public Command {

public:
	const string INFO_STRING = "[LEFT/RIGHT] to Acc";

	AccCommand() {
		info_string = INFO_STRING;
	};
	~AccCommand() = default;
	bool parse(SDL_Event& event) override;
	void execute() override;
};


#endif //CARGAME_AccCOMMAND_H

