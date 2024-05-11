#pragma once
#include <string>
#include <memory>
#include <iostream>

/*
AppCore: The core of app template system.
IApp: Abstract class for app to be implemented
*/

namespace AppCore
{
	class IApp
	{
	protected:
		const std::string mName;
		const std::string mDesc;
	public:
		IApp(std::string _name, std::string _mDesc);
		std::string GetName();
		std::string GetDesc();
		virtual void Run(int iter) = 0;
	};
	void PrintMenu(); // Print all possible apps as menu
}