#pragma once

#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <tchar.h>
#include <atlstr.h>
#include <objidl.h>
#include <gdiplus.h>

// Global variables
int diag_num = 0;

// The main window class name.
static TCHAR szWindowClass[] = _T("DesktopApp");

// The string that appears in the application's title bar.
static TCHAR szTitle[] = _T("My First GUI Application");

HINSTANCE hInst;
HBITMAP hImage;

// Forward declarations of functions included in this code module:
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//The default size for an array created in this program
constexpr auto size_of_array = 1000;

//A Random number generator function
int randomInteger();