#include <iostream>
//#include <locale.h>

using namespace std;

// Abstract Target
class Motor {
	public:
	// pure virtual function providing interface framework.
		virtual void encender() = 0;
		virtual void acelerar() = 0;
		virtual void apagar() = 0;
};

// Concrete Target
class MotorComun : public Motor{
	public:
		MotorComun(){};
		void encender(){
			 cout <<" Motor Comun Encendido.\n";
		}
		void acelerar(){
			cout <<" Motor Comun Acelerado.\n";
		}
		void apagar(){
			cout <<" Motor Comun Apagado.\n"<<endl;
		}
};

// Concrete Target
class MotorEconomico : public Motor{
	public:
		MotorEconomico(){};
		void encender(){
			cout<<"Motor economico Encendido.\n";
		}
		void acelerar(){
			cout<<"Motor economico acelerado.\n";
		}
		void apagar(){
			cout<<"Motor economico apagado.\n"<<endl;
		}
};
// Abstract Adaptee
class MotorElectrico{
	public:
		MotorElectricoAdapter(){};
		void conectar(){
			cout<<"Motor electrico conectado.\n";
		}
		void cargar(){
			cout<<"Motor electrico cargando.\n";
		}
		void desconectar(){
			cout<<"Motor electrico desconectado.\n";
		}
		void arrancar (){
			cout<<"Motor electrico Encendido.\n";
		}
		void apresurar(){
			cout<<"Motor electrico acelerado.\n";
		}
		void frenar(){
			cout<<"Motor electrico detenido.\n";
		}
		void controlar(){
			cout<<"Motor electrico controlando estado baterias.\n";
		}
};

// class Adapter
class AdapterMotorElectrico : public Motor{
	private:
		MotorElectrico motorElectrico;
	public:
		AdapterMotorElectrico(){};
		void encender(){
			this->motorElectrico.conectar();
			this->motorElectrico.cargar();
			this->motorElectrico.desconectar();
			this->motorElectrico. arrancar ();

		}
		void acelerar(){
			this->motorElectrico.apresurar();
		}
		void apagar(){
			this->motorElectrico.frenar();
			this->motorElectrico.controlar();
		}
};
// Client code
int main(){
   // setlocale(LC_CTYPE, "Spanish"); NO LOGRÉ USAR ACENTOS!

	cout << " \n   UNIDAD NRO.1\n   TRABAJO PRACTICO NRO.2 \n   PATRONES ESTRUCTURALES: ADAPTER\n\n";

	Motor* motor = new MotorComun();
	cout<<"  Motor Comun:\n";
	motor ->encender();
	motor ->acelerar();
	motor ->apagar();

	delete motor; //is not needed anymore

	motor = new MotorEconomico();
	cout<<"\n Motor Economico:\n";
	motor ->encender();
	motor ->acelerar();
	motor ->apagar();

	delete motor; //is not needed anymore

	motor = new AdapterMotorElectrico();
	cout <<"\n Motor Electrico:\n";
	motor ->encender();
	motor ->acelerar();
	motor ->apagar();

    delete motor; //is not needed anymore

	return 0;
}
