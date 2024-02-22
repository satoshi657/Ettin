#pragma once
#include"Core.h"

namespace Ettin
{
	class ETTIN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
	};

	// to be defined int CLENT
	Application* CreateApplication();
}

