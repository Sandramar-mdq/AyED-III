#include <iostream>
#include <string.h>
using namespace std;

struct Nodo
{
	char letra;
	Nodo *izq;
	Nodo *der;
};

Nodo *crearNodo(char *n)
{
	Nodo *nuevo_nodo = new Nodo();

	nuevo_nodo->letra = *n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;

	return nuevo_nodo;
}

void insertar(Nodo *&arbol, char *n)
{
	if (arbol == NULL)
	{
		Nodo *nuevo_nodo = crearNodo(n);
		arbol = nuevo_nodo;
	}
	else
	{
		char vRaiz = arbol->letra;
		int compcadena = strcmp(&vRaiz, n);
		if (compcadena == 0)
		{
			insertar(arbol->izq, n);
		}
		else if (compcadena < 0)
		{
			insertar(arbol->der, n);
		}
		else if (compcadena > 0)
		{
			insertar(arbol->izq, n);
		}
	}
}

void mostrarArbol(Nodo *arbol, int cont)
{
	if (arbol == NULL)
	{
		return;
	}
	else
	{
		mostrarArbol(arbol->der, cont + 1);
		for (int i = 0; i < cont; i++)
		{
			cout << "	";
		}
		cout << arbol->letra << endl;
		mostrarArbol(arbol->izq, cont + 1);
	}
}

int main()
{
	Nodo *arbol = NULL;
	int contar = 0;

	char caracteres[] = {'G', 'B', 'Q', 'A', 'C', 'K', 'F', 'P', 'D', 'E', 'R', 'H'};

	for (int i = 0; i < sizeof(caracteres); i++)
	{
		char *letra = &caracteres[i];
		insertar(arbol, letra);
	}

	mostrarArbol(arbol, contar);

	system("pause");
	return 0;
}