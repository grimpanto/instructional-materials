
class Animal {
    void make_noise() { System.out.println("beep beep"); }
}

class Dog extends Animal {
    void make_noise() { System.out.println("bow-bow"); }
}

class Cat extends Animal {
    void make_noise() { System.out.println("meow-meow"); }
}

class AnimalBreeder {
    Animal make_animal() { return new Animal(); }
    void say_hi(Animal a) { a.make_noise(); }
}

class DogBreeder extends AnimalBreeder {
    Dog make_animal() { return new Dog(); }
    void say_hi(Dog d) { d.make_noise(); }
}

public class Test {
    public static void main(String[] args) {
        Animal animals[] = new Animal[5];
        Dog dogs[] = new Dog[5];
        
        animals = dogs;
        animals[0] = new Dog();
        // animals[1] = new Cat(); -> ArrayStoreException

        AnimalBreeder ab = new DogBreeder();
        ab.make_animal().make_noise();
        ab.say_hi(new Dog());

        DogBreeder db = new DogBreeder();
        db.say_hi(new Dog());
    }
}
