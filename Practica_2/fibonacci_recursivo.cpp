 /*INSTITUTO POLITÉCNICO NACIONAL
   ESCUELA SUPERIOR DE CÓMPUTO
   ALUMNOS: González Hipólito Miguel Angel, Lechuga Canales Héctor Jair
   GRUPO: 3CV11
   MATERIA: Análisis de algortmos
   PROFESOR: Benjamin Luna Benoso 
   FECHA: 25/10/2022
   PRÁCTICA 2: Complejidades temporales polinomiales y no polinomiales.*/
#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n, int *c){
	
	(*c++);
	if(n == 0){
		(*c++);
		return 1;
	}
	else{
		(*c++);
		(*c++);
		return fibonacci(n-1, c) + fibonacci(n-2, c);
	}
}
int generaAleatorio(){
	return 1+rand()%(10-1);
};
void principal(){
	
	//creamos archivos csv con el nombre
	ofstream excel("fibonacci_iterativo.csv");
	
	int nCasos, n;
	srand(time(NULL));
	cin >> nCasos;
	int nFibonacci;
    for(int i = 1; i<nCasos; i++){
    	int contador = 0;
    	n = generaAleatorio();
    	nFibonacci = fibonacci(n, &contador);
    	cout << "\n n:" << n << "\tpasos:" << contador;
    	excel << n << "," << contador<<"\n";
    }
    excel.close();
}

int main(){
	principal();
   	return 0;
}
