#pragma once
#include "spch.h"

struct GLFWwindow;
namespace Six {
	class SIXAPI SWindow {
	private:
		struct SWindowData {
			int width;
			int height;
			std::string title;
			bool isvsync;
		};
	public:
		~SWindow();
		SWindow(int w,int h,std::string t);
		bool OnInit();
		void OnUpdate();
		void OnShutdown();
		bool ShouldClose();

		bool IsVsync();
		void SetVsync(bool enable);
		void SetWidth(int w);
		void SetHeight(int h);
		void SetTitle(std::string t);
		const SWindowData& GetData() const;

		inline GLFWwindow* GetNativeWindow() {
			return m_window;
		}
	private:
		GLFWwindow* m_window = nullptr;
		SWindowData m_data;
	};
}