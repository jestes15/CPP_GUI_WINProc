// HelloWindowsDesktop.cpp
// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c


#include "Main.h"
#include "secondary.h"
#pragma warning(suppress : 4996)

//Entry point for the program
int CALLBACK WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    WNDCLASSEX wcex;
    //GdiplusStartupInput gdiplusStartupInput;
    //ULONG_PTR           gdiplusToken;

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
    RECT tp;

    std::wstring left_str(L"Left: "), right_str(L"Right: "), top_str(L"Top: "), bottom_str(L"Bottom: "), rand_int_str(L"Your random number is"), menu,
        left_num, right_num, top_num, bottom_num, rand_int, left, right, top, bottom,
        random_int;

    TCHAR* left_raw, *right_raw, *top_raw, *bottom_raw, *rand_int_msg, *msg;
    TCHAR usr_msg[] = L"I hope you like it!";

    switch (message)
    {
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        SetBkMode(hdc, TRANSPARENT);

        GetClientRect(hWnd, &lp);
        GetClientRect(hWnd, &tp);

        //Define the rectangle to draw the menu on
        tp.left = 5;
        tp.top = 135;
        tp.right = 289;
        tp.bottom = 412;

        menu = get_wstring(1);

        left_num = std::to_wstring(lp.left);
        right_num = std::to_wstring(lp.right);
        top_num = std::to_wstring(lp.top);
        bottom_num = std::to_wstring(lp.bottom);
        rand_int = std::to_wstring(randomInteger());

        left = left_str + left_num;
        right = right_str + right_num;
        top = top_str + top_num;
        bottom = bottom_str + bottom_num;
        random_int = rand_int + rand_int;

        left_raw = (TCHAR*)left.c_str();
        right_raw = (TCHAR*)right.c_str();
        top_raw = (TCHAR*)top.c_str();
        bottom_raw = (TCHAR*)bottom.c_str();
        rand_int_msg = (TCHAR*)random_int.c_str();


        msg = (TCHAR*)menu.c_str();

        // Here your application is laid out.
        // For this introduction, we just print out "Hello, Windows desktop!"
        // in the top left corner.

        TextOut(hdc, 5, 5, left_raw, _tcslen(left_raw));
        TextOut(hdc, 5, 20, right_raw, _tcslen(right_raw));
        TextOut(hdc, 5, 35, top_raw, _tcslen(top_raw));
        TextOut(hdc, 5, 50, bottom_raw, _tcslen(bottom_raw));
        TextOut(hdc, 5, 65, rand_int_msg, _tcslen(rand_int_msg));

        TextOut(hdc, 5, 95, usr_msg, _tcslen(usr_msg));

        //Work in progress
        /*
        Image image(L"Grapes.jpg");
        graphics.DrawImage(&image, 60, 10);

        HICON hIcon = LoadIcon(NULL, IDI_APPLICATION);
        Bitmap bitmap(hIcon);
        graphics.DrawImage(&bitmap, 10, 10);

        SendMessage(hWnd, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hImage);
        */

        DrawText(hdc, msg, -1, &tp, DT_INTERNAL | DT_LEFT | DT_VCENTER | DT_NOCLIP);

        // End application-specific layout section.
        if (!diag_num)
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
                    TextOut(hdc, 5, 110, usr_error_box_msg, _tcslen(usr_error_box_msg));
                }
                diag_num = 1;

                return msgboxID;
            }
        }
        if (diag_num)
        {
            TCHAR usr_error_box_msg[] = L"Agreed to terms and conditions";
            TextOut(hdc, 5, 110, usr_error_box_msg, _tcslen(usr_error_box_msg));
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