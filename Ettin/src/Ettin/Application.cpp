#include "Etpch.h"
#include "Application.h"
namespace Ettin
{
    void Application::run()
    {
        while (m_Running)
        {
            m_Window->OnUpdate();
            SDL_RenderPresent(m_Window->getRenderer());
        }
    }
}

