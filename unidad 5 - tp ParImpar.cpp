/*Escribir dos funciones mutualmente recursivas par(n) e impar(n) que determinen la paridad del numero
natural dado, conociendo solo que:
a. 1 es impar.
b. Si un número es impar, su antecesor es par; y viceversa.*/


#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void impar(int num, int n);
void par(int num, int n);

void impar(int num, int n){
	if(n == num){
		cout << "\n\nEl numero " << num << " es impar." << endl ;
	}else{
		cout << "Numero "<< num  << endl;
		par(num, n + 1);
	}
}

void par(int num, int n){
	if(n == num){
		cout << "\n\nEl numero " << num << " es par." << endl << endl;
	}else{
		cout << "Numero "<< num << endl; 
		impar(num, n + 1);
	}
}


int main(){
	
	int numero = 0;
	
	while(numero == 0){
		
		try{
			cout << "Digite un numero:  ";
			cin >> numero;
		}catch(int n){
			
		}
	}
	
	impar(numero, 1);
	
	system("pause");
	
	return 0;
}