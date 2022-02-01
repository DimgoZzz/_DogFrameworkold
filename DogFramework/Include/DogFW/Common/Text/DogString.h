#pragma once
#include "DogFW/Common/Text/DogChar.h"
#include <String>


//#define D_FORMWSTR(x,...) DogFW::FormatString(x,__VA_ARGS__)

namespace DogFW
{
	using WString = std::wstring;
	using String = std::string;

	namespace StringConverter
	{
		//Converts String/WString using CP_ACP(default Windows ANSI code page.)
		WString	stringToWide(const String& str);
		String wideToString(const WString& wstr);
	};

	WString formatWString(const WChar* fmt, ...);
}

