# Obfuscated-Keylogger-In-C
An obfuscated keylogger built in C. Test out your cybersecurity skills, build and share



Keylogger for Educational Purposes
This is a keylogger tool written in C, designed to monitor and log keystrokes for educational and ethical hacking purposes only. It is intended to help users understand how keyloggers work and how they can be used to study attacker techniques in a controlled, authorized environment. This tool should never be used for illegal activities.

Purpose
The main objective of this project is to serve as a learning tool for cybersecurity professionals and students to understand keylogging techniques and the importance of securing systems against such threats.

This keylogger can be used to study how input is captured, logged, and how attackers might exploit systems. It should only be used in ethical hacking scenarios where you have explicit permission to test systems.

Important Disclaimer
This keylogger is for educational purposes only!

You must have explicit permission to use this tool on any system. Unauthorized use of this tool is illegal and unethical. The creator of this code is not responsible for any misuse or harm caused by the use of this tool.

By using this code, you agree to use it responsibly and only in environments where you have authorization to do so. Misuse of this code may result in legal consequences.

Use Cases
Ethical hacking: For penetration testers and cybersecurity professionals who have permission to assess the security of a system.

Learning tool: For understanding how keyloggers work and exploring defensive measures against them.

Features
Keystroke Logging: Logs all keystrokes to a file.

Shift and Caps Lock Handling: Correctly captures shifted and capitalized characters based on the system’s state.

Special Character Handling: Recognizes shifted numeric and punctuation characters (e.g., !, @, etc.).

Invisible Operation: The program hides its window and runs in the background to emulate real-world keylogging scenarios.

Requirements
Windows Operating System (This code uses the Windows API)

A C compiler (e.g., MinGW, Visual Studio)

Installation
Download the code from this repository.

Compile the C code using your preferred C compiler (e.g., GCC, MSVC).

For MinGW, use the following command in your terminal:

gcc -o keylogger keylogger.c
Run the executable. It will hide its console window and begin logging keystrokes to a file named log.txt in the same directory.

Usage
Once compiled and run, the keylogger will:

Capture keystrokes and write them to log.txt.

Log all keystrokes, including shifted keys and special characters.

Continuously monitor key events in a loop until the program is manually terminated.

How to Stop the Program
To stop the keylogger, terminate the process manually:

Open Task Manager (Ctrl + Shift + Esc).

Find the process named keylogger.exe in the list.

Right-click and select End Task.

License
This project is licensed under the MIT License.

You are free to use, modify, and distribute this code, but you must provide appropriate credit and not use it for malicious purposes.

MIT License

Copyright (c) 2025 [Your Name]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
Acknowledgements
Windows API: For providing the necessary functions to detect key events and handle keyboard inputs.

C Programming Language: The code is written in C for educational purposes, as it’s widely used in cybersecurity and low-level programming.

Ethical Use Reminder
This tool must not be used for any activities that violate privacy, ethics, or the law. You are responsible for ensuring that you have proper authorization before using this tool on any systems.

Additional Notes
You can modify this README further depending on the details of your project, or add specific features and instructions you’d like to highlight.

It's important to make it clear that the keylogger is for learning purposes and should never be used for unauthorized surveillance or hacking.
