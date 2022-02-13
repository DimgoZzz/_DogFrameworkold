#pragma once
#include <string>
#include "DogFW/Common/Text/DogChar.h"


namespace DogFW
{
	using WString = std::wstring;
	using String = std::string;

	namespace StringConverter
	{
		//Converts String/WString using CP_ACP(default Windows ANSI code page.)
		WString	stringToWide(const String& str);
		//Converts String/WString using CP_ACP(default Windows ANSI code page.)
		String wideToString(const WString& wstr);
	};

	WString formatWString(const WChar* fmt, ...);
}