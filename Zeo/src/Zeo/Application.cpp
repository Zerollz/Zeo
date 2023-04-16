#include "zopch.h"
#include "Application.h"

#include "Zeo/Events/ApplicationEvent.h"
#include "Zeo/Log.h"

#include <GLFW/glfw3.h>

namespace Zeo {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());

	}

	Application::~Application()
	{
		
	}

	void Application::Run()
	{
		while (1)
		{
			m_Window->OnUpdate();

		}
	}

}