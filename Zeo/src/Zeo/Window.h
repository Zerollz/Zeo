#pragma once

#include "zopch.h"

#include "Zeo/Core.h"
#include "Zeo/Events/Event.h"

namespace Zeo {

	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Heigth;

		WindowProps(const std::string& title = "Zeo Engine",
					unsigned int width = 1280,
					unsigned int heigth = 720)
			: Title(title), Width(width), Heigth(heigth)
		{
		}
	};

	// Interface representing a desktop system based Window
	class ZEO_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window(){}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeigth() const = 0;

		//Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callkack) = 0;
		virtual void SetVSync(bool enable) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}