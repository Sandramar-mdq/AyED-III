#include <iostream>

using namespace std;

class Cliente {
private:
    class Turno {
    public:
        int info;
        Turno *sig;
    };

    Turno *frente;
    Turno *fondo;
public:
    Cliente();
    ~Cliente();
    void insertar(int x);
    void listar();
    bool vacia();
};


Cliente::Cliente()
{
    frente = NULL;
    fondo = NULL;
}

Cliente::~Cliente()
{
    Turno *reco = frente;
    Turno *bor;
    while (reco != NULL)
    {
        bor = reco;
        reco = reco->sig;
        delete bor;
    }
}

void Cliente::insertar(int x)
{
    Turno *nuevo;
    nuevo = new Turno();
    nuevo->info = x;
    nuevo->sig = NULL;
    if (vacia())
    {
        frente = nuevo;
        fondo = nuevo;
    }
    else {
        fondo->sig = nuevo;
        fondo = nuevo;
    }
}

void Cliente::listar()
{
    Turno *reco = frente;
    cout << "\n  TURNOS (por orden de llegada): \n\n";
    while (reco != NULL)
    {
        cout<< "     Proximo Cliente: " << reco->info << "  Box activo. \n";
        reco = reco->sig;
    }
    cout << "\n";
}

bool Cliente::vacia()
{
    if (frente == NULL)
        return true;
    else
        return false;
}

int main()
{
    Cliente *cola1 = new Cliente();
    cola1->insertar(1);
    cola1->insertar(2);
    cola1->insertar(3);
    cola1->listar();

    return 0;
}
