#pragma once
#include <string>


//#define D_FORMWSTR(x,...) DogFW::FormatString(x,__VA_ARGS__)

namespace DogFW
{
	using wstring = std::wstring;
	using string = std::string;

	namespace StringConverter
	{
		//Converts string/wstring using CP_ACP(default Windows ANSI code page.)
		wstring	StringToWide(const string& str);
		string WideToString(const wstring& wstr);
	};

	std::wstring FormatWString(const wstring fmt, ...);
}

