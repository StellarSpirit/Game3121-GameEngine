#pragma once
#include <stdio.h>
#include "iostream"
#include "atltypes.h"
#include "Winuser.h"
using namespace std;

class InputInterfaceClass
{
	virtual bool OnKeyDown(unsigned int const kcode) = 0;
	virtual bool OnKeyUp(unsigned int const kcode) = 0;

	virtual bool OnPointerMove(const CPoint &mousePos) = 0;
	virtual bool OnPointerButtonDown(const CPoint &mousePos, const std::string &buttonName) = 0;
	virtual bool OnPointerButtonUp(const CPoint &mousePos, const std::string &buttonName) = 0;
	virtual int GetPointerRadius() = 0;
};