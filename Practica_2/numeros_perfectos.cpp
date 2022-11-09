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

bool perfecto(int n, int *c2){
    (*c2)++;
	if(n <= 1){
		(*c2)++;
    	return false;
	}
	(*c2)++; 
    int contador= 1;
    
    (*c2)++;
    (*c2)++;
    for(int i=2; i*i<=n; i++){
        (*c2)++;
        (*c2)++;
		if(n%i == 0){
            (*c2)++;
			contador += (i + (n/i));
        }
	(*c2)++;	 
    }
    (*c2)++;
    if(n == contador){
    	(*c2)++;
		return true;
	}
	(*c2)++;
    return false;
}

void MostrarPerfectos(int n, int *c, int *c2){
	
	
	int nPerfectos = 0, i=1;
	(*c)++;
	(*c)++;
	while(nPerfectos != n){
		(*c)++;
		(*c)++;
		if(perfecto(i, c2)){
			(*c)++;
			cout<<i<<"\t";
			(*c)++;
			nPerfectos++;
		}
		(*c)++;
		if(nPerfectos == n){
			(*c)++;
			break;
		}
		(*c)++;
		i++;
	}
	(*c)++;
}

int generaAleatorio(){
	return 1+rand()%(5-1);
};

void principal(){
	
	//creamos archivos csv con el nombre
	ofstream excel("funcion_muestra_perfecto.csv");
	
	int nCasos, n;
	srand(time(NULL));
	
	//leemos el umero de casos de prueba
    cin >> nCasos;
    for(int i = 1; i<nCasos; i++){
    	//asignamos el contador a 0
    	int contador = 0, c2 = 0;
    	//generamos un numero aleatorio entre 1 y 4 dado que es el rango donde no se desborda la memoria
    	int n = generaAleatorio();
		//Mostramos los n primeros numeros perfectos
    	MostrarPerfectos(n, &contador, &c2);
    	//imprimimos los primeros n numeros perfectos
    	cout <<"n:"<<n<<"\t"<<"pasos:"<< c2*contador <<"\n\n";
    	excel <<n<<","<<contador*c2<<"\n";
	}
	excel.close();
    
}

int main()
{
    principal();
    return 0;
}
