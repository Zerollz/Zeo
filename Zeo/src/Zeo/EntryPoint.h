#pragma once

#ifdef ZO_PLATFORM_WINDOWS

extern Zeo::Application* Zeo::CreateApplication();

int main(int argc, char** argv)
{
	printf("ZeoEngine Running");
	auto app = Zeo::CreateApplication();
	app->Run();
	delete app;
}

#endif // ZO_PLATFORM_WINDOWS
