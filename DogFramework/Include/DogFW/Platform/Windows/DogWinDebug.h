#pragma once
#include "DogFW/Platform/Windows/DogWindows.h"

#include "DogFW/Common/Text/DogString.h"

#pragma region Macros

//Path to codefile and line macros
#define D_FILESHRT_ (std::wcsrchr(__FILEW__, L'\\') ? std::wcsrchr(__FILEW__, L'\\') + 1 : __FILEW__)
#define D_FILELINE_ ((DFORMWSTR(L"%s Line %i",_DFILESHRT_,__LINE__)).c_str())

//Functions
#define DCRITERR(x) DogFW::DCriticalError(D_FORM_WSTR(L"Error: %s \n%s",x,D_FILE_LINE))
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

