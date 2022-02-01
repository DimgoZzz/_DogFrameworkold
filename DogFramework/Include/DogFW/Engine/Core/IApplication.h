#pragma once

namespace DogFW
{
	class IApplication
	{
	protected:
		IApplication();
		virtual ~IApplication() = 0;
	public:
		virtual void initialize() = 0;
		virtual void update() = 0;
	};
}