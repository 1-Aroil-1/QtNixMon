#include <QApplication>
#include "ui/mainwindow.h"
#include <print>
#include <thread>
#include <unistd.h>

import systemmonitor;

[[noreturn]] void runConsoleMode(SystemMonitor& monitor) {
    std::println("Starting System Monitor (CLI Mode)...");
    std::println("{:^10} | {:^15} | {:^10}", "CPU %", "Mem Used", "Status");
    std::println("{:-^40}", "");

    using namespace std::chrono_literals;
    while (true) {
        if (auto result = monitor.update()) {
            std::println("{:^10.2f} | {:^12} MB | {:^10}", result->cpuLoad, result->memUsed / 1024, "OK");
        } else {
            std::println("Error: {}", static_cast<int>(result.error()));
        }
        std::this_thread::sleep_for(1000ms);
    }
}

int main(int argc, char *argv[]) {
    const std::vector<std::string_view> args(argv + 1, argv + argc);
    bool useGui = false;

    for (const auto arg : args) {
        if (arg == "--gui") {
            useGui = true;
            break;
        }
    }

    if (useGui) {

        const pid_t pid = fork();

        if (pid < 0) {
            std::println(stderr, "error forking");
            return 1;
        }

        if (pid > 0) {
            return 0;
        }

        QApplication app(argc, argv);
        app.setApplicationName("QtNixMon");

        mainwindow window;
        window.show();
        return app.exec();
    } else {
        SystemMonitor monitor;
        runConsoleMode(monitor);
    }
}