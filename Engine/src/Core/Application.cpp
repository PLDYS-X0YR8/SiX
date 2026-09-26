#include "spch.h"
#include "Application.h"

namespace Six {
	SApplication::~SApplication() {
		Shutdown();
	}
	bool SApplication::OnInit() {
		return true;
	}
	void SApplication::OnShutdown() {

	}
	void SApplication::OnUpdate(float deltatime) {

	}
	bool SApplication::ShouldClose() {
		return !m_running;
	}
	void SApplication::Shutdown() {
		m_running = false;
	}
}