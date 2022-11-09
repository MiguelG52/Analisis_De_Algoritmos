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

void fibonacci(int n, int *c){
	(*c)++;
	(*c)++;
	(*c)++;
	unsigned long long x = 1, y = 1, z = 0;
	(*c)++;
	if(n==1){
		(*c)++;	
		return;
	}
	(*c)++;
	(*c)++;
   	for (int i = 1; i <= n; i++) {
      (*c)++;
	  z = x + y;
	  (*c)++;	
      x = y;
      (*c)++;
      y = z;
   }
   (*c)++;
}
int generaAleatorio(){
	return 1+rand()%(1000-1);
};
void principal(){
	
	//creamos archivos csv con el nombre
	ofstream excel("fibonacci_iterativo.csv");
	
	int nCasos, n;
	srand(time(NULL));
	cin >> nCasos;
    for(int i = 1; i<nCasos; i++){
    	int contador = 0;
    	n = generaAleatorio();
    	fibonacci(n, &contador);
    	cout << "\n n:" << n << "\tpasos:" << contador;
    	excel << n << "," << contador<<"\n";
    }
    excel.close();
}

int main(){
	principal();
   	return 0;
}
