#pragma once
#include "Ettin/Window.h"
#include "SDL.h"
namespace Ettin
{
    class WindowsWindow : public Window
    {
    public:
        WindowsWindow(const WindowProps& props)
            : m_Window(nullptr), m_Renderer(nullptr), m_Props(props)
        {
            if (SDL_Init(SDL_INIT_VIDEO) < 0)
            {
                SDL_Log("SDL could not initialize! SDL_Error: %s", SDL_GetError());
                exit(EXIT_FAILURE);
            }

            m_Window = SDL_CreateWindow(m_Props.Title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_Props.Width, m_Props.Height, SDL_WINDOW_SHOWN);
            if (m_Window == nullptr)
            {
                SDL_Log("Window could not be created! SDL_Error: %s", SDL_GetError());
                exit(EXIT_FAILURE);
            }

            m_Renderer = SDL_CreateRenderer(m_Window, -1, 0);
            if (m_Renderer == nullptr)
            {
                SDL_Log("Renderer could not be created! SDL_Error: %s", SDL_GetError());
                exit(EXIT_FAILURE);
            }
        }

        ~WindowsWindow()
        {
            SDL_DestroyRenderer(m_Renderer);
            SDL_DestroyWindow(m_Window);
        }

        void OnUpdate() override
        {
            // 在这里可以添加窗口更新逻辑
        }

        int getWidth() const override
        {
            return m_Props.Width;
        }

        int getHeight() const override
        {
            return m_Props.Height;
        }

        SDL_Renderer* getRenderer()
        {
            return m_Renderer;
        }
    private:
        SDL_Window* m_Window;
        SDL_Renderer* m_Renderer;
        WindowProps m_Props;
    };
}

