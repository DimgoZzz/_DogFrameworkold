#include "DogFW/Common/Text/DogString.h"
#include "DogFW/External/Windows/DogWindows.h"

#include <vector>
#include <stdarg.h>


namespace DogFW
{
	WString DogFW::StringConverter::stringToWide(const String& str)
	{
		int nLenOfWideCharStr = MultiByteToWideChar(CP_ACP, 0, str.c_str(), (int)str.length(), NULL, 0);

		if (nLenOfWideCharStr <= 0)
		{
			return WString();
		}

		WString res(nLenOfWideCharStr, L'0');
		MultiByteToWideChar(CP_ACP, 0, str.c_str(), (int)str.length(), res.data(), nLenOfWideCharStr);

		return res;
	}

	String DogFW::StringConverter::wideToString(const WString& wstr)
	{
		int nLenOfCharStr = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), (int)wstr.length(), NULL, 0, NULL, NULL);

		if (nLenOfCharStr <= 0)
		{
			return String();
		}

		String res(nLenOfCharStr, L'0');
		WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), (int)wstr.length(), res.data(), nLenOfCharStr, NULL, NULL);

		return res;
	}

	WString formatWString(const WChar* fmt, ...)
	{
		WChar buf[1024];
		va_list args;

		va_start(args, fmt);
		vswprintf_s(buf, fmt, args);
		va_end(args);
		return WString(buf);
	}
}
