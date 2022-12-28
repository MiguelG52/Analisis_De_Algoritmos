 /*INSTITUTO POLITÉCNICO NACIONAL
   ESCUELA SUPERIOR DE CÓMPUTO
   ALUMNOS: González Hipólito Miguel Angel, Lechuga Canales Héctor Jair
   GRUPO: 3CV11
   MATERIA: Análisis de algortmos
   PROFESOR: Benjamin Luna Benoso 
   FECHA: 21/12/2022
   PRÁCTICA 4:Algoritmos greedy*/

#include<bits/stdc++.h>
using namespace std;


int generaAletorio(int limite){
    int a = (rand()%(limite))+1;
}

void solve(vector<int> c,int r, int *contador){
	int len = c.size();
	(*contador)++;

	(*contador)++;
	if(len == 1){
		(*contador)++;
		return;
	}
	(*contador)++;
	int f = r + c[0];
	(*contador)++;
	vector<int> s;
	
	(*contador)++;
	for(int i=1; i<len; i++){
		(*contador)++;
		if(i == 1) {
			(*contador)++;
			s.push_back(c[0]);
		}
		(*contador)++;
		if(i>1){
			//cout << c[i]<<":"<<f<<"\t";
			(*contador)++;
			if(c[i] > f){
				(*contador)++;(*contador)++;
				s.push_back(c[i-1]);
				f = r + c[i-1];
			}
		} 
		(*contador)++;
	}
	(*contador)++;
	s.push_back(c[len-1]);
	(*contador)++;
	for(int i=0; i<s.size(); i++) cout << s[i]<<"\t";
}

void greedy(){
    int t;
    ofstream excel("greedy.csv");
    cin >> t;
	srand(time(NULL));
    for(int i=0; i<t; i++){
		int contador = 0;
        int tamano = generaAletorio(500);
        int r = generaAletorio(150);
        vector<int> c;
        
        for(int j=0; j<tamano;j++){
        int n = generaAletorio(1000);
        	c.push_back(n);
    	}
    	sort(c.begin(), c.end());
    	cout<<"r:"<<r<<"\n\n";
    	solve(c, r, &contador);
    	
    	cout << tamano<<"\t"<<contador<<"\n";
    	excel <<tamano<<","<<contador<<"\n";
    }
    excel.close();
}

int main(void){
    greedy();
    return 0;
}
