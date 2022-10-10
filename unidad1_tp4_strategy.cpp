#include <iostream>
using namespace std;


class Strategy{
  public:
  virtual ~Strategy(){};
  virtual void ExecuteAlgoritm()=0;
};

class Peaton :public Strategy
{
  public:
   virtual void ExecuteAlgoritm()
   {
    cout <<"Calcular ruta de Peaton... "<< endl;
   }

};

class Coche :public Strategy
{
  public:
     virtual void ExecuteAlgoritm()
   {
    cout <<"Calcular ruta en Coche... "<< endl;
   }

};
class TransportePublico :public Strategy
{
  public:
   virtual void ExecuteAlgoritm()
   {
    cout <<"Calcular ruta de transporte Publico... "<< endl;
   }

};

class Navigator{
    private:
    Strategy * _strategy;
    public:
       Navigator(Strategy *strategy): _strategy(strategy){}

       void set_strategy(Strategy *strategy){
        _strategy=strategy;

           }
       void calculateRoute(){
        _strategy->ExecuteAlgoritm();

       }
       void InterfazContexto(){
       _strategy->ExecuteAlgoritm();
      }

};

int main()
{
    Strategy *defaultStrategy = new Peaton();
    Navigator *nav = new Navigator(defaultStrategy);
    std::cout << "El cliente calcula la ruta del Peaton: " << std::endl;
    nav->calculateRoute();
    std::cout << "------------------------------------" << std::endl;
    std::cout << "El cliente ahora calcula la ruta del Coche: " << std::endl;
    nav->set_strategy(new Coche());
    nav->calculateRoute();
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Ahora el cliente calcula la ruta del Tranporte Publico: " << std::endl;
    nav->set_strategy(new TransportePublico());
    nav->calculateRoute();

    return 0;
}


