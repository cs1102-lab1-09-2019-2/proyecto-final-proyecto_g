//
// Created by Tania on 27/10/2019.
//

#include "CObjetos.h"

const char INICIO ='X';
const char FINAL ='F';
const char OBSTACULO ='1';
const char LIBRE ='0';
static int ancho_x = 10; // es el ancho del mapa(x) Si se cambia, tambien el archivo mapa.map
static int largo_y = 10; // el largo de mapa(y)
static int tam_m=ancho_x*largo_y; // tamanio total del mapa

// al pasar sMapaLeido a matrix numerica vector[][]
// estos seran los equivalentes
//'T'=-2
//'F'=-3
//'X'=0
//'.'=-1

class Mapa{
private:
    int m_Altura;
    int m_Ancho;
    char **m_Plano;
    int m_cantInicioFinal;
    string sMapaLeido;
    CObjetos **m_InicioFinal =nullptr;
public:
    Mapa();
    Mapa(int pAltura, int pAncho);
    virtual ~Mapa();
    void adicionarInicioFin(CObjetos* pInicioFinal);
    int getAltura();
    int getAncho();
    int getCantidadObjectos();
    void LeerArchivo(string sArchivo);
    void cargarMapa();
    void hallarRuta();
    void dibujarMapa(ostream &os);
    void actualizarMapa();
};
