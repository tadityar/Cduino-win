#include <windows.h>
#include <stdio.h>

int main()
{
	FILE *fp;
	//this is my file but I don't think you'll have a folder called Sharmin in your
	//computer cos that would be super creepy.
	//change it to the full path of the file you want to save the values to.
	fp = fopen("C:/Users/Sharmin/Documents/eHealth_Pulse.txt", "a");

    // Declare variables and structures
    HANDLE hSerial;
    DCB dcbSerialParams = {0};
    COMMTIMEOUTS timeouts = {0};

    // Open the highest available serial port number
    fprintf(stderr, "Opening serial port...");
    hSerial = CreateFile(
                "\\\\.\\COM8", GENERIC_READ|GENERIC_WRITE, 0, NULL,
                OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL );
    if (hSerial == INVALID_HANDLE_VALUE)
    {
            fprintf(stderr, "Error\n");
            return 1;
    }
    else fprintf(stderr, "OK\n");

    // Set device parameters (9600 baud, 1 start bit,
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

    // Read text
    DWORD dwRead;
    DWORD dwCommEvent;
    char bytes_to_read[200];
    int i;

        fprintf(stderr, "Reading bytes...\n");
        Sleep(30000);
        if(!ReadFile(hSerial, bytes_to_read, 200, &dwRead, NULL))
        {
            fprintf(stderr, "Error\n");
            CloseHandle(hSerial);
            return 1;
        }
        for (i = 0; i <= 199; i++){
            char c = bytes_to_read[i];
            fprintf(fp, "%c", c);
        }
        fprintf(fp, "\n");

    /*fprintf(stderr, "Reading bytes...\n");
        //Sleep(500);
        if(!ReadFile(hSerial, bytes_to_read, 3, &dwRead, NULL))
        {
            fprintf(stderr, "Error\n");
            CloseHandle(hSerial);
            return 1;
        }
        else {
            for (i = 0; i <= 3; i++){
            char c = bytes_to_read[i];
            fprintf(stderr, "%c", c);
        }
        }
        fprintf(stderr, "\n");*/
    // Close serial port
    fprintf(stderr, "Closing serial port...");
    if (CloseHandle(hSerial) == 0)
    {
        fprintf(stderr, "Error\n");
        return 1;
    }
    fprintf(stderr, "OK\n");
    fclose(fp);
    // exit normally
    return 0;
}
