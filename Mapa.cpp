#include "Mapa.h"
Mapa::Mapa(): m_cantInicioFinal{0},
                          m_Altura{ALTURA}, m_Ancho{ANCHO}  {
    m_Plano = new char*[m_Altura];
    for (size_t i = 0; i < m_Altura; ++i)
        m_Plano[i] = new char[m_Ancho];
}

Mapa::Mapa(int pAltura, int pAncho): m_Altura {pAltura}, m_Ancho {pAncho}, m_cantInicioFinal{1} {
    m_Plano = new char*[m_Altura];
    for (size_t i = 0; i < m_Altura; ++i)
        m_Plano[i] = new char [m_Ancho];
}

Mapa::~Mapa() {
    for (size_t i = 0; i < m_Altura; ++i) {
        delete[] m_Plano[i];
    }
    delete[] m_Plano;
    m_Plano = nullptr;
}
void Mapa::adicionarInicioFin(CObjetos* pInicioFinal) {
    CObjetos** temp = new CObjetos*[m_cantInicioFinal + 1];
    for (size_t i  = 0; i < m_cantInicioFinal; ++i)
        temp[i] = m_InicioFinal[i];
    temp[m_cantInicioFinal] = pInicioFinal;

    delete [] m_InicioFinal;
    m_InicioFinal = temp;
    m_cantInicioFinal++;
}
/*CRobot* CBattleBox::removerRobot(TipoString nombre) {
    // Buscando objeto
    auto robot = buscarRobot(nombre);
    if (robot == nullptr) return nullptr;
    // Eliminando objeto
    CRobot** temp = new CRobot*[m_CantRobots - 1];
    int j = 0;
    for (size_t i  = 0; i < m_CantRobots; ++i)
        if (m_Robots[i] != robot) {
            temp[j] = m_Robots[i];
            j++;
        }
    m_Robots = temp;
    m_CantRobots--;
    return robot;
}
CRobot* CBattleBox::buscarRobot(TipoString pNombre) {
    for (size_t i  = 0; i < m_CantRobots; ++i) {
        if (pNombre == m_Robots[i]->getNombre()) {
            return m_Robots[i];
        }
    }
    return nullptr;
}
void CBattleBox::imprimirInicioFinal(ostream &os) {
    for (size_t i = 0; i < m_CantRobots; ++i) {
        os << "* * * * * * [" << i << "] ";
        os << " Nombre = " << m_Robots[i]->getNombre() << " "
           << m_Robots[i]->getPosicion()
           << " Color = " << m_Robots[i]->getColor() << '\n';
    }
}*/
void Mapa::actualizarMapa() {

    for (size_t i = 0; i < m_Altura ; ++i) {
        for (size_t j = 0; j < m_Ancho; ++j) {
            m_Plano[i][j] = rand()%2;;
        }
    }
    for (size_t k = 0; k < m_cantInicioFinal; ++k) {
        m_Plano[m_InicioFinal[k]->getPosY()][m_InicioFinal[k]->getPosX()]= m_InicioFinal[k]->getColor();
    }
}
void Mapa::dibujarMapa(ostream &os) {
    os << '\n';
    os << setw(3) << ' ';
    for (size_t j = 0; j < m_Ancho; ++j)
        os << setw(3) << j;
    os << '\n';
    for (size_t i = 0; i < m_Altura ; ++i) {
        os << setw(3) << i;
        for (size_t j = 0; j < m_Ancho; ++j) {
            os << setw(3) << m_Plano[i][j];
        }
        os << '\n';
    }
}

int Mapa::getAltura() {
    return m_Altura;
}

int Mapa::getAncho(){
    return m_Ancho;
}