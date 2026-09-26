#pragma once
#include <iostream>
#include <glad/glad.h>
#include <glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <imgui_stdlib.h>
#include <string>

namespace SixEditor {
	enum class SELogLevel {
		Debug,
		Info,
		Error
	};
	struct SELogMessage {
		SELogLevel level;
		std::string content;
		std::string category;
		std::string filename;
		int line;
	};
	class SELogWin {
	public:
		void Render();
	private:
		bool m_open = true;
	};
}