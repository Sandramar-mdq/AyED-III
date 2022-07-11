#include <iostream>
#define MODERN


using namespace std;

/* *
* Interfaz de producto base común a todos los productos. 
* Los clientes trabajarán con productos a través de esta interfaz, 
*/
class FurnitureFactory {
 public:
  virtual void create() = 0;
 };


//Clase concreta línea de productos estilo Moderno.

class ModernTable : public FurnitureFactory {
 public:
  void create() { cout << "Mesa Estilo Moderno\n"; }
};
class ModernChair : public FurnitureFactory {
 public:
  void create() { cout << "Silla Estilo Moderno\n"; }
};


//Clase concreta línea de productos estilo Victoriano.
 
class VictorianTable : public FurnitureFactory {
 public:
  void create() { cout << "Mesa Estilo Victoriano\n"; }
};
class VictorianChair : public FurnitureFactory {
 public:
  void create() { cout << "Silla Estilo Victoriano\n"; }
};


/**
 * Factory abstracta define métodos para crear 
 * todos los productos relacionados.
 */
class Factory {
 public:
  virtual FurnitureFactory *create_table() = 0;
  virtual FurnitureFactory *create_chair() = 0;
};

/**
 * Las clases concretas implementan el método de fábrica 
 * para crear productos correspondientes a cada línea/familia.
 * crean productos concretos pero los devuelven como abstractos.
 */

class ProductModernFactory : public FurnitureFactory {
 public:
  FurnitureFactory *create_table() {
    return new ModernTable;
  }
 FurnitureFactory *create_chair() {
    return new ModernChair;
  }
 };

class ProductVictorianFactory : public FurnitureFactory {
 public:
  FurnitureFactory *create_table() {
    return new VictorianTable;
  }
  FurnitureFactory *create_chair() {
    return new VictorianChair;
  } 
};


//El cliente recibe un objeto de fábrica.

class Client {
 private:
  Factory *factory;

 public:
  Client(Factory *f)
  {
    factory = f;
  }

  void create()  {
    FurnitureFactory *ff = factory->create_table();
    ff->create();
    display_modern();
    display_victorian();
  }

  void display_modern()   {
    FurnitureFactory *ff[] = {
        factory->create_chair(),
        factory->create_table()
   };
    ff[0]->create();
    ff[1]->create();
}

 void display_victorian()   {
    FurnitureFactory *ff[] = {
        factory->create_chair(),
        factory->create_table()
  };
    ff[0]->create();
    ff[1]->create();
  } 
};


//
int main() 
{
  Factory *factory;

#ifdef MODERN
  factory = new ProductModernFactory;

#else // VICTORIAN
  factory = new ProductVictorianFactory;

#endif

  Client *c = new Client(factory);
  c->create();
}