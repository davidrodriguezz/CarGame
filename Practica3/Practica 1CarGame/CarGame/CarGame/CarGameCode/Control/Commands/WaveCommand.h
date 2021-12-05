#pragma once
#ifndef CARGAME_WaveCOMMAND_H
#define CARGAME_WaveCOMMAND_H

#include "Command.h"

class WaveCommand : public Command {

public:
	const string INFO_STRING = "[W] to Wave";

	WaveCommand() {
		info_string = INFO_STRING;
	};
	~WaveCommand() = default;
	bool parse(SDL_Event& event) override;
	void execute() override;
};


#endif //CARGAME_WaveCOMMAND_H

