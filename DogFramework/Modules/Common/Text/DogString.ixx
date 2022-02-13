#include <string>
export module DogFW.BasicTypes.String;
export import DogFW.BasicTypes.Char;

//#define D_FORMWSTR(x,...) DogFW::FormatString(x,__VA_ARGS__)

export namespace DogFW :: inline BasicTypes
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

//export namespace DogSTD = std;
export namespace DogSTD
{
	
}
