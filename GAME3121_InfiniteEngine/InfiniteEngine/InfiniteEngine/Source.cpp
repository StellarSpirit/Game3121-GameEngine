#include "GameCodeApp.h"
#include <iostream>

using namespace std;

int main()
{
	GameCodeApp* gGameCodeApp;
	gGameCodeApp = new GameCodeApp();

	if (gGameCodeApp->IsOnlyInstance(gGameCodeApp->mName))
	{
		cout << "This is the only instance of window " << gGameCodeApp->mName << endl;
	}
	else
	{
		cout << "There is another instance of window " << gGameCodeApp->mName << endl;
	}

	if (gGameCodeApp->CheckStorage(300000000))
	{
		cout << "The computer has sufficient storage space." << endl;
	}
	else
	{
		cout << "The computer does not have sufficient storage space." << endl;
	}


	system("PAUSE");
	return 0;
}