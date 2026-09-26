#pragma once
#include "SixEngine.h" // 包含 SApplication 的头文件

class Game : public Six::SApplication { // 1. 加上 public
public: // 2. 加上 public:
    Game() = default;

    // 重写帧更新逻辑
    void OnUpdate(float deltatime) override;
    bool OnInit() override;
    void OnShutdown() override;
    bool ShouldClose() override;
private:
    Six::SWindow* m_win = nullptr;
};