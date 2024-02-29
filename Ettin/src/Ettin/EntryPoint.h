#pragma once

#ifdef ET_PLATFORM_WINDOWS

extern Ettin::Application* Ettin::CreateApplication();

int main(int argc, char* argv[])
{
	Ettin::Application* app = Ettin::CreateApplication();
	app->run();
	delete app;
	SDL_Quit();
	Ettin::Log::Init();
	ET_CORE_INFO("hello");
	return 0;
}

#endif
