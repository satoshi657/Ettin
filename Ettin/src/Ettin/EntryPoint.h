#pragma once

#ifdef ET_PLATFORM_WINDOWS

extern Ettin::Application* Ettin::CreateApplication();

int main(int argc, char** argv)
{
	Ettin::Log::Init();
	ET_ERROR("hello,val = {0}",45);
	ET_CORE_INFO("hello");
	ET_CORE_WARN("hello");
	ET_TRACE("hello");
	
}

#endif
