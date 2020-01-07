#include "GameCodeApp.h"
#include <iostream>

using namespace std;

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	GameCodeApp* gGameCodeApp;
	gGameCodeApp = new GameCodeApp();
	
	//gGameCodeApp->CheckMemory();




	system("PAUSE");
	return 0;
}