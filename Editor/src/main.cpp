#include "Log.h"

int main() {
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(1280, 720, "我的第一个Dear ImGui应用", NULL, NULL);
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glfwSwapInterval(1); // 开启垂直同步，防止画面撕裂和轨迹残留

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();

    // 【修改 1】开启 Docking 和 Viewports（多视口）
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;   // 开启停靠
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable; // 开启多视口（允许拖出窗口）

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    SixEditor::SELogWin logger;

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::ShowDemoWindow();
        logger.Render();

        ImGui::Render();

        // 【修改 2】清屏（防止拖拽时产生轨迹）
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.1f, 0.1f, 0.12f, 1.0f); // 设置深灰色背景
        glClear(GL_COLOR_BUFFER_BIT);

        // 渲染 ImGui 主窗口
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // 【修改 3】多视口渲染逻辑（处理被拖出去的窗口）
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
            GLFWwindow* backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context); // 恢复主窗口的 OpenGL 上下文
        }

        glfwSwapBuffers(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}