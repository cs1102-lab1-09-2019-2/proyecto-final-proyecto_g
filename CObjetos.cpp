#include "CObjetos.h"

CObjetos::CObjetos() : m_Nombre{"Vacio"}, m_Caracter{0}, m_PosX{0}, m_PosY{0} {}
CObjetos::CObjetos(string pNombre,char pCaracter, int pPosX, int pPosY): m_Nombre{pNombre}, m_Caracter{pCaracter}, m_PosX{pPosX}, m_PosY{pPosY} {}
CObjetos::CObjetos(string pNombre,char pCaracter): m_Nombre{pNombre}, m_Caracter{pCaracter}, m_PosX{0}, m_PosY{0} {}
CObjetos::~CObjetos() {}

void CObjetos::setNombre(char pNombre) { this->m_Nombre = pNombre; }
string  CObjetos::getNombre() { return m_Nombre; }
char CObjetos::getCaracter()  { return m_Caracter; }
int   CObjetos::getPosX()   { return m_PosX; }
int   CObjetos::getPosY()   { return m_PosY; }
string CObjetos::getPosicion() { return "X = " + to_string(m_PosX) + " Y = " + to_string(m_PosY);}
