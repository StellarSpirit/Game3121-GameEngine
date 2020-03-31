#include <SFML/Graphics.hpp>
#include "GameCodeApp.h"
using namespace std;

GameCodeApp::GameCodeApp()
{
	mName = LPCSTR("Infinite Engine");
	Initialise();
	RunEngine();
}

void GameCodeApp::Initialise()
{
	if (IsOnlyInstance(mName))
	{
		cout << "This is the only instance of window " << mName << endl;
	}
	else
	{
		cout << "There is another instance of window " << mName << endl;
		return;
	}

	


	if (CheckStorage(300000000))
	{
		cout << "The computer has sufficient storage space." << endl;
	}
	else
	{
		cout << "The computer does not have sufficient storage space." << endl;
	}

	DWORD test = ReadCPUSpeed();
	cout << "CPU SPEED = " << test << " MHz" << endl;

	//system("PAUSE");

	if (CheckMemory())
	{
		cout << "There is enough memory available.\n";
	}
	else
	{
		cout << "There isn't enough memory available.\n";
	}
}

bool GameCodeApp::IsOnlyInstance(LPCTSTR gameTitle) {
	HANDLE handle = CreateMutex(NULL, TRUE, gameTitle);
	if (GetLastError() != ERROR_SUCCESS) {
			return false;
	}
	return true;
}

bool GameCodeApp::CheckStorage(const DWORDLONG diskSpaceNeeded) {
	// Check for enough free disk space on the current disk.
	int const drive = _getdrive();
	struct _diskfree_t diskfree;
	_getdiskfree(drive, &diskfree);
	unsigned __int64 const neededClusters = diskSpaceNeeded /
		(diskfree.sectors_per_cluster *
			diskfree.bytes_per_sector);

	if (diskfree.avail_clusters < neededClusters) {
		// if you get here you don’t have enough disk space!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		//GCC_ERROR("CheckStorage Failure: Not enough physical storage.");
//#pragma GCC error "CheckStorage Failure: Not enough physical storage."
		return false;
	}
	return true;
}

bool GameCodeApp::CheckMemory() {
	MEMORYSTATUSEX status;
	status.dwLength = sizeof(status);
	GlobalMemoryStatusEx(&status);
	//cout << status.ullAvailPhys;
	if (!status.ullAvailPhys) {
		/* You don't have enough physical memory.*/
		cout << "CheckMemory Failure: Not enough physical memory.";
		return false;
	}
	else
		cout << "Available physical memory: " << status.ullAvailPhys / 1024 << " KB\n";

	//Check for enough free memory.
	if (!status.ullAvailVirtual) {
		// You don't have enough virtual memory available.
		cout << "CheckMemory Failure: Not enough virtual memory.";
		return false;
	}
	else
		cout << "Available virtual memory: " << status.ullAvailVirtual / 1024 << " KB\n";
	return true;
}

DWORD GameCodeApp::ReadCPUSpeed() {
	DWORD BufSize = sizeof(DWORD);
	DWORD dwMHz = 0;
	DWORD type = REG_DWORD;
	HKEY hKey;
	// open the key where the proc speed is hidden:
	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",
		0, KEY_READ, &hKey);
	if (lError == ERROR_SUCCESS) {
		//cout << "ERROR SUCCESS" << endl;
		// query the key:
		RegQueryValueEx(hKey, "~MHz", NULL, &type, (LPBYTE)&dwMHz,
			&BufSize);
	}
	return dwMHz;
}

void GameCodeApp::RunEngine() {
	sf::Clock clock;
	sf::Clock updateClock;

	bool splashScreenOver = false;
	sf::Vector2u textureSize;
	sf::Vector2u windowSize;

	sf::Color gray = sf::Color::Color(sf::Color::Color(125, 125, 125, 255));
	int initX = 1200;
	int initY = 800;

	sf::RenderWindow window(sf::VideoMode(initX, initY), "INFINITE ENGINE");

	//sf::Vector2f((window.getSize().x / 4)*2, 0.f)

	//sf::Vector2f windowSize = window.getSize();

	sf::RectangleShape hierarchy;
	hierarchy.setSize(sf::Vector2f(window.getSize().x / 4, window.getSize().y));
	hierarchy.setPosition(0.f, 0.f);
	hierarchy.setFillColor(gray);
	hierarchy.setOutlineThickness(1.f);
	hierarchy.setOutlineColor(sf::Color::Black);

	sf::RectangleShape inspector;
	inspector.setSize(sf::Vector2f(window.getSize().x / 4, window.getSize().y));
	inspector.setPosition(window.getSize().x - inspector.getSize().x, 0.f);
	inspector.setFillColor(gray);
	inspector.setOutlineThickness(1.f);
	inspector.setOutlineColor(sf::Color::Black);
	
	sf::RectangleShape projectExplorer;
	// Size calculation is assuming hierarchy is on left and inspector on the right
	projectExplorer.setSize(sf::Vector2f((inspector.getPosition().x) - (hierarchy.getPosition().x + hierarchy.getSize().x), window.getSize().y / 4));
	projectExplorer.setPosition(hierarchy.getPosition().x + hierarchy.getSize().x, projectExplorer.getSize().y * 3);
	projectExplorer.setFillColor(gray);
	projectExplorer.setOutlineThickness(1.f);
	projectExplorer.setOutlineColor(sf::Color::Black);

	sf::Time splashScreenDelay = sf::seconds(5.0f);
	
	float frameTime = 1.f / 60.f;
	sf::Time dt = sf::seconds(frameTime);

	sf::Texture splashScreenImage;
	splashScreenImage.loadFromFile("../Assets/Images/IELogoBlotches.png");

	textureSize = splashScreenImage.getSize();
	windowSize = window.getSize();

	float ScaleX = (float)windowSize.x / textureSize.x;
	float ScaleY = (float)windowSize.y / textureSize.y;

	sf::Sprite splashScreenSprite;
	splashScreenSprite.setTexture(splashScreenImage);
	splashScreenSprite.setScale(ScaleX, ScaleY);
	

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (clock.getElapsedTime() > splashScreenDelay && !splashScreenOver)
		{
			splashScreenOver = true;
			updateClock.restart();
		}

		if (splashScreenOver)
		{
			//if (updateClock.getElapsedTime() > sf::seconds(0.016666f))
			if (updateClock.getElapsedTime() > dt)
			{
				Update(updateClock.getElapsedTime().asSeconds());
				updateClock.restart();
			}			
		}

		window.clear();
		window.draw(hierarchy);
		window.draw(inspector);
		window.draw(projectExplorer);

		if (!splashScreenOver)
		{
			window.draw(splashScreenSprite);
		}
		
		window.display();

		
	}
}

void GameCodeApp::Update(float deltaTime)
{
	cout << deltaTime << endl;
}
