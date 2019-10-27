#include "Mapa.h"

int main() {
    srand(time(NULL));
    int NumRobots, pPosX, pPosY;
    string nombre;
    char pColor;
    Mapa* pMapa = new Mapa();
     NumRobots=2;
    for(size_t i=0; i<NumRobots; i++){
      if(i==0){
        nombre='I';
        pColor='X';
      }
      if (i==1){
        nombre='F';
        pColor='F';
      }

      pPosX=rand()%11;
      pPosY=rand()%11;
        pMapa->adicionarInicioFin(new CObjetos(nombre, pColor, pPosX, pPosY));
        pMapa->actualizarMapa();
    }
    pMapa->dibujarMapa(cout);
    //pMapa->imprimirInicioFinal(cout);
}