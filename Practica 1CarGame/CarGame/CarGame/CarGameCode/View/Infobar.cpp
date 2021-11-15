#include "Infobar.h"

void Infobar::drawInfo()
{
	game->drawInfo(int(SDL_GetTicks()));
}

void Infobar::drawMenuInfo()
{
	game->drawMenuInfo();
}

void Infobar::drawGameOverInfo()
{
	game->drawGameOverInfo();
}

void Infobar::drawGameOverInfo2()
{
	int tiempo = SDL_GetTicks() - game->getTiempo();
	game->drawGameOverInfo2(tiempo);
}

void Infobar::drawState()
{
	game->drawState();
	
}


