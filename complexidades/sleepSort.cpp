#include <thread>
#include <chrono>
#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::vector<std::thread> threads;
    for (int i = 1; i < argc; ++i) {
        threads.emplace_back([i, &argv]() {
            int arg = std::stoi(argv[i]);
            std::this_thread::sleep_for(std::chrono::seconds(arg/10));
            std::cout << argv[i] << std::endl;
        });
    }
    for (auto& thread : threads) {
        thread.join();
    }
}