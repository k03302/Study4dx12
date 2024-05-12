#include "AppCore.h"
#include "Utils.h"
#include <iostream>
#include <vector>
#include <memory>
#include <utility>
#include <string>
#include <conio.h> 


namespace AppCore {
	std::vector<IApp*> mAppList;
	std::string mLastInput = "";

/* private methods */
	void RegisterEx(IApp* app)
	{
		mAppList.emplace_back(app);
	}
	void PrintMenu()
	{
		int i = 1;
		std::cout << "Select the app to run" << std::endl;
		for (auto& app : mAppList)
		{
			if (app != nullptr)
			{
				std::cout << i << ". " << app->GetName() << ": " << app->GetDesc() << std::endl;
				++i;
			}
		}
	}

	// Get an input 
	void GetInput()
	{
		std::cin >> mLastInput;
		system("cls"); // clear console (works in Window only)
	}
	
	// Run the app
	bool ExecuteApp(IApp* app)
	{
		if (app == nullptr)
		{
			return false;
		}

		app->Run();
		return true;
	}

	// Run the instruction in mLastInput
	void Execute()
	{
		auto tokens = Utils::Tokenize(mLastInput);
		std::string t0 = tokens.at(0);
		if (Utils::IsNumber(t0))
		{
			int num = stoi(t0) - 1;
			if (num < mAppList.size())
			{
				IApp* app = mAppList[num];
				if (ExecuteApp(app))
				{
					std::cout << std::endl << "Ran successfully." << std::endl;
				}
				else
				{
					std::cout << "Execution of the app" << t0 << " failed" << std::endl;
				}
			}
			else
			{
				std::cout << "Invalid Input" << std::endl;
			}
		}
		else
		{
			std::cout << "Invalid Input" << std::endl;
		}
		std::cout << "Press enter to continue..." << std::endl;
		std::cin.ignore(2); // same as getchar();
		system("cls"); // clear console (works in Window only)
	}
	bool hasToExit()
	{
		if (mLastInput == "a")
		{
			return true;
		}
		return false;
	}

/* definitions of public methods */
	

	void Run()
	{
		while (true)
		{
			PrintMenu();
			GetInput();
			if (hasToExit())
			{
				break;
			}
			Execute();
		}
	}

/* IApp */
	IApp::IApp(std::string _name, std::string _desc)
		: mName(_name), mDesc(_desc)
	{
		RegisterEx(this);
	}
	
	std::string IApp::GetName()
	{
		return mName;
	}
	std::string IApp::GetDesc()
	{
		return mDesc;
	}
	
}