#define _WIN32_WINNT 0x0501 // Supports Windows XP and later
#include <windows.h>

// Function prototypes
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

// Entry point
int main() {
    // Initialize the window class
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProcedure;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "ExampleWindowClass";

    // If not registered show error
    if (!RegisterClass(&wc)) {
        MessageBox(NULL, "Window class registration failed!", "Error", MB_OK | MB_ICONERROR);
        return 1;
    }

    // Create the window
    HWND hwnd = CreateWindow(
        wc.lpszClassName, "Example", WS_OVERLAPPEDWINDOW, 
        CW_USEDEFAULT, CW_USEDEFAULT, 300, 200, 
        NULL, NULL, wc.hInstance, NULL
    );

    if (hwnd == NULL) {
        MessageBox(NULL, "Window creation failed!", "Error", MB_OK | MB_ICONERROR);
        return 1;
    }

     CreateWindow("STATIC", "Example", WS_VISIBLE | WS_CHILD, 
                 100, 50, 100, 30, hwnd, NULL, wc.hInstance, NULL);

    // Create buttons
    CreateWindow("BUTTON", "OK", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 
                 50, 100, 80, 30, hwnd, (HMENU)1, wc.hInstance, NULL);
    CreateWindow("BUTTON", "Cancel", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
                 150, 100, 80, 30, hwnd, (HMENU)2, wc.hInstance, NULL);


    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);


    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

// Window procedure to handle messages
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        case WM_COMMAND:

            break;
        default:
            return DefWindowProc(hwnd, msg, wp, lp);
    }
    return 0;
}
