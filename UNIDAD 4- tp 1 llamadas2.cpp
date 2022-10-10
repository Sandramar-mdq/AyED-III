#include <iostream>

using namespace std;

class Llamada
{
private:
    int llamadas[50];
    int Max;
    int nroReciente; //TOP

 public:
    Llamada()
    {
        Max = 50;
        nroReciente = -1;
    }
    int getnroReciente();
    int pop();
    void Agregar(int Element);
    int Vacia();
    int CantLlamadas();
    int Llena();

};

int Llamada ::getnroReciente()
{
    if (!Vacia())
         return (llamadas[nroReciente]);
}

int Llamada ::pop()
{
     if (!Vacia())
         return (llamadas[nroReciente--]);
}

int Llamada ::Vacia()
{
     if (nroReciente == -1)
         return 1;
     else
         return 0;
}

int Llamada ::Llena()
{
     if (nroReciente == Max - 1)
         return 1;
     else
         return 0;
}

int Llamada ::CantLlamadas()
{
     return (nroReciente + 1);
}

void Llamada ::Agregar(int Element)
{
     if (!Llena())
         llamadas[++nroReciente] = Element;
}


int main()
{
     Llamada L;
    // L.pop();
     L.Agregar(42222);
     L.Agregar(33333);
     L.Agregar(44444);

    cout << "\t\n HISTORIAL DE LLAMADOS \n";
    cout << "\t" << L.pop() << endl;
    cout << "\t" << L.pop() << endl;
    cout << "\t" << L.pop() << endl;
    cout << "\n---------\n";


     return 0;
}

