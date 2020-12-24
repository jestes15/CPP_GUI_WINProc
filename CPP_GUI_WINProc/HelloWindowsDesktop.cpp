// HelloWindowsDesktop.cpp
// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c


#include "Main.h"
#pragma warning(suppress : 4996)

//Entry point for the program
int CALLBACK WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_BACKGROUND + 3);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

    if (!RegisterClassEx(&wcex))
    {
        MessageBox(NULL,
            _T("Call to RegisterClassEx failed!"),
            _T("My First GUI Application"),
            NULL);

        return 1;
    }

    // Store instance handle in our global variable
    hInst = hInstance;

    // The parameters to CreateWindow explained:
    // szWindowClass: the name of the application
    // szTitle: the text that appears in the title bar
    // WS_OVERLAPPEDWINDOW: the type of window to create
    // CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
    // 500, 100: initial size (width, length)
    // NULL: the parent of this window
    // NULL: this application does not have a menu bar
    // hInstance: the first parameter from WinMain
    // NULL: not used in this application
    HWND hWnd = CreateWindow(
        szWindowClass,
        szTitle,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        500, 500,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (!hWnd)
    {
        MessageBox(NULL,
            _T("Call to CreateWindow failed!"),
            _T("My First GUI Application"),
            NULL);

        return 1;
    }

    // The parameters to ShowWindow explained:
    // hWnd: the value returned from CreateWindow
    // nCmdShow: the fourth parameter from WinMain
    ShowWindow(hWnd,
        nCmdShow);
    UpdateWindow(hWnd);

    // Main message loop:
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;

    RECT lp;
    HWND Window = GetConsoleWindow();
    GetWindowRect(Window, &lp);

    std::wstring left_str(L"Left: ");
    std::wstring right_str(L"Right: ");
    std::wstring top_str(L"Top: ");
    std::wstring bottom_str(L"Bottom: ");

    std::wstring left_num = std::to_wstring(lp.left);
    std::wstring right_num = std::to_wstring(lp.right);
    std::wstring top_num = std::to_wstring(lp.top);
    std::wstring bottom_num = std::to_wstring(lp.bottom);

    std::wstring left_combined = left_str + left_num;
    std::wstring right_combined = right_str + right_num;
    std::wstring top_combined = top_str + top_num;
    std::wstring bottom_combined = bottom_str + bottom_num;

    TCHAR* left_raw = (TCHAR*)left_combined.c_str();
    TCHAR* right_raw = (TCHAR*)right_combined.c_str();
    TCHAR* top_raw = (TCHAR*)top_combined.c_str();
    TCHAR* bottom_raw = (TCHAR*)bottom_combined.c_str();

    TCHAR usr_msg[] = L"I hope you like it!";

    switch (message)
    {
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        SetBkMode(hdc, TRANSPARENT);

        // Here your application is laid out.
        // For this introduction, we just print out "Hello, Windows desktop!"
        // in the top left corner.

        TextOut(hdc, 5, 5, left_raw, _tcslen(left_raw));
        TextOut(hdc, 5, 20, right_raw, _tcslen(right_raw));
        TextOut(hdc, 5, 35, top_raw, _tcslen(top_raw));
        TextOut(hdc, 5, 50, bottom_raw, _tcslen(bottom_raw));

        TextOut(hdc, 5, 95, usr_msg, _tcslen(usr_msg));
        // End application-specific layout section.
        if (!Num)
        {
            int DisplayConfirmSaveAsMessageBox();
            {
                int msgboxID = MessageBox(
                    NULL,
                    L"Please Agree to the terms and conditions\nPress OK to continue",
                    L"Terms and Conditions Agreement",
                    MB_ICONEXCLAMATION | MB_OK
                );

                if (msgboxID == IDOK)
                {
                    TCHAR usr_error_box_msg[] = L"Agreed to terms and conditions";
                    TextOut(hdc, 5, 200, usr_error_box_msg, _tcslen(usr_error_box_msg));
                }
                Num = 1;

                return msgboxID;
            }
        }
        if (Num)
        {
            TCHAR usr_error_box_msg[] = L"Agreed to terms and conditions";
            TextOut(hdc, 5, 200, usr_error_box_msg, _tcslen(usr_error_box_msg));
        }

        EndPaint(hWnd, &ps);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        break;
    }

    return 0;
}