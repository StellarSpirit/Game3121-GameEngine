#include "GameCodeApp.h"
#include <iostream>

using namespace std;

int main()
{
	GameCodeApp* gGameCodeApp;
	gGameCodeApp = new GameCodeApp();
	gGameCodeApp->ReadCPUSpeed();
	//cout << "\n";

	system("PAUSE");
	return 0;
}