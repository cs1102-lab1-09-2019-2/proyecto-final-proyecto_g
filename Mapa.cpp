#include "Mapa.h"

int minimo(int a,int b, int c, int d,int *p); //hallar el mínimo de 4 valores

Mapa::Mapa(): m_cantInicioFinal{0}, m_Altura{ancho_x}, m_Ancho{largo_y}  {
    m_Plano = new char*[m_Altura];
    for (int i = 0; i < m_Altura; ++i)
        m_Plano[i] = new char[m_Ancho];
}
Mapa::Mapa(int pAltura, int pAncho): m_Altura {pAltura}, m_Ancho {pAncho}, m_cantInicioFinal{1} {
    m_Plano = new char*[m_Altura];
    for (int i = 0; i < m_Altura; ++i)
        m_Plano[i] = new char [m_Ancho];
}
Mapa::~Mapa() {
    for (int i = 0; i < m_Altura; ++i) {
        delete[] m_Plano[i];
    }
    delete[] m_Plano;
    m_Plano = nullptr;
}
void Mapa::adicionarInicioFin(CObjetos* pInicioFinal) {
    CObjetos** temp = new CObjetos*[m_cantInicioFinal + 1];
    for (int i  = 0; i < m_cantInicioFinal; ++i)
        temp[i] = m_InicioFinal[i];
    temp[m_cantInicioFinal] = pInicioFinal;

    delete [] m_InicioFinal;
    m_InicioFinal = temp;
    m_cantInicioFinal++;
}
void Mapa::LeerArchivo(string sArchivo){
	//Leer Archivo con el mapa
	ifstream archivo;
	archivo.open(sArchivo,ios::in); //Abrimos el archivo en modo lectura
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	while(!archivo.eof()){ //mientras no sea final del archivo
		getline(archivo,sMapaLeido);
	}
	cout<<"Archivo:"<<sArchivo<<endl;
	archivo.close(); //Cerramos el archivo
}
void Mapa::cargarMapa(){
	// Pone set valores de sMapaLeido a pMapa
	int NumUbicaciones=100;
	int pPosX, pPosY;
	string pNombre;
	char pCaracter;
	for(int i=0; i<NumUbicaciones; i++){
		pNombre="MapSet";
	    pCaracter=sMapaLeido[i];
	    // Tralasdar fila-Columna de sMatrizMapa a fila-columna del pMapa
	    pPosX=i%10;  //elementos de columna
	    pPosY=i/10;  //elementos de fila
	    Mapa::adicionarInicioFin(new CObjetos(pNombre, pCaracter, pPosX, pPosY));
	    //Mapa::actualizarMapa();
	    for (int k = 0; k < m_cantInicioFinal; ++k) {
	        m_Plano[m_InicioFinal[k]->getPosY()][m_InicioFinal[k]->getPosX()]= m_InicioFinal[k]->getCaracter();
	    }
	}
}
void Mapa::hallarRuta(){
	int indice=0;
	int vector[ancho_x][largo_y];  //matriz temporal numerica para algoritmo
	int PosXx, PosXy;
	// buscar X(i,j)
	for (int j=0;j<largo_y;j++){
	  for (int i=0;i<ancho_x;i++){
	    if (sMapaLeido[indice] == 'X'){
	        // Posición encontrada
	        PosXx = i;
	        PosXy = j;
	        // TEST
	        cout<<"Cordenadas de X:("<<PosXx;
	        cout<<","<<PosXy<<")"<<endl;
	    }
	    indice++;
	  }
	}
	// Copiar cadena sMapaLeido a matriz nuemrica temporal vector
	indice=0;
	for (int j=0;j<largo_y;j++){
	    for (int i=0;i<ancho_x;i++){
	      if(sMapaLeido[indice]=='.'){
	        vector[i][j]=-1;
	      }
	      if(sMapaLeido[indice]=='T'){
	        vector[i][j]=-2;
	      }
	      if(sMapaLeido[indice]=='F'){
	        vector[i][j]=-3;
	      }
	      if(sMapaLeido[indice]=='X'){
	        vector[i][j]=0;
	      }
	      indice++;
	    }
	}
	for (indice=0;indice<tam_m;indice++){   //tam_m=tamanio del mapa
	    for (int j=0;j<largo_y;j++){
	      for (int i=0;i<ancho_x;i++){
	        if (vector[i][j] == indice){
	          //arriba
	          if (j-1 >-1 ){
	            //Escribir "indice+1" solo si la celda esta vacia
	            if (vector[i][j-1]==-1){
	              vector[i][j-1]=indice+1;
	            }
	          }
	          //abajo
	          if (j+1 < largo_y ){
	            if (vector[i][j+1]==-1){
	              vector[i][j+1]=indice+1;
	            }
	          }
	          //izquierda
	          if (i-1 >-1 ){
	            if (vector[i-1][j]==-1){
	              vector[i-1][j]=indice+1;
	            }
	          }
	          //derecha
	          if (i+1 < ancho_x ){
	            if (vector[i+1][j]==-1){
	              vector[i+1][j]=indice+1;
	            }
	          }
	        }
	      }
	    }
	}
	// TEST
	/*
	cout<<"\nMostrando matriz(sin ruta):\n\n";
	//se comprueba que encontro la ruta mas corta
	for(int j=0;j<largo_y;j++){
			for(int i=0;i<ancho_x;i++){
				cout<<setw(3)<<vector[i][j];
			}
			cout<<"\n";
	}
	*/
	//Hallar "F" = -3
	indice=0;
	int PosFx=0;
	int PosFy=0;
	for (int j=0;j<10;j++){
	    for (int i=0;i<10;i++){
	      if (vector[i][j] == -3){
	        // Posición encontrada
	        PosFx = i;
	        PosFy = j;
	        cout<<"Cordenadas de F:("<<PosFx;
	        cout<<","<<PosFy<<")"<<endl;
	      }
	      indice++;
	    }
	}
	//buscar el menor al rededor de F
	// arribar es
	int arriba;
	int abajo;
	int izquierda;
	int derecha;
	if ((PosFy-1) < 0 ){
	  arriba=100;
	}
	else {
	  arriba=vector[PosFx][PosFy-1];
	}
	if ((PosFy+1) > 9 ){
	  abajo=100;
	}
	else {
	  abajo=vector[PosFx][PosFy+1];
	}
	if ((PosFx-1) < 0 ){
	  izquierda=100;
	}
	else {
	  izquierda=vector[PosFx-1][PosFy];
	}
	if ((PosFx+1) > 9 ){
	  derecha=100;
	}
	else {
	  derecha=vector[PosFx+1][PosFy];
	}
	int pos;
	int temp=minimo(arriba,abajo,izquierda,derecha,&pos);
	//TEST
	/*
	cout<<"menor valor:"<<temp<<endl;
	cout<<"en la posicion:"<<pos<<endl;
	*/
	switch(pos){
	case 0:
		PosFy--;
		break;
	case 1:
		PosFy++;
		break;
	case 2:
		PosFx--;
		break;
	case 3:
		PosFx++;
		break;
	}
	//TEST
	/*
	cout<<"Nueva Pos:("<<PosFy<<","<<PosFx<<")"<<endl;
	cout<<"valor:"<<vector[PosFx][PosFy]<<endl;
	*/
	// Ya tenemos la posicion y valor del primero de la ruta
	for(int i=vector[PosFx][PosFy];i>0;i--){
		vector[PosFx][PosFy]=-5; //para indicar que es la ruta "*"
		sMapaLeido[PosFy*10+PosFx]='*'; //marcamos con asterisco la ruta
		//buscar a los lados el siguiente menor "i-1"
		bool encontrado=false;
		if (((PosFy-1) >=0 ) and (!encontrado)){
			//arriba
			if(vector[PosFx][PosFy-1]==(i-1)){
				PosFy--;
				encontrado=true;
			}
		}
		if (((PosFy+1) <=9 ) and (!encontrado)){
			//abajo
			if(vector[PosFx][PosFy+1]==(i-1)){
				PosFy++;
				encontrado=true;
			}
		}
		if (((PosFx-1) >=0 ) and (!encontrado)){
			//izquierda
			if(vector[PosFx-1][PosFy]==(i-1)){
				PosFx--;
				encontrado=true;
			}
		}
		if (((PosFx+1) <= 9 ) and (!encontrado)){
			//derecha
			if(vector[PosFx+1][PosFy]==(i-1)){
				PosFx++;
				encontrado=true;
			}
		}
	}
	//TEST
	/*
	cout<<"\nMostrando matriz con ruta\n\n";
	//se comprueba que encontro la ruta mas corta
	for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				cout<<setw(3)<<vector[i][j];
			}
			cout<<"\n";
	}
	*/
}
void Mapa::actualizarMapa() {
    for (int k = 0; k < m_cantInicioFinal; ++k) {
        m_Plano[m_InicioFinal[k]->getPosY()][m_InicioFinal[k]->getPosX()]= m_InicioFinal[k]->getCaracter();
    }
}
void Mapa::dibujarMapa(ostream &os) {
    os << '\n';
    os << setw(3) << ' ';
    for (int j = 0; j < m_Ancho; ++j)
        os << setw(3) << j;
    os << '\n';
    for (int i = 0; i < m_Altura ; ++i) {
        os << setw(3) << i;
        for (int j = 0; j < m_Ancho; ++j) {
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
int minimo(int a,int b, int c, int d,int *p){
  int min=100;
  if (a>0){
  if (a<min){
    min=a;
    *p=0;
  }
  }
  if (b>0){
  if (b<min){
    min=b;
    *p=1;
  }
  }
  if(c>0){
  if (c<min){
    min=c;
    *p=2;
  }
  }
  if (d>0){
  if (d<min){
    min=d;
    *p=3;
  }
  }
  return min;
}
