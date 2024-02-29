#pragma once
#include "Core.h"
namespace Ettin
{
	struct WindowProps
	{
		std::string  Title;
		uint32_t Width;
		uint32_t Height;

		WindowProps(
			const std::string& title = "Ettin engine",
			uint32_t width = 1280,
			uint32_t height = 720)
			:Title(title), Width(width), Height(height)
		{
		}
	};
	class Window
	{
	public:

		virtual	~Window() = default;

		virtual void OnUpdate() = 0;

		virtual int getWidth() const = 0;
		virtual int getHeight() const = 0;

	//	static Window* Create(const WindowProps& props = WindowProps());
	};
}
