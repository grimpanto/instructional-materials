
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

struct Coat {};


struct DogCoat : Coat {};


struct Animal {
    virtual void make_noise() { puts("beep beep"); }
    //virtual Coat coat() { return coat_; }
    virtual Coat& coat() { return coat_; }
    virtual void set_coat(Coat*) {};
    virtual ~Animal() = default;
  private:
    Coat coat_;
};


struct Dog : Animal {
    void make_noise() override { puts("bow-wow"); }
    //DogCoat coat() override { return DogCoat{}; }  //   invalid covariant return type for ‘virtual DogCoat Dog::coat()’
    DogCoat& coat() override { return coat_; }
    //void set_coat(DogCoat*) override;  //  ‘void Dog::set_coat(DogCoat*)’ marked ‘override’, but does not override
  private:
    DogCoat coat_;
};


int main() {
    Dog golu;
    golu.make_noise();  // -> bow-bow
    Animal* animal{&golu};
    animal->make_noise();  // -> bow-bow

    Animal animals[5]{ Dog{}, Dog{} };
    animals[0].make_noise(); // -> beep beep
    // why? object slicing:
    Animal rex{golu};
    rex.make_noise(); // -> beep beep

    // keine Arrays von Referenzen:
    // Animal& animals2[5]; // declaration of ‘animals2’ as array of references

    // Array von Pointer:
    Animal* animals2[5]{ new Dog{}, new Dog{} };
    animals2[0]->make_noise();  // -> bow-bow

    // keine Zuweisung von Arrays mit unterschiedlichen Typen
    Dog* dogs[5];
    //animals2 = dogs;  // incompatible types in assignment
    //dogs = animals2;  // incompatible types in assignment

    vector<Dog> dogs3;
    vector<Animal> animals3;
    //animals3 = dogs3;  //  no match for ‘operator=’...
    //dogs3 = animals3;  //  no match for ‘operator=’...

    
    using AnimalDoctor = function<void(Animal*)>;
    using DogDoctor = function<void(Dog*)>;
    
    auto maxi{[](Animal*){}};
    auto mini{[](Dog*){}};

    DogDoctor a{mini};
    DogDoctor b{maxi};
    //AnimalDoctor c{mini};  // no matching function for call to...
    AnimalDoctor d{maxi};
}
