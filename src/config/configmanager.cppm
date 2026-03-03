module;

#include <filesystem>
#include <fstream>
#include <string>
#include <expected>
#include <print>
#include <cstring>

#include "../tools/json.hpp"

export module configmanager;

export struct ConfigData {
    int update_interval_ms = 1000;
};

export class ConfigManager {
    std::filesystem::path configPath;
    ConfigData config;
    
    std::filesystem::path getConfigPath() const {
        const char* home = std::getenv("HOME");
        if (!home) {
            return std::filesystem::current_path() / "config.json";
        }
        return std::filesystem::path(home) / ".config" / "QtNixMon" / "config.json";
    }
    
    void ensureConfigDir() {
        std::filesystem::path dir = configPath.parent_path();
        if (!std::filesystem::exists(dir)) {
            std::filesystem::create_directories(dir);
        }
    }
    
public:
    ConfigManager() : configPath(getConfigPath()) {}
    
    void load() {
        if (!std::filesystem::exists(configPath)) {
            save();
            return;
        }
        
        try {
            std::ifstream file(configPath);
            if (!file.is_open()) {
                std::println(stderr, "Cannot open config file");
                return;
            }
            
            nlohmann::json j;
            file >> j;
            
            config.update_interval_ms = j.value("update_interval_ms", 1000);
            
        } catch (const std::exception& e) {
            std::println(stderr, "Config load error: {}, using defaults", e.what());
            config = ConfigData{};
        }
    }
    
    void save() {
        try {
            ensureConfigDir();
            
            nlohmann::json j;
            j["update_interval_ms"] = config.update_interval_ms;
            
            std::ofstream file(configPath);
            if (!file.is_open()) {
                std::println(stderr, "Cannot write config file");
                return;
            }
            
            file << j.dump(4);
            std::println("Config saved to {}", configPath.string());
            
        } catch (const std::exception& e) {
            std::println(stderr, "Config save error: {}", e.what());
        }
    }
    
    int getInterval() const { return config.update_interval_ms; }
    void setInterval(int ms) { config.update_interval_ms = ms; }
};
