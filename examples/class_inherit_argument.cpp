#include <iostream>

class Animal {
  public:
    virtual void speak() { std::cout << "I'm animal\n"; }
};

class Dog : public Animal {
  public:
    void speak() { std::cout << "I'm dog\n"; }
};

class SpecialDog : public Dog {
  public:
    void speak() { std::cout << "I'm special dog\n"; }
};

void speak(Animal* a) {
    a->speak();
}

int main() {
    auto* animal = new Animal;
    auto* dog = new Dog;
    speak(dog);  // directly Animal->speak without `virtual` // I'm animal
    auto* sdog = new SpecialDog;
    speak(sdog);  // mro
}
