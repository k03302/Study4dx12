#include "AppCore.h"
#include <iostream>
#include <list>
#include <memory>
#include <utility>
#include <string>



namespace AppCore {
	std::list<IApp*> mAppList;


/* private methods */
	void RegisterEx(IApp* app)
	{
		mAppList.emplace_back(app);
	}


/* definitions of public methods */
	void PrintMenu()
	{
		int i = 1;
		for (auto& app : mAppList)
		{
			if (app != nullptr)
			{
				std::cout << i << ". " << app->GetName() << ": " << app->GetDesc() << std::endl;
				++i;
			}
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