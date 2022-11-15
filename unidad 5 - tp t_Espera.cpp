#include <iostream>
#include <queue>

using namespace std;


class Cliente
{
    private:
    string name;
    string surname;
    int tiempoDeEspera;

    public:
    Cliente(string name, string surname)
    {
        this->name = name;
        this->surname = surname;
        this->tiempoDeEspera = 0;
    }

    void setClienteName(string name)
    {
        this->name = name;
    }

    string getClienteName()
    {
        return this->name;
    }

    void setClienteSurname(string surname)
    {
        this->surname = surname;
    }

    string getClienteSurname()
    {
        return this->surname;
    }

    void setTiempoDeEspera(int tiempoDeEspera)
    {
        this->tiempoDeEspera = tiempoDeEspera;
    }

    int getTiempoDeEspera()
    {
        return this->tiempoDeEspera;
    }

};

class RecursiveFunction
{

    public:
       RecursiveFunction()
        {

        }

    void showRecursiveClientList(queue<Cliente> cQueue)
    {
        if (cQueue.empty())
        return;
        else{
          cout <<  cQueue.front().getClienteName() << " " <<
          cQueue.front().getClienteSurname() << " " <<
          cQueue.front().getTiempoDeEspera() << endl;
          cQueue.pop();
          showRecursiveClientList(cQueue);
    }

}

};
class BoxDeAtencion
{
    private:
    queue<Cliente> clienteQueue;
    RecursiveFunction recursiveFunction;

    int lastNumeroLlamada = 1;
    int currentTiempoDeEspera = 0;

    public:
    BoxDeAtencion()
    {
        
    }   

    void addCliente(Cliente& cliente)
    {
        currentTiempoDeEspera = currentTiempoDeEspera + 10;
        cliente.setTiempoDeEspera(currentTiempoDeEspera);
        lastNumeroLlamada++;
        clienteQueue.push(cliente);

    }

    void showClienteList()
    {
        queue<Cliente> clientQueueCopy;
        clientQueueCopy = clienteQueue;
        
        while(!clientQueueCopy.empty())
        {
            cout << clientQueueCopy.front().getClienteName() << " " <<
                         clientQueueCopy.front().getClienteSurname() << " " <<
                         clientQueueCopy.front().getTiempoDeEspera() << endl;
            clientQueueCopy.pop();
        }


    }

    void showRecList()
    {
        recursiveFunction.showRecursiveClientList(clienteQueue);
    }

    void nextCliente()
    {
        queue<Cliente> clientQueueCopy;
        clientQueueCopy = clienteQueue;

         cout << "Atendiendo a: " << 
         clientQueueCopy.front().getClienteName() << " " <<
         clientQueueCopy.front().getClienteSurname() << endl;

        clientQueueCopy.pop();

        cout << "Proximo Cliente en la cola: " <<
         clientQueueCopy.front().getClienteName() << " " <<
         clientQueueCopy.front().getClienteSurname() << endl;
    }

    void atenderCliente()
    {
        clienteQueue.pop();
        currentTiempoDeEspera = currentTiempoDeEspera - 10;
        int frontTiempoDeEspera = 10;

            if(currentTiempoDeEspera > 0)
            {
                clienteQueue.back().setTiempoDeEspera(currentTiempoDeEspera);
                clienteQueue.front().setTiempoDeEspera(frontTiempoDeEspera);
            }
    }

};


int main()
{
    BoxDeAtencion boxAtencion;
    

    Cliente cliente1("Carlos", "Ramos");
    Cliente cliente2("Jazmin", "Aitana");
    Cliente cliente3("Felipe", "Rey");
    Cliente cliente4("Maria", "Marta");
    Cliente cliente5("Roberto","Carlos");
    Cliente cliente6("Lucas", "Ponce");

    boxAtencion.addCliente(cliente1);
    boxAtencion.addCliente(cliente2);
    boxAtencion.addCliente(cliente3);
    boxAtencion.addCliente(cliente4);
    boxAtencion.addCliente(cliente5);
    boxAtencion.addCliente(cliente6);
    boxAtencion.showRecList();

    

}