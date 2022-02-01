#include "DogFW/External/Windows/DogWindows.h"

#include <comdef.h>

namespace DogFW
{
    WString DogFW::getErrorInfo(DWORD errorMessageID)
    {
        _com_error error(errorMessageID);
        WString error_message = error.ErrorMessage();
        return error_message;
    }

    void DogFW::debugTextWindow(String str)
    {
        MessageBoxA(NULL, str.c_str(), "DebugTextWindow", NULL);
    }
    void DogFW::debugTextWindow(WString str)
    {
        MessageBoxW(NULL, str.c_str(), L"DebugTextWindow", NULL);
    }
    void DogFW::debugTextWindow(HRESULT hr, String str)
    {
        _com_error error(hr);
        WString error_message = L"Error:" + StringConverter::stringToWide(str) + L"\n" + error.ErrorMessage();

        MessageBoxW(NULL, error_message.c_str(), L"DebugTextWindow", NULL);
    }
    void DogFW::debugTextWindow(HRESULT hr, WString str)
    {
        _com_error error(hr);
        WString error_message = L"Error:" + str + L"\n" + error.ErrorMessage();

        MessageBoxW(NULL, error_message.c_str(), L"DebugTextWindow", NULL);
    }
    

    void DogFW::critErr(String str)
    {
        MessageBoxW(NULL, StringConverter::stringToWide(str).c_str(), L"Critical Error", MB_ICONERROR);
        exit(-1);
    }
    void DogFW::critErr(WString str)
    {
        MessageBoxW(NULL, str.c_str(), L"Critical Error", MB_ICONERROR);
        exit(-1);
    }
    void critErr(HRESULT hr, String str)
    {
        _com_error error(hr);
        WString error_message = L"Error:" + StringConverter::stringToWide(str) + L"\n" + error.ErrorMessage();

        MessageBoxW(NULL, error_message.c_str(), L"Critical Error", MB_ICONERROR);
    }
    void critErr(HRESULT hr, WString str)
    {
        _com_error error(hr);
        WString error_message = L"Error:" + str + L"\n" + error.ErrorMessage();

        MessageBoxW(NULL, error_message.c_str(), L"Critical Error", MB_ICONERROR);
    }

}