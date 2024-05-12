#pragma once
#include "../AppCore/AppCore.h"
/*
* Preprocessor definitions
* 
* WIN32: Compile env is subsystem of Win32
* _DEBUG: Debug buildset
* NDEBUG: Not debut buildset (Release buildset)
* 
* _MBCS: Compiled with multi byte character set
* _WBCS: Compiled with unicode 
* 
* _CONSOLE: Console application project
* _WINDOWS: Windows application project
* _LIB: Static library project
* _USRDLL: Dynamic library project
*/

class PreprocessorTest : public AppCore::IApp
{
public:
	/*
	   This declaration is needed beause a cpp class dosen't inherit
	   the constructor of its parent.
	*/
	using AppCore::IApp::IApp;
	virtual void Run() override
	{
		using namespace std;
#ifdef WIN32
		cout << "x86" << endl;
#else
		cout << "x64" << endl;
#endif

#ifdef _MBCS
		cout << "MBCS" << endl;
#elif _WBCS
		cout << "WBCS" << endl;
#endif

#ifdef _CONSOLE
		cout << "console" << endl;
#elif _WINDOW
		cout << "window" << endl;
#elif _LIB
		cout << "lib" << endl;
#elif _USRDLL
		cout << "dll" << endl;
#endif



	}
};