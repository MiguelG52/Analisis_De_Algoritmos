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
// Serie de fibonacci: 1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597...
int main() {
	 int n, i, cont=0, x=0, y=1, z;
 
 printf("Digite el numero de elementos: ");
 scanf("%d", &n);
 for(i=1;i<=n;i++){
  z=x+y;
  y=x;
  x=z;
  cont ++;
  printf("%d, ",z);
  printf("%d \n",cont);
 }
	return 0;
}
