#pragma once
#include <SDL/SDL.h>
#include "VRender.h"

class VApplication
{
public:

	VRender render;

	void Init();
	void Shutdown();
	void Render();
};

