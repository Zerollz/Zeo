#pragma once

#include "Core.h"

namespace Zeo {

	class ZEO_API Application
	{
	public:
		Application();
		virtual ~Application();//设置为虚函数，因为会被Sandbox继承

		void Run();
	};

	//To be define in CLIENT
	Application* CreateApplication();

}


