#include "SixEngine.h"
#include "Game.h"

int main() {
    Six::STimer timer;
    Game g;
    bool ok = timer.Init();
    ok &= g.OnInit();
    std::cout << "Init Ok=" << ok << "\n";
    while (!g.ShouldClose()) {
        timer.Update();
        g.OnUpdate(timer.deltatime);
    }
    g.OnShutdown();
    return 0;
}
