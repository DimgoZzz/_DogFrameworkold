#include "DogFW/DogBase.h"
#include "DogFW/External/Windows/DogWindows.h"
#include "DogFW/Common/Time/StopWatch.h"
#include "DogFW/Common/Math/DogVector.h"
#include "DogFW/Engine/Core/Application.h"
#include "DogFW/Common/Logging/LoggerSimple.h"
#include <vector>
#include <sstream>

using namespace DirectX;
using namespace DogFW;

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
	LoggerSimple l;
	l.log(L"Gaw %s %i", L"jjj",4);
	

	return 0;
}
