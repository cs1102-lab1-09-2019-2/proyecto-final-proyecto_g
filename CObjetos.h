#include "Tipos.h"
#include <string>
using namespace std;

class CObjetos{
private:
    string m_Nombre;
    char   m_Caracter;
    int    m_PosX;
    int    m_PosY;
public:
    CObjetos();
    CObjetos(string pNombre,char pCaracter,int pPosX, int pPosY);
    CObjetos(string pNombre, char pCaracter);
    string getNombre();
    int getPosX();
    void setNombre(char pNombre);
    int getPosY();
    string getPosicion();
    char getCaracter();
    ~CObjetos();
};
