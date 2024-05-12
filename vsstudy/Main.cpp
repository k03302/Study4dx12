#include <stdio.h>
#include <utility>
#include <iostream>
#include "allheaders.h"

int main()
{
	Example example("ExampleApp", "This is just an example");
	PreprocessorTest preprocessorTest("Preprocessor Test",
		"Visual studio preprocessor definitions");
	VaListTest vaListTest("variable argument test", "variable argument test");

	AppCore::Run();
}