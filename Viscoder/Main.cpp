
#include <SDL/SDL.h>
#include "VApplication.h"

VApplication App;

int main(int argc, char** argv) {

	App.Init();

	App.Shutdown();
	return 0;
}