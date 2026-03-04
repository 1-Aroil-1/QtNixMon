#include <QApplication>
#include "ui/mainwindow.h"
#include <print>
#include <thread>
#include <unistd.h>
#include <csignal>

import systemmonitor;
import configmanager;

volatile sig_atomic_t gRunning = 1;

void signalHandler(int) {
    gRunning = 0;
}

void printHelp() {
    std::println("QtNixMon - System Monitor for Linux");
    std::println("");
    std::println("Usage:");
    std::println("  QtNixMon [options]");
    std::println("");
    std::println("Options:");
    std::println("  --gui              Run in GUI mode");
    std::println("  --interval <ms>    Set update interval in milliseconds (default: 1000)");
    std::println("  --show-config      Show current config and exit");
    std::println("  --help             Show this help message");
}

void runConsoleMode(SystemMonitor& monitor, ConfigManager& config) {
    std::println("Starting System Monitor (CLI Mode)...");
    std::println("{:^10} | {:^15} | {:^10}", "CPU %", "Mem Used", "Status");
    std::println("{:-^40}", "");

    using namespace std::chrono_literals;
    auto interval = std::chrono::milliseconds(config.getInterval());
    
    while (gRunning) {
        if (auto result = monitor.update()) {
            std::println("{:^10.2f} | {:^12} MB | {:^10}", result->cpuLoad, result->memUsed / 1024, "OK");
        } else {
            std::println("Error: {}", static_cast<int>(result.error()));
        }
        std::this_thread::sleep_for(interval);
    }
    
    config.save();
    std::println("Config saved, exiting...");
}

int main(int argc, char *argv[]) {
    const std::vector<std::string_view> args(argv + 1, argv + argc);
    bool useGui = false;
    bool showConfig = false;
    bool showHelp = false;
    int interval = -1;

    for (size_t i = 0; i < args.size(); ++i) {
        const auto arg = args[i];
        
        if (arg == "--gui") {
            useGui = true;
        } else if (arg == "--show-config") {
            showConfig = true;
        } else if (arg == "--help") {
            showHelp = true;
        } else if (arg == "--interval" && i + 1 < args.size()) {
            interval = std::stoi(std::string(args[++i]));
        }
    }

    if (showHelp) {
        printHelp();
        return 0;
    }

    ConfigManager config;
    config.load();
    
    if (showConfig) {
        std::println("Current config:");
        std::println("  update_interval_ms: {}", config.getInterval());
        return 0;
    }

    if (interval > 0) {
        config.setInterval(interval);
        config.save();
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
        std::signal(SIGINT, signalHandler);
        std::signal(SIGTERM, signalHandler);
        
        SystemMonitor monitor;
        runConsoleMode(monitor, config);
    }
}
