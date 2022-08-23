#include <iostream>

class IHotel {
 public:
  virtual ~IHotel() {}
  virtual std::string Price() const = 0;
};

class ConcreteHotel1Star : public IHotel {
 public:
  std::string Price() const override {
    return " ( Estadia Hotel 1 estrella: 150,00.- ) ";
  }
};

class Decorator : public IHotel {
 protected:
  IHotel* hotel_;
 public:
  Decorator(IHotel* hotel) : hotel_(hotel) {}
  std::string Price() const override {
    return this->hotel_->Price();
  }
};

class ConcreteDecoratorHotelBoutique: public Decorator {
   public:
  ConcreteDecoratorHotelBoutique(IHotel* hotel) : Decorator(hotel) {
  }
  std::string Price() const override {
    return " Hotel Boutique: (" + Decorator::Price() + "200,00.- )";
  }
};

class ConcreteDecoratorPosada: public Decorator {
   public:
  ConcreteDecoratorPosada(IHotel* hotel) : Decorator(hotel) {}
  std::string Price() const override {
    return " Posada: (" + Decorator::Price() + "100,00.- )";
  }
};

void FindHotel(IHotel* hotel) {
  std::cout << " PRESUPUESTO: " << hotel->Price();
  };

int main() {
  IHotel * basic = new ConcreteHotel1Star;
  std::cout << " Busqueda: Hay un Hotel de 1 estrella:  \n";
  FindHotel (basic);
  std::cout << "\n\n";

  IHotel* concretedecoratorhotelboutique = new ConcreteDecoratorHotelBoutique(basic);
  IHotel* concretedecoratorposada = new ConcreteDecoratorPosada(concretedecoratorhotelboutique);
  std::cout << "Busqueda: Hay nuevos hoteles disponibles: \n";
  FindHotel (concretedecoratorposada);
  std::cout << "\n";

  delete basic;
  delete concretedecoratorhotelboutique;
  delete concretedecoratorposada;

  return 0;

}
