#pragma once
#include "DogFW/External/Windows/DogWindows.h"

#include "DogFW/Common/Text/DogString.h"

#pragma region Macros

//Path to codefile and line macros
#define D_FILESHRT_ (std::wcsrchr(__FILEW__, L'\\') ? std::wcsrchr(__FILEW__, L'\\') + 1 : __FILEW__)
#define D_FILELINE_ ((DogFW::FormatWString(L"%s Line %i",D_FILESHRT_,__LINE__)).c_str())

//Functions
#define D_CRITERR(x) DogFW::CritErr(DogFW::FormatWString(L"Error: %s \n%s",x,D_FILELINE_))
#pragma endregion Macros

namespace DogFW
{
	//Returns Info of ErrorCode
	wstring GetErrorInfo(DWORD errorMessageID);

	//Shows Window with text and hr desc
	void DebugTextWindow(wstring str);
	void DebugTextWindow(string str);
	void DebugTextWindow(HRESULT hr, wstring str);
	void DebugTextWindow(HRESULT hr, string str);

	//Shows Window with text and exit(-1)
	void CritErr(string str);
	void CritErr(wstring str);
	

}

