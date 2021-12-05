#pragma once
#ifndef CARGAME_ShootCOMMAND_H
#define CARGAME_ShootCOMMAND_H

#include "Command.h"

class ShootCommand : public Command {

public:
	const string INFO_STRING = "[S] to Shoot";

	ShootCommand() {
		info_string = INFO_STRING;
	};
	~ShootCommand() = default;
	bool parse(SDL_Event& event) override;
	void execute() override;
};


#endif //CARGAME_ShootCOMMAND_H

