//
// Created by tania on 27/10/2019.
//

#include "CObjetos.h"

const int ALTURA = 11;
const int ANCHO = 11;
const char INICIO ='X';
const char FINAL ='F';
const char OBSTACULO ='1';
const char LIBRE ='0';


class Mapa{
private:
    int m_Altura;
    int m_Ancho;
    char **m_Plano;
    int m_cantInicioFinal;
    CObjetos **m_InicioFinal =nullptr;
public:
    Mapa();
    Mapa(int pAltura, int pAncho);
    virtual ~Mapa();
    void adicionarInicioFin(CObjetos* pInicioFinal);
    //CRobot* removerRobot(TipoString pNombre);
    //CRobot* buscarRobot(TipoString pNombre);
    //void imprimirInicioFinal(ostream &os);
    int getAltura();
    int getAncho();
    int getCantidadObjectos();
    void dibujarMapa(ostream &os);
    void actualizarMapa();
};