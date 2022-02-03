#pragma once
#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers
#include <Windows.h>


#include "DogFW/Common/Text/DogString.h"

#pragma region Macros

//Path of file
#define D_FILEPATHSHRT_ (std::wcsrchr(__FILEW__, L'\\') ? std::wcsrchr(__FILEW__, L'\\') + 1 : __FILEW__)
//Patn and line of macro
#define D_FILELINE_ ((DogFW::formatWString(L"%s Line %i",D_FILEPATHSHRT_,__LINE__)).c_str())

//
#define D_CRITERR(x) DogFW::critErr(DogFW::formatWString(L"Error: %s \n%s",x,D_FILELINE_))
#pragma endregion Macros


namespace DogFW
{
	//Returns Info of ErrorCode
	WString getErrorInfo(DWORD errorMessageID);

	//Shows Window with text and hr desc
	void debugTextWindow(WString str);
	void debugTextWindow(String str);
	void debugTextWindow(HRESULT hr, WString str);
	void debugTextWindow(HRESULT hr, String str);

	//Shows Window with text and exit(-1)
	void critErr(String str);
	void critErr(WString str);
	void critErr(HRESULT hr, String str);
	void critErr(HRESULT hr, WString str);
}


