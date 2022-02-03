#include "DogFW/DogBasicTypes.h"
#include "DogFW/External/Windows/DogWindows.h"

#include "DogFW/Engine/Core/Application.h"
#include "DogFW/Common/Time/StopWatch.h"
#include "DogFW/Common/Log/LoggerSimple.h"

#include "DogFW/Common/Math/DogVector.h"
#include <vector>
#include <sstream>

using namespace DirectX;
using namespace DogFW;

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
	LoggerSimple l(L"Gaw/",L"DogLog.log");
	l.logs(L"Gaw %s %i", L"jjj",4);
	

	return 0;
}
