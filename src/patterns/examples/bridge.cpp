#include <iostream>
using namespace std;

struct TransportVehicle {
    virtual void transport_impl()=0;
};

struct RefrigeratorCar : public TransportVehicle {
    void transport_impl() { cout << "per refrigerator car" << endl; }
};
struct TankTruck : public TransportVehicle {
    void transport_impl() { cout << "per tank truck" << endl; }
};
struct LowLoadingTruck : public TransportVehicle {
    void transport_impl() { cout << "per low-loading truck" << endl; }
};

struct Article {
    Article(TransportVehicle* carrier) : carrier{carrier} {}
    TransportVehicle* carrier;
    virtual void transport() { carrier->transport_impl(); }
};

struct Fish : public Article {
    Fish(TransportVehicle* carrier) : Article{carrier} {}
};

struct Menhir : public Article {
    Menhir(TransportVehicle* carrier) : Article{carrier} {}
};


struct MagicPotion : public Article {
    MagicPotion(TransportVehicle* carrier) : Article{carrier} {}
};


int main() {
    TransportVehicle* carrier{new RefrigeratorCar()};
    Article* fish{new Fish(carrier)};
    fish->transport();
}
