 /*INSTITUTO POLIT�CNICO NACIONAL
   ESCUELA SUPERIOR DE C�MPUTO
   ALUMNOS: Gonz�lez Hip�lito Miguel Angel, Lechuga Canales H�ctor Jair
   GRUPO: 3CV11
   MATERIA: An�lisis de algortmos
   PROFESOR: Benjamin Luna Benoso 
   FECHA: 1/11/2022
   PR�CTICA 3: Funciones Iterativas vs recursivas*/
#include<bits/stdc++.h>
using namespace std;

//Genera un limite aleatorio multiplo de 3
int generaAleatorio(){
	int ale = 3+rand()%(900-3);
	while(ale%3 != 0 ) ale = 3+rand()%(900-3);
	return ale;
};

//Realiza busqueda secuencial
int busquedaEnBloqueIterativo(int n, vector<int>numbers, int *ctr){
	(*ctr)++;
	int size = numbers.size()/3;
	//crea sub arreglos
	(*ctr)++;
	vector<int> b, b2,b3;
	//inicializa punteros al final de los bloques
	(*ctr)++;(*ctr)++;
	int pb = size-1, pb2 = size-1;
	
	//inicializa punteros al inicio,  1/3 y 2/3 del arreglo para copiar elementos siguientes
	(*ctr)++;(*ctr)++;(*ctr)++;
	int i = 0, j = (numbers.size()/3), k = 2 * (numbers.size()/3);
	//LLena subarreglos
	while(i<size){(*ctr)++;
	
		b.push_back(i);(*ctr)++;
		b2.push_back(j);(*ctr)++;
		b3.push_back(k);(*ctr)++;
		i++;j++;k++;(*ctr)++;(*ctr)++;(*ctr)++;	
	}
	(*ctr)++;
	(*ctr)++;
	if(n == b[pb] || n == b2[pb2]){(*ctr)++;
		return pb;
	}
	else{
		//evalua si n es mayor o igual al primer elemento y menor o igual al ultimo elemento de cada blqoue
		(*ctr)++;
		if(n >= b[0] && n <= b[size-1]){
			(*ctr)++;
			for(int c = 0; c<b.size(); c++){
				(*ctr)++;(*ctr)++;(*ctr)++;
				if(b[c] == n){
					(*ctr)++;
					return c;
				}
			}
		}
		(*ctr)++;
		if(n >= b2[0] && n <= b2[size-1]){
			(*ctr)++;
			for(int c = 0; c<b2.size(); c++){
				(*ctr)++;(*ctr)++;(*ctr)++;
				if(b2[c] == n){
					 (*ctr)++;
					 return c;
				}
			}
		}
		(*ctr)++;
		if(n >= b3[0] && n <= b3[size-1]){
			(*ctr)++;
			for(int c = 0; c<b3.size(); c++){
				(*ctr)++;(*ctr)++;(*ctr)++;
				if(b3[c] == n){
					(*ctr)++;
					return c;
				}
			}
		}
	}
	(*ctr)++;
	return -1;
}

//Main
void principal(){
	int t;
	//crear archivo de excel para el programa division 1
	ofstream excel("busquedaIterativa.csv");
	//lee el numero de casos
	cin >> t;
	srand(time(NULL));
	
	for(int i=0; i<t;i++){
		int c = 0;
		vector<int> numeros;
		//obtiene limite de vector a llenar;
		int limite = generaAleatorio();
		//genera numero a buscar
		int n = 1+rand()%(2*limite-1);
		//llena vector
		for(int i=0;i<limite;i++) numeros.push_back(i+1);
		//Busca elemento n en vector numeros
		int indice = busquedaEnBloqueIterativo(n,numeros, &c);
		cout << "limite:"<<limite<<"\tn:"<<n<<"\tindice:"<<indice<<"\n";
		excel << limite <<","<<n<<","<<c<<"\n";
	}
	excel.close();
}
int main(){
	principal();
	return 0;
}
