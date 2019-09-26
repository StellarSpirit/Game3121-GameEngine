#include "GameCodeApp.h"
#include <iostream>

using namespace std;

int main()
{
	GameCodeApp* gGameCodeApp;
	gGameCodeApp = new GameCodeApp();

	gGameCodeApp->CheckMemory();


	system("PAUSE");
	return 0;
}