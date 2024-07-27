#include "pch.h"
#include <windows.h>

#pragma region Global Variables

#define MAX_NAME_STRING 100

WCHAR WindowClass[MAX_NAME_STRING];
WCHAR WindowTitle[MAX_NAME_STRING];

INT WindowWidth;
INT WindowHeight;

HICON hIcon;

#pragma endregion

#pragma region PreDeclarations

VOID InitialiseVariables();
VOID CreateWindowClass();
VOID InitialiseWindow();
VOID MessageLoop();

LRESULT CALLBACK WindowProcess(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

#pragma endregion

#pragma region Operations

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT nCmdShow)
{
    InitialiseVariables();
    CreateWindowClass();
    InitialiseWindow();
    MessageLoop();

    return 0;
}

LRESULT CALLBACK WindowProcess(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

#pragma endregion

#pragma region Functions

VOID InitialiseVariables()
{
    LoadString(HInstance(), IDS_PERGAMENAME, WindowTitle, MAX_NAME_STRING);
    LoadString(HInstance(), IDS_WINDOWCLASS, WindowClass, MAX_NAME_STRING);

    WindowWidth = 1366;
    WindowHeight = 768;
    hIcon = LoadIcon(HInstance(), MAKEINTRESOURCE(IDI_MAINICON));
}

VOID CreateWindowClass()
{
    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WindowProcess;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = HInstance();
    wcex.hIcon = hIcon;
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = WindowClass;
    wcex.hIconSm = hIcon;

    RegisterClassEx(&wcex);
}

VOID InitialiseWindow()
{
    HWND hWnd = CreateWindow(WindowClass, WindowTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, WindowWidth, WindowHeight, nullptr, nullptr, HInstance(), nullptr);
    if (!hWnd)
    {
        MessageBox(0, L"Failed to Create Window!.", 0, 0);
        PostQuitMessage(0);
    }
}

VOID MessageLoop()
{
    MSG msg = { 0 };
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

#pragma endregion
