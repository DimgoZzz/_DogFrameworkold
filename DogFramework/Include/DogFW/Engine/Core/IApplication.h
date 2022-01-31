#pragma once

namespace DogFW
{
	class IApplication
	{
	public:
		IApplication();
		virtual ~IApplication() = 0;

	public:
		virtual void Init() = 0;
		virtual void Update() = 0;

	};
}