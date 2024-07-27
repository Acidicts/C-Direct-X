#include "Olympus.h"

INT CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT nCmdShow)
{
    InitialiseVariables();
    CreateWindowClass();
    InitialiseWindow();
    MessageLoop();

    return 0;
}