#include <windows.h>
#include <stdio.h>

const char g_szClassName[] = "myWindowClass";

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {   case WM_CREATE:
        CreateWindow(TEXT("button"), TEXT("On"),
                 WS_VISIBLE | WS_CHILD ,
                 20, 30, 80, 25,
                 hwnd, (HMENU) 1, NULL, NULL);
        CreateWindow(TEXT("button"), TEXT("Off"),
                 WS_VISIBLE | WS_CHILD ,
                 120, 30, 80, 25,
                 hwnd, (HMENU) 2, NULL, NULL);
        CreateWindow(TEXT("button"), TEXT("Blink"),
                 WS_VISIBLE | WS_CHILD ,
                 70, 70, 80, 25,
                 hwnd, (HMENU) 3, NULL, NULL);
        break;
        case WM_COMMAND:
        if (LOWORD(wParam) == 1) {
            printf("Button 1 clicked.\n");

            // Define the bytes you want to send, lookup ASCII table for this
            char bytes_to_send[1];
            bytes_to_send[0] = 49;

            // Declare variables and structures
            HANDLE hSerial;
            DCB dcbSerialParams = {0};
            COMMTIMEOUTS timeouts = {0};

            // Open the highest available serial port number
            fprintf(stderr, "Opening serial port...");
            hSerial = CreateFile(
                        "\\\\.\\COM10", GENERIC_READ|GENERIC_WRITE, 0, NULL,
                        OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL );
            if (hSerial == INVALID_HANDLE_VALUE)
            {
                fprintf(stderr, "Error\n");
                return 1;
            }
            else fprintf(stderr, "OK\n");

            // Set device parameters (38400 baud, 1 start bit,
            // 1 stop bit, no parity)
            dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
            if (GetCommState(hSerial, &dcbSerialParams) == 0)
            {
                fprintf(stderr, "Error getting device state\n");
                CloseHandle(hSerial);
                return 1;
            }

            dcbSerialParams.BaudRate = CBR_9600;
            dcbSerialParams.ByteSize = 8;
            dcbSerialParams.StopBits = ONESTOPBIT;
            dcbSerialParams.Parity = NOPARITY;
            if(SetCommState(hSerial, &dcbSerialParams) == 0)
            {
                fprintf(stderr, "Error setting device parameters\n");
                CloseHandle(hSerial);
                return 1;
            }

            // Set COM port timeout settings
            timeouts.ReadIntervalTimeout = 50;
            timeouts.ReadTotalTimeoutConstant = 50;
            timeouts.ReadTotalTimeoutMultiplier = 10;
            timeouts.WriteTotalTimeoutConstant = 50;
            timeouts.WriteTotalTimeoutMultiplier = 10;
            if(SetCommTimeouts(hSerial, &timeouts) == 0)
            {
                fprintf(stderr, "Error setting timeouts\n");
                CloseHandle(hSerial);
                return 1;
            }

            // Send specified text (remaining command line arguments)
            DWORD bytes_written, total_bytes_written = 0;
            fprintf(stderr, "Sending bytes...");
            if(!WriteFile(hSerial, bytes_to_send, 1, &bytes_written, NULL))
            {
                fprintf(stderr, "Error\n");
                CloseHandle(hSerial);
                return 1;
            }
            fprintf(stderr, "%d bytes written\n", bytes_written);

            // Close serial port
            fprintf(stderr, "Closing serial port...");
            if (CloseHandle(hSerial) == 0)
            {
                fprintf(stderr, "Error\n");
                return 1;
            }
            fprintf(stderr, "OK\n");

            // exit normally
            return 0;

        }
        if (LOWORD(wParam) == 2) {
            printf("Button 2 clicked.\n");

            // Define the bytes you want to send, lookup ASCII table for this
            char bytes_to_send[1];
            bytes_to_send[0] = 50;

            // Declare variables and structures
            HANDLE hSerial;
            DCB dcbSerialParams = {0};
            COMMTIMEOUTS timeouts = {0};

            // Open the highest available serial port number
            fprintf(stderr, "Opening serial port...");
            hSerial = CreateFile(
                        "\\\\.\\COM10", GENERIC_READ|GENERIC_WRITE, 0, NULL,
                        OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL );
            if (hSerial == INVALID_HANDLE_VALUE)
            {
                fprintf(stderr, "Error\n");
                return 1;
            }
            else fprintf(stderr, "OK\n");

            // Set device parameters (38400 baud, 1 start bit,
            // 1 stop bit, no parity)
            dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
            if (GetCommState(hSerial, &dcbSerialParams) == 0)
            {
                fprintf(stderr, "Error getting device state\n");
                CloseHandle(hSerial);
                return 1;
            }

            dcbSerialParams.BaudRate = CBR_9600;
            dcbSerialParams.ByteSize = 8;
            dcbSerialParams.StopBits = ONESTOPBIT;
            dcbSerialParams.Parity = NOPARITY;
            if(SetCommState(hSerial, &dcbSerialParams) == 0)
            {
                fprintf(stderr, "Error setting device parameters\n");
                CloseHandle(hSerial);
                return 1;
            }

            // Set COM port timeout settings
            timeouts.ReadIntervalTimeout = 50;
            timeouts.ReadTotalTimeoutConstant = 50;
            timeouts.ReadTotalTimeoutMultiplier = 10;
            timeouts.WriteTotalTimeoutConstant = 50;
            timeouts.WriteTotalTimeoutMultiplier = 10;
            if(SetCommTimeouts(hSerial, &timeouts) == 0)
            {
                fprintf(stderr, "Error setting timeouts\n");
                CloseHandle(hSerial);
                return 1;
            }

            // Send specified text (remaining command line arguments)
            DWORD bytes_written, total_bytes_written = 0;
            fprintf(stderr, "Sending bytes...");
            if(!WriteFile(hSerial, bytes_to_send, 1, &bytes_written, NULL))
            {
                fprintf(stderr, "Error\n");
                CloseHandle(hSerial);
                return 1;
            }
            fprintf(stderr, "%d bytes written\n", bytes_written);

            // Close serial port
            fprintf(stderr, "Closing serial port...");
            if (CloseHandle(hSerial) == 0)
            {
                fprintf(stderr, "Error\n");
                return 1;
            }
            fprintf(stderr, "OK\n");

            // exit normally
            return 0;

        }
        if (LOWORD(wParam) == 3) {
            printf("Button 3 clicked.\n");

            // Define the bytes you want to send, lookup ASCII table for this
            char bytes_to_send[1];
            bytes_to_send[0] = 51;

            // Declare variables and structures
            HANDLE hSerial;
            DCB dcbSerialParams = {0};
            COMMTIMEOUTS timeouts = {0};

            // Open the highest available serial port number
            fprintf(stderr, "Opening serial port...");
            hSerial = CreateFile(
                "\\\\.\\COM10", GENERIC_READ|GENERIC_WRITE, 0, NULL,
                OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL );
            if (hSerial == INVALID_HANDLE_VALUE)
            {
                fprintf(stderr, "Error\n");
                return 1;
            }
            else fprintf(stderr, "OK\n");

            // Set device parameters (38400 baud, 1 start bit,
            // 1 stop bit, no parity)
            dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
            if (GetCommState(hSerial, &dcbSerialParams) == 0)
            {
                fprintf(stderr, "Error getting device state\n");
                CloseHandle(hSerial);
                return 1;
            }

            dcbSerialParams.BaudRate = CBR_9600;
            dcbSerialParams.ByteSize = 8;
            dcbSerialParams.StopBits = ONESTOPBIT;
            dcbSerialParams.Parity = NOPARITY;
            if(SetCommState(hSerial, &dcbSerialParams) == 0)
            {
                fprintf(stderr, "Error setting device parameters\n");
                CloseHandle(hSerial);
                return 1;
            }

            // Set COM port timeout settings
            timeouts.ReadIntervalTimeout = 50;
            timeouts.ReadTotalTimeoutConstant = 50;
            timeouts.ReadTotalTimeoutMultiplier = 10;
            timeouts.WriteTotalTimeoutConstant = 50;
            timeouts.WriteTotalTimeoutMultiplier = 10;
            if(SetCommTimeouts(hSerial, &timeouts) == 0)
            {
                fprintf(stderr, "Error setting timeouts\n");
                CloseHandle(hSerial);
                return 1;
            }

            // Send specified text (remaining command line arguments)
            DWORD bytes_written, total_bytes_written = 0;
            fprintf(stderr, "Sending bytes...");
            if(!WriteFile(hSerial, bytes_to_send, 1, &bytes_written, NULL))
            {
                fprintf(stderr, "Error\n");
                CloseHandle(hSerial);
                return 1;
            }
            fprintf(stderr, "%d bytes written\n", bytes_written);

            // Close serial port
            fprintf(stderr, "Closing serial port...");
            if (CloseHandle(hSerial) == 0)
            {
                fprintf(stderr, "Error\n");
                return 1;
            }
            fprintf(stderr, "OK\n");

            // exit normally
            return 0;

        }

        break;
        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        "CDuino",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 240, 160,
        NULL, NULL, hInstance, NULL);

    if(hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while(GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}
