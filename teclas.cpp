//
// Created by jessica on 28/10/19.
//
void gotoxy(int x, int y){

    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;

    SetConsoleCursorPosition(hCon, dwPos);
}

void Hide_Cursor(){

    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cci;

    cci.dwSize = 100;
    cci.bVisible = FALSE;

    SetConsoleCursorInfo(hCon, &cci);
}
