#pragma once

#ifdef ET_PLATFORM_WINDOWS

extern Ettin::Application* Ettin::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Ettin::CreateApplication();
	app->run();
	delete app;
}

#endif
