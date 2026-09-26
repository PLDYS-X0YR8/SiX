#pragma once
#include "spch.h"

namespace Six {
	class SIXAPI SApplication {
	public:
		virtual ~SApplication();
		virtual void OnUpdate(float deltaTime);
		virtual bool OnInit();
		virtual void OnShutdown();
		virtual bool ShouldClose();
		virtual void Shutdown();
	protected:
		bool m_running = true;

	};
}