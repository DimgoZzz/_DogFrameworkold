#pragma once
#include "IApplication.h"

namespace DogFW
{
	class Application : public IApplication
	{
	public:
		Application();
		~Application();
	public:
		void initialize() override;
		void update() override;
	};
}