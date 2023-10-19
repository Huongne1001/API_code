#include <windows.h>
#include <iostream>

int main() {
    HANDLE hThread = GetCurrentThread(); // Lay handle cua luong hien tai

    FILETIME creationTime, exitTime, kernelTime, userTime;

    if (GetThreadTimes(hThread, &creationTime, &exitTime, &kernelTime, &userTime)) {
        // Chuyen doii FILETIME thành 64-bit integer (FILETIME thuong duoc bieu dien duoi dang 2 32-bit integers)
        ULONGLONG kernelTimeInTicks = ((ULONGLONG)kernelTime.dwHighDateTime << 32) | kernelTime.dwLowDateTime;
        ULONGLONG userTimeInTicks = ((ULONGLONG)userTime.dwHighDateTime << 32) | userTime.dwLowDateTime;

        // Chuyen doi thoi gian tu ticks sang milliseconds hoacc seconds neu can
        double kernelTimeInSeconds = kernelTimeInTicks / 10000000.0; // 1 tick = 100 nanoseconds
        double userTimeInSeconds = userTimeInTicks / 10000000.0;

        std::cout << "Thoi gian thuc hien cong viec o cap do kernel: " << kernelTimeInSeconds << " giay" << std::endl;
        std::cout << "Thoi gian thuc hien cong viec o cap do nguoi dung: " << userTimeInSeconds << "giay" << std::endl;
    } else {
        std::cerr << "Loi khi goi GetThreadTimes" << std::endl;
    }

    return 0;
}

