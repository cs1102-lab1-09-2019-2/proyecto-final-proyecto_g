#include "Mapa.h"

// de X a F solo puede se puede llegar 
// por los espacios vacíos "."
// y en direcciones arriba, abajo, izquierda, derecha
// "X" punto de inicio
// "F" punto final
// "." espacio vacío
// "*" ruta resuelta

int main() {
  // crea el objeto mapa
  Mapa* pMapa = new Mapa();   		
  cout<<"Mapa cargado del ";
  // lee el archivo .map y lo guarda en sMapaLeido
  pMapa->LeerArchivo("mapa5.map");	
  pMapa->cargarMapa();
  pMapa->dibujarMapa(cout);
  // Busqueda ruta de X a F
  pMapa->hallarRuta();
  // pasa cadena sMapaLeido como Cobjetos al pMapa			
  pMapa->cargarMapa();				
  cout<<endl<<"Mapa resuelto con la ruta más corta:"<<endl;
  //imprimir en consola mapa resuelto
  pMapa->dibujarMapa(cout); 
  delete pMapa;		
  // pausa para que no cierre la consola
  //system("pause");					  
return 0;
}
