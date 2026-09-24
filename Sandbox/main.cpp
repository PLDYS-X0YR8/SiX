#include <iostream>
#include "SixEngine.h"

int main() {
    Engine::STimer timer;
    bool ok;
    timer.Init(ok);
    std::cout << "SixEngine Sandbox running, timer init=" << ok << "\n";
    while (true) {
        timer.Update();
        std::cout << "deltatime=" << timer.deltatime << "\n";
    }
    return 0;
}
