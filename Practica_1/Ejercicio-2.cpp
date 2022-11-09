#include<iostream>
#include <fstream>
#include<stdlib.h>
#include<time.h>
#define TAM 2

using namespace std;

//definimos funciones
void principal();
int euclides(int n, int m, int *ctr);
void generaAleatorios(int arreglo[], int limite, int n, int tipo);

//array constante con algunos numeros consecutivos de la serie
const int fibonacci[18] = {144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229};

int euclides(int m, int n, int *ctr){
	
	while(n != 0){
		(*ctr)++; //cada comparacion
		int r = m%n; (*ctr)++; //cada operacion de modulo
		m = n; (*ctr)++; //cada reasignacion
		n = r; (*ctr)++; //cada reasignacion
	}
	(*ctr)++; //ultima comparacion
	(*ctr)++; //dato retornado
	return m;
}
//Generamos numeros aleatorios
void generaAleatorios(int array[], int limite, int n, bool esFibonacci){
	
	if(esFibonacci){
		//generamos un numero aleatorio del arreglo de la sucesion
		int espacioDeArray = rand() % sizeof(limite);
		
		//En caso de que se genere el ultimo espacio restamos 1 para tomar los dos ultimos numeros
		if(espacioDeArray == limite-1) espacioDeArray--;
		
		//tomamos los 2 numeros consecutivos del arreglo de fibonacci y los asigamos al arreglo que llega por parametro
		array[0] = fibonacci[espacioDeArray];
		array[1] = fibonacci[espacioDeArray+1]; 
	}
	
	else{	
		for(int i=0; i<n; i++){
			array[i] = 1+rand()%limite;
		}
		
	}
}

//Generamos funcion principal
void principal(){
	
	//creamos archivos csv con el nombre excel
	ofstream excel("Euclides.csv");
	
	int n, m, mcd;
	int arreglo[TAM];
	srand(time(NULL));

	//Generamos numeros aleatorios para generar todo tipo de casos
	for(int i=1; i<=30; i++){
		
		int ctr = 0;
		
		bool esFibonacci = false;
		int limite = 100;
		
		//cada 3 numeros generamos un par de numeros consecutivos del arreglo con la sucesion de fibonacci
		if(i%3 == 0){
			esFibonacci = true;
			limite = 18;
		}
		
		generaAleatorios(arreglo, limite , 2, esFibonacci);
		int mcd = euclides(arreglo[0], arreglo[1], &ctr);
		cout << arreglo[0] <<"\t"<< arreglo[1] <<"\t" << mcd << "\t"<< ctr << "\n";
		excel <<  mcd << "," << ctr << "\n";
		
	}	
	excel.close();
}

main(){
	principal();
	return 0;
}

