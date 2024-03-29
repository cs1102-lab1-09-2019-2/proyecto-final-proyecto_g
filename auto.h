//
// Created by jessica on 27/10/19.
//

#ifndef PROYECTO_AUTO_H
#define PROYECTO_AUTO_H


//EMPIEZA LA CLASE AUTO
//Se declara la clase para hacer el objeto
const int VIDAS=5;

class AUTO{
private:
    int x;
    int y;
    int salud;//cuando salud es cero las vidas disminuyen
    int num_vidas;//cuando la vida llega a cero  se muere o termina
public:
    AUTO(int x, int y, int salud, int num_vidas);
    int X(){return x;}
    int Y(){return y;}
    void redu_salud(){salud--;}
    void pintar();
    void borrar();
    void mover(int x, int y);
    void salud_();
    void muerte();
    void cursor();
};

#endif //PROYECTO_AUTO_H
