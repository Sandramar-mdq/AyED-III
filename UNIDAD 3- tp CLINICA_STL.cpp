#include <iostream>
#include <list>

using namespace std;

class Paciente
{
private:
    string _dni;
    string _nombre;
    string _apellido;
    string _direccion;

public:
    Paciente();
    Paciente(string dni, string nombre, string apellido, string direccion);
    string getinfoPaciente();
};

Paciente::Paciente()
{
    this->_dni = "";
    this->_nombre = "";
    this-> _apellido = "";
    this->_direccion = "";
}
Paciente::Paciente(string dni, string nombre, string apellido, string direccion)
{
    this->_dni = "";
    this->_nombre = "";
    this-> _apellido = "";
    this->_direccion = "";
}
string Paciente::getinfoPaciente()
{
    string infoPaciente;
    infoPaciente = " DNI: " + this->_dni + " Nombre: " + this->_nombre + " Apellido: " + this->_apellido + " Direccion: " + this->_direccion;
    return infoPaciente;
}
void mostrar_pacientes(list<Paciente*> list)
{
   std::list<Paciente*>::iterator iterator;
    cout << "Listado de pacientes: " << endl;
    for (iterator = list.begin(); iterator != list.end(); ++iterator)
        std::cout << (*iterator)->getinfoPaciente() << std::endl;
}

void actualizar_paciente(list<Paciente*> *list, Paciente *anterior, Paciente *actual)
{
    std::list<Paciente *>::iterator iterator;
    for (iterator = list->begin(); iterator != list->end(); ++iterator)
    {
        if ((*iterator)->getinfoPaciente() == anterior->getinfoPaciente())
        {
            *iterator = actual;
            return;
        }
    }
    cout << "Paciente no encontrado." << endl;
}

int main()
{
    list<Paciente*> paciente_list;

    Paciente *paciente_1 = new Paciente("33111", "Juan", "Perez", "Salta 212");
    Paciente *paciente_2 = new Paciente("30222", "Ana", "Rios", "Luro 2311");
    Paciente *paciente_3 = new Paciente("21333", "Alicia", "Moreau", "Rivadavia 3231");
    Paciente *paciente_4 = new Paciente("14112", "Juan", "Justo", "Falucho 2342");
    Paciente *paciente_5 = new Paciente("12233", "Alfredo", "Palacios", "Bolivas 2113");


    cout << " Cargando pacientes " << endl;
    paciente_list.push_back(paciente_1);
    paciente_list.push_back(paciente_2);
    paciente_list.push_back(paciente_3);
    paciente_list.push_back(paciente_4);
    paciente_list.push_back(paciente_5);

    mostrar_pacientes(paciente_list);
    cout << " " << endl;

    cout << " Eliminando paciente " << endl;
    paciente_list.remove(paciente_1);

    mostrar_pacientes(paciente_list);
    std::cout << " " << std::endl;

    cout << " Actualizando paciente " << endl;
    actualizar_paciente(&paciente_list, paciente_3, paciente_5);

    mostrar_pacientes(paciente_list);

    return 0;
}
