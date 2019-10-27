#include "Tipos.h"
class CObjetos{
private:
    string  m_Nombre;
    char m_Color;
    int    m_PosX;
    int    m_PosY;
public:
    string getNombre();
    int getPosX();
    CObjetos(string pNombre,char pColor,
             int pPosX, int pPosY);
    CObjetos(string pNombre, char pColor);
    CObjetos();
    ~CObjetos();
    void setNombre(char pNombre);
    void moverse(int pPosX, int pPosY);
    int getPosY();
    string getPosicion();
    char getColor();
};