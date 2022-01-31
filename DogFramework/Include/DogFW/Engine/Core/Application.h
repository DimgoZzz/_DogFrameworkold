#pragma once
#include "IApplication.h"

namespace DogFW
{
	class Application : public IApplication
	{
		Application();
		~Application();
	public:
		void Update() override;
		void Init() override;
	};
}