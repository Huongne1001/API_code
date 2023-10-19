#include <windows.h>
#include <iostream>
using namespace std;

int main() {
    //khai báo một con trỏ kiểu LPCWSTR với giá trị là đường dẫn của tệp mới
    LPCWSTR path = L"E:\\Hello\\haha.txt"; 

    // Tạo một tệp mới sử dụng CreateFile API
    HANDLE hFile = (CreateFile(
        path,    //Tên của tệp mới.
        GENERIC_READ|GENERIC_WRITE, //Quyền truy cập mong muốn cho tệp mới
        FILE_SHARE_READ,        //Chế độ chia sẻ cho tệp mới.         
        NULL,               //Thông tin bảo mật cho tệp mới
        CREATE_NEW,         // Cách thức tạo tệp mới.
        FILE_ATTRIBUTE_NORMAL, //Thuộc tính cho tệp mới.
        NULL));                //Tệp mẫu
    
    
    if (hFile == INVALID_HANDLE_VALUE) {
        std::cout << "Khong the tao tep! Loi: " << GetLastError() << std::endl;
    }
    else {
        std::cout << "Tep da duoc tao thanh cong!" << std::endl;
        CloseHandle(hFile);
    }
    return 0;
}
