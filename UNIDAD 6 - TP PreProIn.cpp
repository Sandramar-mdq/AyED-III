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
		int comparacion = strcmp(&vRaiz, n);
		if (comparacion == 0)
		{
			insertar(arbol->izq, n);
		}
		else if (comparacion < 0)
		{
			insertar(arbol->der, n);
		}
		else if (comparacion > 0)
		{
			insertar(arbol->izq, n);
		}
	}
}

void preOrden(Nodo *arbol)
{
	if (arbol == NULL)
	{
		return;
	}
	else
	{
		cout << arbol->letra << " - ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

void inOrden(Nodo *arbol)
{
	if (arbol == NULL)
	{
		return;
	}
	else
	{
		inOrden(arbol->izq);
		cout << arbol->letra << " - ";
		inOrden(arbol->der);
	}
}

void postOrden(Nodo *arbol)
{
	if (arbol == NULL)
	{
		return;
	}
	else
	{
		inOrden(arbol->izq);
		inOrden(arbol->der);
		cout << arbol->letra << " - ";
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
	int contador = 0;

	char letraes[] = {'G', 'B', 'Q', 'A', 'C', 'K', 'F', 'P', 'D', 'E', 'R', 'H'};

	for (int i = 0; i < sizeof(letraes); i++)
	{
		char *letra = &letraes[i];
		insertar(arbol, letra);
	}

	cout << "Mostrar arbol" << endl
		 << endl;
	mostrarArbol(arbol, contador);
	cout << "\n\nPreOrden: ";
	preOrden(arbol);
	cout << endl
		 << endl;

	cout << "InOrden: ";
	inOrden(arbol);
	cout << endl
		 << endl;

	cout << "PostOrden: ";
	postOrden(arbol);
	cout << endl
		 << endl;

	system("pause");
	return 0;
}
