#pragma once
#include"Core.h"
#include "Platform/WindowsWindow.h"
namespace Ettin
{
	// TODO: create windowApplicate
	class ETTIN_API Application
	{
	public:
		Application()
		{
			m_Window = new Ettin::WindowsWindow(Ettin::WindowProps("Ettin engine", 800, 800));
		}
		virtual ~Application()
		{
			delete m_Window;
		}
		void run();

	private:
		Ettin::WindowsWindow* m_Window;
		bool m_Running = true;
	};

	// to be defined int CLENT
	Application* CreateApplication();
}

