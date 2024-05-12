#pragma once
#include "../AppCore/AppCore.h"
#include <cstdarg>
class VaListTest : public AppCore::IApp
{
	using AppCore::IApp::IApp;

	void PrintIntegers(int count, ...)
	{
		va_list ap;
		va_start(ap, count);
		for (int i = 0; i < count; ++i)
		{
			std::cout << va_arg(ap, int) << " ";
		}
		std::cout << std::endl;
		va_end(ap);
	}
	
	virtual void Run() override
	{
		PrintIntegers(3, 1, 2, 3);
	}
};