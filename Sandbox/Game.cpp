#include "Game.h"

void Game::OnUpdate(float deltatime) {
	std::cout << "deltatime: " << deltatime<<"\n";
	Six::SRenderer::Get().Update(deltatime);
}

bool Game::OnInit() {
	bool ok = true;
	m_win = new Six::SWindow(Six::Config::width,Six::Config::height,Six::Config::title);
	Six::SRenderer::Get().SetWindow(m_win);
	ok &= Six::SRenderer::Get().Init();
	return ok;
}

void Game::OnShutdown() {
	Six::SRenderer::Get().Shutdown();
}

bool Game::ShouldClose() {
	return !m_running || Six::SRenderer::Get().ShouldClose();
}