 /*INSTITUTO POLITÉCNICO NACIONAL
   ESCUELA SUPERIOR DE CÓMPUTO
   ALUMNOS: González Hipólito Miguel Angel, Lechuga Canales Héctor Jair
   GRUPO: 3CV11
   MATERIA: Análisis de algortmos
   PROFESOR: Benjamin Luna Benoso 
   FECHA: 1/11/2022
   PRÁCTICA 3: Funciones Iterativas vs recursivas*/
#include<bits/stdc++.h>
using namespace std;

pair <int, int> aleatorios();

int division1(int n, int div, int *c){
	(*c)++;
	int q = 0;
	
	while(n>=div){ (*c)++;
		(*c)++;
		n = n-div;
		(*c)++;
		q++;
	}
	(*c)++;
	return q;
}

int division2(int n, int div, int *c){
	
	(*c)++;(*c)++;(*c)++;
	int dd= div;
	int q = 0;
	int r = n;
	
	
	while(dd <= n){ (*c)++;
		(*c)++;
		dd = 2*dd;
	}
	
	while(dd > div){ (*c)++;
		(*c)++;
		dd = dd/2;
		(*c)++;
		q = 2*q;
		(*c)++;
		if(dd <= r){ 
			(*c)++;
			r = r-dd;
			(*c)++;
			q = q+1;
		}
	}
	(*c)++;
	(*c)++;
	return q;
}

int division3(int n, int div, int *c){
	
	int **temp = &c;

	(*c)++;
	if(div>n){
		(*c)++;
		return 0;
	}
	else{
		(*c)++;(*c)++;
		return 1 + division3(n-div, div, *temp);
	};
}


//Funcion que genera numeros aleatorios
pair<int, int> generaAleatorios(){
	int a = 1+rand()%(1000-1);
	int b = 1+rand()%(1000-1);
	while(b>a) b = 1+rand()%(600-1);
	
	return make_pair(a,b);
};
//funcion principal
void principal(){
	int t;
	//crear archivo de excel para el programa division 1
	ofstream excel("division3.csv");
	//lee el numero de casos
	cin >> t;
	srand(time(NULL));
	
	for(int i=0; i<t; i++){
		int contador = 0;
		
		pair<int, int> aleatorios = generaAleatorios();
		division3(aleatorios.first, aleatorios.second, &contador);
		
		cout <<"n:"<< aleatorios.first << "\tdiv:" << aleatorios.second <<"\tpasos:"<<contador<<"\n";
		excel << aleatorios.first<<","<<aleatorios.second<<","<<contador<<"\n";
	}
	excel.close();
}
int main(){
	principal();
	return 0;
}
