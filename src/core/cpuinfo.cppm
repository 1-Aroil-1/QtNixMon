module;

#include <fstream>
#include <string>
#include <sstream>

export module cpuinfo;

export struct CpuStats {
    unsigned long long user;
    unsigned long long nice;
    unsigned long long system;
    unsigned long long idle;
    unsigned long long iowait;
    unsigned long long irq;
    unsigned long long softirq;

    unsigned long long getTotal() const {
        return user + nice + system + idle + iowait + irq + softirq;
    }

    unsigned long long getActive() const {
        return user + nice + system + irq + softirq;
    }
};

export class CpuInfo {
public:
    static CpuStats init() {
        std::ifstream file("/proc/stat");
        std::string line;
        CpuStats stats{};

        if (std::getline(file, line)) {
            std::string cpuPrefix;
            std::istringstream ss(line);

            ss >> cpuPrefix >> stats.user >> stats.nice >> stats.system
               >> stats.idle >> stats.iowait >> stats.irq >> stats.softirq;
        }

        return stats;
    }
};
