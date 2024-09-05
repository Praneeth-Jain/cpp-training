#include <iostream>
#include <cwchar>

int main() {
    wchar_t hindiWord[] = L"नमस्ते"; 
    std::wcout << L"Hindi Word: " << hindiWord << std::endl;
    std::wcout << L"Size of wchar_t: " << sizeof(wchar_t) << " bytes" << std::endl;
    return 0;
}
