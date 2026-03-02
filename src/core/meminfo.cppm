module;

#include <fstream>
#include <string>

export module meminfo;

export struct MemoryStats {
    unsigned long total;
    unsigned long available;
    unsigned long used;
};

export class MemInfo {
    static unsigned long parseValue(const std::string& line) {
        return std::stoul(line.substr(line.find_first_of("0123456789")));
    }
public:
    static MemoryStats init() {
        std::ifstream file("/proc/meminfo");
        std::string line;
        unsigned long total = 0, avail = 0;

        while (std::getline(file, line)) {
            if (line.compare(0, 9, "MemTotal:") == 0) {
                total = parseValue(line);
            } else if (line.compare(0, 13, "MemAvailable:") == 0) {
                avail = parseValue(line);
            }
        }
        return {total, avail, total - avail};
    }
};