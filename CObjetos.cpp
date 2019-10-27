#include "CObjetos.h"
CObjetos::CObjetos() {}

CObjetos::CObjetos(string pNombre,char pColor, int pPosX, int pPosY):m_Nombre{pNombre}, m_Color{pColor}, m_PosX{pPosX}, m_PosY{pPosY} {
}
CObjetos::CObjetos(string pNombre, char pColor):m_Nombre{pNombre}, m_Color{pColor} {
}
CObjetos::~CObjetos() {}
void CObjetos::setNombre(char pNombre) { this->m_Nombre = pNombre; }
void CObjetos::moverse(int pPosX, int pPosY) {} //--  por implementar
string  CObjetos::getNombre() { return m_Nombre; }
char CObjetos::getColor()  { return m_Color; }
int   CObjetos::getPosX()   { return m_PosX; }
int   CObjetos::getPosY()   { return m_PosY; }
string CObjetos::getPosicion() {
    return "X = " + to_string(m_PosX) + " Y = " + to_string(m_PosY);
}

