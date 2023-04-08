#include <iostream>
#include <string>
using namespace std;

class People {
    public : 
        void speak() { 
            cout<<"Speaking" <<endl;
        }
        People() {
            cout<<"I'm inside People Constructor " <<endl;
        }
};
class Dog : public People {
    public : 
        // creating custom behaviour with same func name as base class func name 
        //it over rides the base class behaviour with custom behaviour
        void speak() { 
            cout<<"Barking" <<endl;
        }
        Dog() {
            cout << "I'm inside Dog Constructor " <<endl;
        }
};

int main () {
    Dog d1;
    d1.speak(); //inheriting the behaviour from base class

    //custom behaviour
    d1.speak();

    //dynamic memory creation
    (*d1).speak(); //one way to dynamically access the members
     d1->speak();  //another way
    //1 case 
    Dog *d1 = new Dog();
    d1->speak();

    //2case
    People *p1 = new People;
    p1->speak();

    //3case
    // upcasting 
    People *p2 = new Dog;
    p2->speak();
    
    // downcasting
    //here dog* because downcasting behave compiler to complier so we are
    //explicitly typecasting
    Dog *d2 = (Dog*) new People();
    d2->speak();

    //Constructor calling 
    //case 1
    People *p1 = new People;
    //case 2
    Dog *d1 = new Dog;

}