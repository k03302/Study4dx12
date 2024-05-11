#pragma once
#include <string>
#include <memory>
namespace AppCore
{
	class IApp : public std::enable_shared_from_this<IApp>
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
	void PrintMenu();
}