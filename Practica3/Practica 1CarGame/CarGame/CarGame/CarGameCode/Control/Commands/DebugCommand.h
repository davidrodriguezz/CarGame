//#define CARGAME_DebugCOMMAND_H
#pragma once
#include "Command.h"
#include <iostream>

using namespace std;

class DebugCommand : public Command {

public:
	const string INFO_STRING = "[D] to Debug";

	DebugCommand() {
		info_string = INFO_STRING;
	};
	~DebugCommand() = default;
	bool parse(SDL_Event& event) override;
	void execute() override;
};


//#endif CARGAME_DebugCOMMAND_H

