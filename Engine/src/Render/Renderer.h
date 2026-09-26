#pragma once
#include "spch.h"
#include "Window.h"

namespace Six {
	class SIXAPI SRenderer {
	public:
		static SRenderer& Get() {
			static SRenderer r;
			return r;
		}
		void SetWindow(int width,int height,std::string title);
		void SetWindow(SWindow* w);
		inline SWindow* GetWindow() {
			return m_window.get();
		}
		bool Init();
		void Update(float deltatime);
		void Shutdown();
		bool ShouldClose();
	private:
		std::unique_ptr<SWindow> m_window;
	};
}