#include <iostream>
#include <windows.h>

int main() {
    MEMORYSTATUSEX memoryInfo;
    memoryInfo.dwLength = sizeof(memoryInfo);

    if (GlobalMemoryStatusEx(&memoryInfo)) {
        std::cout << "Total physical memory: " << memoryInfo.ullTotalPhys << " bytes" << std::endl;
        std::cout << "Available physical memory: " << memoryInfo.ullAvailPhys << " bytes" << std::endl;
        std::cout << "Total virtual memory: " << memoryInfo.ullTotalVirtual << " bytes" << std::endl;
        std::cout << "Available virtual memory: " << memoryInfo.ullAvailVirtual << " bytes" << std::endl;
    } else {
        std::cerr << "GlobalMemoryStatusEx failed." << std::endl;
    }

    return 0;
}

