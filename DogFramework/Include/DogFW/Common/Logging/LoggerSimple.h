#pragma once
#include "DogFW/DogBase.h"

namespace DogFW
{
	//Static,Thread unSafe, one file logger
	class LoggerSimple
	{
	public:
		LoggerSimple ();
	
		~LoggerSimple();
	public:
		//Log to local String, call saveToFile for saving 
		void log(const WChar* fmt, ...);
		//Log and Save
		void logs(const WChar* fmt, ...);
		void setNewPath(const WString path);
		void saveToFile();
	private:
		WString filePath_ = L"Log\\SimpleLog.log";
	};
}
