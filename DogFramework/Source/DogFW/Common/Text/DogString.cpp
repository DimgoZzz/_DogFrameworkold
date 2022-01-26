#include "DogFW/Common/Text/DogString.h"

#include "DogFW/External/Windows/DogWindows.h"

#include <vector>
#include <stdarg.h>

namespace DogFW
{
	wstring DogFW::StringConverter::StringToWide(const string& str)
	{
		int nLenOfWideCharStr = MultiByteToWideChar(CP_ACP, 0, str.c_str(), (int)str.length(), NULL, 0);

		if (nLenOfWideCharStr <= 0)
		{
			return std::wstring();
		}

		std::wstring res(nLenOfWideCharStr, L'0');
		MultiByteToWideChar(CP_ACP, 0, str.c_str(), (int)str.length(), res.data(), nLenOfWideCharStr);

		return res;
	}

	string DogFW::StringConverter::WideToString(const wstring& wstr)
	{
		int nLenOfCharStr = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), (int)wstr.length(), NULL, 0, NULL, NULL);

		if (nLenOfCharStr <= 0)
		{
			return string();
		}

		string res(nLenOfCharStr, L'0');
		WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), (int)wstr.length(), res.data(), nLenOfCharStr, NULL, NULL);

		return res;
	}

	wstring FormatWString(const wstring fmt, ...)
	{
		//https://habr.com/ru/post/318962/
		//Max 1024 new symbpols
		const int MAXCHARS = 1024;

		va_list args;
		va_start(args, fmt);
		std::vector<wchar_t> v(fmt.length() + MAXCHARS);
		while (true)
		{
			va_list args2;
			va_copy(args2, args);
			int res = _vsnwprintf_s(v.data(), v.size(), MAXCHARS, fmt.c_str(), args2);
			if ((res >= 0) && (res < static_cast<int>(v.size())))
			{
				va_end(args);
				va_end(args2);
				return std::wstring(v.data());
			}
			size_t size;
			if (res < 0)
				size = v.size() * 2;
			else
				size = static_cast<size_t>(res) + 1;
			v.clear();
			v.resize(size);
			va_end(args2);
		}
	}
}
