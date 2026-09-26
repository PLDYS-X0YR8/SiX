#include "spch.h"
#include "Renderer.h"


namespace Six {
    void SRenderer::SetWindow(int width, int height, std::string title)
    {
        m_window.reset(new SWindow(width, height, title));
    }
    void SRenderer::SetWindow(SWindow* w)
    {
        m_window.reset(w);
    }
    bool SRenderer::Init() {
        return m_window->OnInit();
	}

    void SRenderer::Update(float deltatime) {
        m_window->OnUpdate();
    }

    void SRenderer::Shutdown() {
        m_window->OnShutdown();
    }
    bool SRenderer::ShouldClose()
    {
        return m_window->ShouldClose();
    }
}