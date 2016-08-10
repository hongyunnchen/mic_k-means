#include "utils.hpp"

Utils::Utils(){
    seed_random();
}
void Utils::seed_random(){
     std::srand(std::time(0));
}
double Utils::get_random(){
    return ((double)rand() / (double)(RAND_MAX));
}
void Utils::start_timer(std::string timer)
{
    start[timer] = std::chrono::system_clock::now();
}
void Utils::stop_timer(std::string timer)
{
    if (start.find(timer) != start.end())
    {
        std::chrono::duration<double> elapsed_seconds = std::chrono::system_clock::now() - start[timer];
        last[timer] = elapsed_seconds.count();
        total[timer] += elapsed_seconds.count();
        count[timer]++;
        start.erase(timer);
    }
}

double Utils::get_last_time(std::string timer){
    if (last.find(timer) != last.end())
    {
        return last[timer];
    }
    return 0.0;
}
double Utils::get_total_time(std::string timer){
    if (total.find(timer) != total.end())
    {
        return total[timer];
    }
    return 0.0;
}
double Utils::get_prom_time(std::string timer){
    if (total.find(timer) != total.end())
    {
        if (count.find(timer) != count.end())
        {
            return total[timer]/count[timer];
        }
    }
    return 0.0;
}

unsigned long Utils::getMemFree() {
    std::string token;
    std::ifstream file("/proc/meminfo");
    while(file >> token) {
        if(token == "MemFree:") {
            unsigned long mem;
            if(file >> mem) {
                return mem;
            } else {
                return 0;
            }
        }
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return 0;
}

unsigned long Utils::getMemAvailable() {
    std::string token;
    std::ifstream file("/proc/meminfo");
    while(file >> token) {
        if(token == "MemAvailable:") {
            unsigned long mem;
            if(file >> mem) {
                return mem;
            } else {
                return 0;
            }
        }
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return 0;
}

unsigned long Utils::getCPUFrequency() {
    std::ifstream file("/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq");
    unsigned long mem;
    if(file >> mem) return mem;
    return 0;
}
