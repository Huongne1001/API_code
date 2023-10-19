#include <windows.h>
#include <tchar.h>
#include <stdio.h>

int _tmain(int argc, _TCHAR* argv[])
{
    // Ten tep tin , ung dung muon khoi chay 
    _TCHAR szApplicationName[] = _T("notepad.exe");

    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    // Khoi tao cau truc STARTUPINFO
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);

    // Goi ham CreateProcess de khoi chay ung dung 
    if (CreateProcess(NULL, szApplicationName, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
    {
        printf("Ung dung duoc khoi chay thanh cong!\n");

        // Ðoi cho tien trinh ket thuc 
        WaitForSingleObject(pi.hProcess, INFINITE);

        // Dong cac handle da mo 
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
    else
    {
        printf("Khong the khoi chay ung dung.Ma loi: %d\n", GetLastError());
    }

    return 0;
}

