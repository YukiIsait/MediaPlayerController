#include <Windows.h>

void SendKey(WORD key) {
    INPUT inputs[2] = { 0 };
    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wVk = key;
    inputs[1].type = INPUT_KEYBOARD;
    inputs[1].ki.wVk = key;
    inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
}

void ShowUsage() {
    MessageBoxW(NULL, L"Usage: MediaPlayerController.exe <prev-track|next-track|play-pause|stop>", L"Error", MB_ICONERROR);
}

int Main(int argumentCount, LPWSTR* argumentVector) {
    if (argumentCount < 2) {
        ShowUsage();
        return 1;
    }
    if (lstrcmpW(argumentVector[1], L"prev-track") == 0) {
        SendKey(VK_MEDIA_PREV_TRACK);
    } else if (lstrcmpW(argumentVector[1], L"next-track") == 0) {
        SendKey(VK_MEDIA_NEXT_TRACK);
    } else if (lstrcmpW(argumentVector[1], L"play-pause") == 0) {
        SendKey(VK_MEDIA_PLAY_PAUSE);
    } else if (lstrcmpW(argumentVector[1], L"stop") == 0) {
        SendKey(VK_MEDIA_STOP);
    } else {
        ShowUsage();
        return 1;
    }
    return 0;
}
