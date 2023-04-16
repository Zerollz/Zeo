#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Zeo {

	class ZEO_API Application
	{
	public:
		Application();
		virtual ~Application();//����Ϊ�麯������Ϊ�ᱻSandbox�̳�

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	//To be define in CLIENT
	Application* CreateApplication();

}


