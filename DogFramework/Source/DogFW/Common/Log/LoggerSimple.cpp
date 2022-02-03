#include "DogFW/Common/Log/LoggerSimple.h"
#include <stdarg.h>
#include <fstream>
#include "DogFW/External/Windows/DogWindows.h"

namespace DogFW
{
	LoggerSimple::LoggerSimple()
	{

	}

	LoggerSimple::LoggerSimple(WString path, WString name)
		:filePath_(path), fileName_(name)
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

		messages.push_back(WString(buf));
	}



	void LoggerSimple::logs(const WChar* fmt, ...)
	{
		WChar buf[1024];
		va_list args;

		va_start(args, fmt);
		vswprintf_s(buf, fmt, args);
		va_end(args);
		messages.push_back(WString(buf));
		saveToFile();
	}



	void LoggerSimple::setNewPath(const WString path)
	{
		filePath_ = path;
	}



	void LoggerSimple::saveToFile()
	{
		std::wfstream outfile;
		CreateDirectory(filePath_.c_str(), NULL);
		outfile.open((filePath_+fileName_).c_str(), std::ios_base::app);
		if (!outfile.is_open())
		{
			D_CRITERR(L"Cant open log file");
		}

		for (int i=0;i<messages.size();++i)
		{
			outfile << messages[i] << std::endl;

		}
		outfile.close();
		messages.clear();
	}
}