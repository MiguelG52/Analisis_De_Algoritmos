 /*INSTITUTO POLIT�CNICO NACIONAL
   ESCUELA SUPERIOR DE C�MPUTO
   ALUMNOS: Gonz�lez Hip�lito Miguel Angel, Lechuga Canales H�ctor Jair
   GRUPO: 3CV11
   MATERIA: An�lisis de algortmos
   PROFESOR: Benjamin Luna Benoso 
   FECHA: 25/10/2022
   PR�CTICA 2: Complejidades temporales polinomiales y no polinomiales.*/
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
