#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Zeo {

	class ZEO_API Application
	{
	public:
		Application();
		virtual ~Application();//设置为虚函数，因为会被Sandbox继承

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	//To be define in CLIENT
	Application* CreateApplication();

}


