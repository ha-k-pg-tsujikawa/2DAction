#ifndef BUTTON_H
#define BUTTON_H

#include "TitleScene.h"

enum ButtonStatus
{
	Active,
	NotActive,
	Selecting,
	Pushed,
};


bool OnCursor();

#endif // !BUTTON_H
