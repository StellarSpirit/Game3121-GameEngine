#include "GameCodeApp.h"
#include <iostream>

using namespace std;

int main()
{
	GameCodeApp *gGameCodeApp = new GameCodeApp();
	if (gGameCodeApp->CheckMemory(1, 1))
	{
		cout << "There is enough memory available.\n";
	}
	else
	{
		cout << "There isn't enough memory available.\n";
	}
	system("PAUSE");
	return 0;
}