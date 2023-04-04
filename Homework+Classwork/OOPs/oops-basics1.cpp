#include <iostream>
#include <string>
using namespace std;

class Animal {
    /*
    here we cant access the properties and behaviour bcz by default all the members are marked under
    private section. 
    members means all data members and member functions.
    Benefit of marking all the members under private or by default private due to security purpose,
    so that no one can access it easly.
     */
    //state or properties 
    private : //can access inside of class but not outside 
        int weight;
    public : /* public is access modifier means which tells the scope of members of class other access 
    modifier are public, private and protected
    */
        int age;
        string name;

        //behaviour or function
        void eat() {
            cout<<"Animal is Eating" <<endl;
        }
        void walk() {
            cout<<"Animal is walking" <<endl;
        }

        //creating getters and setters to access member under private
        int getWeight() {
            return weight;
        }
        //how to differentiate between date members and input when both are named with same name;
        void setWeight(int weight) {
            this->weight = weight; //when input and data member have same name we can use this pointer 
            //which point to the current object. Here current object is lion and cat
        }

        //creating constructor
        //default constructor with no input parameters
        Animal() {
            this->age = 0;
            this->weight = 0;
            this->name = "";
            cout<<"Default Constructor worked " <<endl;
        }

        //parametrized constructor single parameter
        Animal(int age) {
            this-> age = age;
            cout<<"Parameterized Constructor 1 called" <<endl;
        }
        //parametrized constructor two parameter
        Animal(int age, int weight) {
            this-> age = age;
            this-> weight = weight;
            cout<<"Parameterized Constructor 2 called" <<endl;
        }
        //parametrized constructor three parameter
        Animal(int age, int weight, string name) {
            this->age = age;
            this->weight = weight;
            this->name = name;
            cout<<"Parameterized Constructor 3 called" <<endl;
        }

        //copy constructor
        Animal(Animal &donkey) {
            this->age = donkey.age;
            this->weight = donkey.weight;
            this->name = donkey.name;
            cout<<"Copy Constructor called "<<endl;
        }

        //Destructor
        ~Animal() {
            cout<<"Destructor called " <<endl;
        }

        void print() {
            cout<< this->age <<" " <<this->weight << " " <<this->name <<endl;
        }
        
};

int main() {
    //creating object in static memory allocation
    Animal dog;
    //accessing the properties with dot operator
    //dog.age;
    //dog.weight
    /* dog.age and dog.name consists of garbage value and print */
    cout<< dog.age<<endl;
    cout<< dog.name<<endl;

    //initializing the properties/state of a class
    dog.age = 12;
    dog.name = "Sheru";
    cout<<"The age of dog is : "<<dog.age<<endl;
    cout<<"Name of dog is : "<<dog.name<<endl;

    //how to access the data members declare under private section
    //we can access it by creating getters and setters
    dog.setWeight(43);
    cout<<"The weight is : "<<dog.getWeight()<<endl;

    //accessing the behaviour of class with dot operator
    dog.eat();
    dog.walk();


    //creating object in dynamic memory allocation
    /*here cat is an object new keyword allocate space in heap memory and return address which is stored in
    pointer *cat
     */
    Animal *cat = new Animal;
    //one way to create and access object in dynamic memory allocation
    (*cat).age = 15;
    (*cat).name = "cutie";
    cout<<"The age of cat is : " << (*cat).age <<endl;
    cout<<"The name of cat is : " << (*cat).name <<endl;
    //accessing private members in static memory location
    (*cat).setWeight(6);
    cout<<"The weight of cat is : " << (*cat).getWeight() <<endl;

    //another way to create and access object in dynamic
    Animal *lion = new Animal;
    lion->age = 23;
    lion->name = "Rocky";
    cout<<"The age of cat is : " << lion->age <<endl;
    cout<<"The name of cat is : " << lion->name <<endl;
    //accessing private members in dynamic memory allocation
    lion->setWeight(90);
    cout<<"The weight of lion is : " << lion->getWeight() <<endl;
    lion->eat();
    lion->walk();
    
    Default Constructor
    Animal *tiger = new Animal;

    //parameterized constructor 
    //single paramter
    Animal leo(45);
    Animal *jaguar = new Animal(59);
    cout<< "The age of leo is : "<< leo.age<<endl;
    cout<< "The age of jaguar is : " << jaguar->age <<endl<<endl;

    //two parameter
    Animal kutta(10, 15); //static
    Animal *billi = new Animal(6, 9); //dynamic
    cout<< "The age of kutta is : "<< kutta.age <<endl; //accessing age 
    cout<<"The weight of kutta is : " << kutta.getWeight()<<endl; //accessing weight with getters and setters
    cout<< "The age of billi is : " << billi->age <<endl; //accessing age 
    cout<<"The weight of billi is : " << billi->getWeight()<<endl; //accessing weight with getters and setters
    cout<<endl;

    //three parameters
    Animal soup(20, 72, "Supriya");
    Animal *motu = new Animal(21, 68, "Subrat");
    cout<<"The age of soup is : " << soup.age <<endl;
    cout<<"The weight of soup is : " << soup.getWeight() <<endl;
    cout<<"The name of soup is : " << soup.name <<endl;
    cout<<"The age of motu is : " << motu->age <<endl;
    cout<<"The weight of motu is : " << motu->getWeight() <<endl;
    cout<<"The name of motu is : " << motu->name <<endl <<endl;

    //copy constructor
    //two ways to create it 
    Animal horse;
    Animal donkey = horse;

    Animal a;
    Animal b(a);


    //Destructor
    Animal a; //for static destructor calls automatically
    Animal *b = new Animal; //for dynamic we need to manually call the destructor with delete keyword
    delete b;

    printing the print function
    Animal a;
    a.age = 20;
    a.setWeight(58);
    a.getWeight();
    a.name = "Sing";

    Animal b = a;
    cout<<"For object a : " <<endl;
    a.print();
    cout<<"For object b : " <<endl;
    b.print();
    

    //we have change the initial value of string but it will not show any effect in copy object i.e copy 
    //constructor;
    cout<<endl;
    a.name[0] ='K';
    a.print();
    b.print();
    
}