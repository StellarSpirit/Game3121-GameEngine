#pragma once
#include <string>
using namespace std;

class BaseComponent
{
protected:
	string componentName;
public:
	BaseComponent() {};
	~BaseComponent() {};
	string GetName() { return componentName; }
};

