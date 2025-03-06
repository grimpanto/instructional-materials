
using System;

class Animal {}

class Dog : Animal {}

class AnimalBreeder {
    public virtual Animal make_animal() { return new Animal(); }
    //public virtual void say_hi(Animal a) { a.make_noise(); }
}

class DogBreeder : AnimalBreeder {
    //public override Dog make_animal() { return new Dog(); }
    // -> 'DogBreeder.make_animal()': return type must be 'Animal' to
    //     match overridden member 'AnimalBreeder.make_animal()'
    //public override void say_hi(Dog a) { d.make_noise(); }
    // ->  'DogBreeder.say_hi(Dog)': no suitable method found to override
}


public class Test {
    static Dog make_dog() { return new Dog(); }
    static void make_noise1(Dog d) { Console.WriteLine("bow-bow"); }
    static void make_noise2(Animal d) { Console.WriteLine("beep beep"); }
    
    public static void Main() {
        Func<Animal> func = make_dog;
        Action<Dog> action1 = make_noise1;
        Action<Dog> action2 = make_noise2;
        //Action<Animal> action3 = make_noise1;
    }
}
