#pragma once

#include "VRender.h"

class VApplication
{
public:

	VRender render;

	void Init();
	void Shutdown();
	void Update();
};

