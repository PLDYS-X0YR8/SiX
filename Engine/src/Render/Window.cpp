#include "spch.h"
#include "Window.h"
#include <glad/glad.h>
#include <glfw3.h>

namespace Six {
	SWindow::~SWindow() {
		OnShutdown();
	}
	SWindow::SWindow(int w, int h, std::string t) {
		m_data.width = w;
		m_data.height = h;
		m_data.title = t;
		OnInit();
	}
	bool SWindow::OnInit(){
		if (!glfwInit()) {
			std::cerr << "Failed to initialize GLFW" << std::endl;
			return false;
		}
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		if (!m_window)
		{
			m_window = glfwCreateWindow(m_data.width, m_data.height, m_data.title.c_str(), nullptr, nullptr);
		}
		if (!m_window) {
			std::cerr << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return false;
		}
		glfwMakeContextCurrent(m_window);
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cerr << "Failed to initialize GLAD" << std::endl;
			return false;
		}
		glViewport(0, 0, m_data.width, m_data.height);

		return true;
	}
	void SWindow::OnUpdate(){
		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}
	void SWindow::OnShutdown(){
		if (m_window)
		{
			glfwDestroyWindow(m_window);
			m_window = nullptr;
		}
		glfwTerminate();
	}
	bool SWindow::ShouldClose(){
		return glfwWindowShouldClose(m_window);
	}

	bool SWindow::IsVsync(){
		return m_data.isvsync;
	}
	void SWindow::SetVsync(bool enable){
		m_data.isvsync = enable;
		glfwSwapInterval((bool)m_data.isvsync);
	}
	void SWindow::SetWidth(int w){
		m_data.width = w;
		glViewport(0, 0, m_data.width, m_data.height);
	}
	void SWindow::SetHeight(int h){
		m_data.height = h;
		glViewport(0, 0, m_data.width, m_data.height);
	}
	void SWindow::SetTitle(std::string t){
		m_data.title = t;
	}
	const SWindow::SWindowData& SWindow::GetData() const{
		return m_data;
	}
}