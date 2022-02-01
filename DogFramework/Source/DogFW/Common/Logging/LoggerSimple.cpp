#include "DogFW/Common/Logging/LoggerSimple.h"
#include <stdarg.h>

namespace DogFW
{
	LoggerSimple::LoggerSimple()
	{

	}

	LoggerSimple::~LoggerSimple()
	{
		saveToFile();
	}

	void LoggerSimple::log(const WChar* fmt, ...)
	{
		WChar buf[4096];
		va_list args;

		va_start(args, fmt);
		vswprintf_s(buf, fmt, args);
		va_end(args);
	}

	void LoggerSimple::logs(const WChar* fmt, ...)
	{
		WChar buf[1024];
		va_list args;

		va_start(args, fmt);
		vswprintf_s(buf, fmt, args);
		va_end(args);
		saveToFile();
	}

	void LoggerSimple::setNewPath(const WString path)
	{
		filePath_ = path;
	}
	void LoggerSimple::saveToFile()
	{
		
	}
}