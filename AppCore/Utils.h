#pragma once
#include <vector>
#include <string>
namespace Utils
{
	using namespace std;
	vector<string> Tokenize(string str)
	{
		vector<string> result;
		int pos, prev = 0;
		do
		{
			pos = str.find(" ", prev);
			result.push_back(str.substr(prev, pos - prev));
			prev = pos + 1;
		} while (pos != string::npos);
		return result;
	}

	bool IsNumber(string str)
	{
		auto iter = str.begin();
		while (iter != str.end() && isdigit(*iter)) { iter++; }
		return (iter == str.end()) || str.empty();
	}
}