#pragma once

#include "Core.h"

namespace Zeo {

	class ZEO_API Application
	{
	public:
		Application();
		virtual ~Application();//����Ϊ�麯������Ϊ�ᱻSandbox�̳�

		void Run();
	};

	//To be define in CLIENT
	Application* CreateApplication();

}


