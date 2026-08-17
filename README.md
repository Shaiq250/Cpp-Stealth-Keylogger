# C++ Stealth Keylogger

![C++](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=c%2B%2B)
![Platform](https://img.shields.io/badge/Platform-Windows-0078D6?style=for-the-badge&logo=windows)
![Security](https://img.shields.io/badge/Security-Red%20Team-red?style=for-the-badge)

> [!CAUTION]
> **LEGAL & ETHICAL WARNING**
>
> This software is a **Proof of Concept (PoC)** developed for educational purposes to demonstrate how keystroke logging malware operates on Windows systems.
>
> *   **Do not use this software for malicious purposes.**
> *   Deploying this tool on a system without the owner's explicit consent is a **criminal offense** (e.g., Computer Fraud and Abuse Act in the US).
> *   This project is intended for **Cybersecurity Research** to help security professionals understand detection signatures and malware behavior.

---

## 🔍 Project Overview

It is a lightweight, stealthy keylogger written in C++. Unlike high-level language implementations (like Python), this C++ version demonstrates how malware operates closer to the OS level with minimal dependencies, making it faster and harder to detect by simple heuristic analysis.

It is designed to run in the background, minimizing the console window to remain invisible to the victim while logging all keyboard input to a local file.

## ⚙️ Features

*   **Stealth Mode**: Automatically hides the console window (`ShowWindow(SW_HIDE)`) upon execution to run invisibly.
*   **Keystroke Capture**: Intercepts all global keyboard events using the Windows API (`GetAsyncKeyState`).
*   **Special Key Support**: Maps virtual key codes to readable text (e.g., `[ENTER]`, `[CAPS_LOCK]`, `[BACKSPACE]`).
*   **Context Awareness**: (Experimental) Attempts to detect if the user is typing in a Username or Password field based on navigation patterns (Enter/Tab keys).
*   **Low Footprint**: Minimal resource usage compared to Python-based agents.

## 🛠️ Technical Details

The core loop iterates through ASCII values (8-190) to check the state of every key.
*   **API Used**: `Windows.h` (WinAPI)
*   **Persistence**: (None in this version - runs while active).
*   **Output**: Appends logs to `file.txt` in the same directory.

## 🚀 Usage (Lab Only)

1.  **Compile the Code**:
    You can use any C++ compiler (MinGW, Visual Studio).
    ```bash
    g++ Project.cpp -o Project.exe
    ```

2.  **Run the Executable**:
    Double-click `Project.exe`.
    *The window will likely flash and disappear immediately (Stealth Mode).*

3.  **Check Logs**:
    Open `file.txt` to see the captured keystrokes.

4.  **Stop the Process**:
    Since the window is hidden, you must terminate it via Task Manager or Command Prompt:
    ```bash
    taskkill /F /IM Project.exe
    ```

## 🛡️ Detection & Defense

To defend against such tools, Blue Teams should monitor for:
*   **Unsigned Binaries**: Executables running from temporary folders without digital signatures.
*   **API Hooking**: Processes repeatedly calling `GetAsyncKeyState` or `SetWindowsHookEx`.
*   **Hidden Processes**: Processes with hidden windows consuming CPU time.

## 📝 License

**Educational Use Only**. No license is provided for malicious use.
