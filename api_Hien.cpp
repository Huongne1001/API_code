#include <windows.h>

int main() {
    HWND hwnd = 0; // Thay doi gia tri nay neu ban muon hop thoai duoc gan lien voi cua so cu the
    LPCSTR message = "Chao mung ban den voi vi du ve ham API trong Windows!";
    LPCSTR title = "Vi du MessageBox";
    UINT type = MB_OK | MB_ICONINFORMATION;

    MessageBox(hwnd, message, title, type);

    return 0;
}
