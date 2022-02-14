module;
//#include <string>

export module DogFW.BasicTypes.String;
export import DogFW.BasicTypes.Char;
export import <string>;

//#define D_FORMWSTR(x,...) DogFW::FormatString(x,__VA_ARGS__)

export namespace DogFW
{
	class WString : public std::wstring
	{

	};
	//using String = std::string;

	namespace StringConverter
	{
		//Converts String/WString using CP_ACP(default Windows ANSI code page.)
		//WString	stringToWide(const String& str);
		//Converts String/WString using CP_ACP(default Windows ANSI code page.)
		//String wideToString(const WString& wstr);
	};

	//WString formatWString(const WChar* fmt, ...);
}