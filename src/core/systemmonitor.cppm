module;

#include <chrono>
#include <expected>

export module systemmonitor;

import meminfo;
import cpuinfo;

export enum class MonitorError {
    ReadError
};

export struct SystemSnapshot {
    double cpuLoad;
    unsigned long memUsed;
    unsigned long memTotal;
};

export class SystemMonitor {
    CpuStats prevCpu{};

    double calculateCpuLoad(const CpuStats& current) const {
        const unsigned long long prevTotal = prevCpu.user + prevCpu.nice + prevCpu.system +
                                       prevCpu.idle + prevCpu.iowait + prevCpu.irq + prevCpu.softirq;

        const unsigned long long currTotal = current.user + current.nice + current.system +
                                       current.idle + current.iowait + current.irq + current.softirq;

        const unsigned long long prevIdle = prevCpu.idle + prevCpu.iowait;
        const unsigned long long currIdle = current.idle + current.iowait;

        const unsigned long long totalDiff = currTotal - prevTotal;
        const unsigned long long idleDiff = currIdle - prevIdle;

        if (totalDiff == 0) return 0.0;

        return 100.0 * (static_cast<double>(totalDiff - idleDiff) / totalDiff);
    }
public:
    std::expected<SystemSnapshot, MonitorError> update() {
        const auto currentCpu = CpuInfo::init();
        const auto currentMem = MemInfo::init();

        if (currentMem.total == 0) {
            return std::unexpected(MonitorError::ReadError);
        }

        const double cpuLoad = calculateCpuLoad(currentCpu);
        prevCpu = currentCpu;

        return SystemSnapshot{
            .cpuLoad = cpuLoad,
            .memUsed = currentMem.used,
            .memTotal = currentMem.total
        };
    }
};
