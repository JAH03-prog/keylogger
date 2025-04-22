# 🖥️ C++ Keylogger (Windows Only)

This is a simple Windows-based keylogger written in C++ that captures and logs keystrokes into a file named `Keylogs`. It uses the Windows API to hook into low-level keyboard events and store readable key presses in plain text format.

---

## 🚧 Disclaimer

> ⚠️ This tool is for **educational** and **ethical testing purposes only**.  
> Unauthorized use of keylogging software can violate privacy laws and terms of service.  
> The author is not responsible for any misuse of this code.

---

## 🛠 Features

- Logs common keystrokes like letters, numbers, Enter, Tab, Backspace, and Ctrl
- Saves output to a file named `Keylogs` in the working directory
- Runs silently in the background
- Written in native WinAPI for minimal dependencies

---

## 📄 How It Works

- Uses `SetWindowsHookEx()` to register a low-level keyboard hook.
- On each `WM_KEYDOWN` event, it logs the key to a file via `ofstream`.
- Captures special keys and displays them in `[KEY]` format.

---

## 🧩 Code Highlights

```cpp
SetWindowsHookEx(WH_KEYBOARD_LL, keyboardProc, NULL, 0);
