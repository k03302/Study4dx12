#pragma once
#include "../AppCore/AppCore.h"
class Example : public AppCore::IApp
{
public:
	/*
	   This declaration is needed beause a cpp class dosen't inherit
	   the constructor of its parent.
	*/
	using AppCore::IApp::IApp;
	virtual void Run() override
	{
		std::cout << "Example app running" << std::endl;
	}
};