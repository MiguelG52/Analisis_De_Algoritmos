 /*INSTITUTO POLITÉCNICO NACIONAL
   ESCUELA SUPERIOR DE CÓMPUTO
   ALUMNOS: González Hipólito Miguel Angel, Lechuga Canales Héctor Jair
   GRUPO: 3CV11
   MATERIA: Análisis de algortmos
   PROFESOR: Benjamin Luna Benoso 
   FECHA: 25/10/2022
   PRÁCTICA 2: Complejidades temporales polinomiales y no polinomiales.*/
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int Fibonacci (int n);
int main() {
	int numero, i;
	printf("Dame el numero de elementos: ");
	scanf("%d", &numero);
	for(i=1; i<=numero; i++){
		printf("%d, ", Fibonacci(i));
	}
	
	return 0;
}
int Fibonacci (int n){
	if(n==0 || n==1)
	{
		return n;
	}
	else {
		return(Fibonacci(n-1) + Fibonacci(n-2));
	}
}
