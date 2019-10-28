//
// Created by jessica on 27/10/19.
//

#include "auto.h"
AUTO::AUTO(int x, int y, int salud, int num_vidas){
    this->x=x;
    this->y=y;
    this->salud=salud;
    this->num_vidas=num_vidas;
}
void AUTO::pintar() { }
void AUTO::mover(int x, int y) {

    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;

    SetConsoleCursorPosition(hCon, dwPos);

}
    void AUTO::Hide_Cursor() {

        HANDLE hCon;
        hCon = GetStdHandle(STD_OUTPUT_HANDLE);

        CONSOLE_CURSOR_INFO cci;

        cci.dwSize = 100;
        cci.bVisible = FALSE;
    }

void AUTO::borrar() { }
void AUTO::salud_() { }
void AUTO::muerte() { }
