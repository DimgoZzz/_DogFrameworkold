#include "DogFW/External/Windows/DogWinDebug.h"
#include <comdef.h>

namespace DogFW
{
    wstring DogFW::GetErrorInfo(DWORD errorMessageID)
    {
        _com_error error(errorMessageID);
        wstring error_message = error.ErrorMessage();
        return error_message;
    }

    void DogFW::DebugTextWindow(wstring str)
    {
        MessageBoxW(NULL, str.c_str(), L"DebugTextWindow", NULL);
    }

    void DogFW::DebugTextWindow(string str)
    {
        MessageBoxA(NULL, str.c_str(), "DebugTextWindow", NULL);
    }

    void DogFW::DebugTextWindow(HRESULT hr, wstring str)
    {
        _com_error error(hr);
        wstring error_message = L"Error:" + str + L"\n" + error.ErrorMessage();

        MessageBoxW(NULL, error_message.c_str(), L"DebugTextWindow", NULL);
    }

    void DogFW::DebugTextWindow(HRESULT hr, string str)
    {
        _com_error error(hr);
        wstring error_message = L"Error:" + StringConverter::StringToWide(str) + L"\n" + error.ErrorMessage();

        MessageBoxW(NULL, error_message.c_str(), L"DebugTextWindow", NULL);
    }

    void DogFW::CritErr(string str)
    {
        MessageBoxW(NULL, StringConverter::StringToWide(str).c_str(), L"Critical Error", MB_ICONERROR);
        exit(-1);
    }
    void DogFW::CritErr(wstring str)
    {
        MessageBoxW(NULL, str.c_str(), L"Critical Error", MB_ICONERROR);
        exit(-1);
    }
    
}