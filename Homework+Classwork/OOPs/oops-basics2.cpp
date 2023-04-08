#include <iostream>
#include <string>
using namespace std;

//A class is a basically example of encapsulation because all the data members and member function are wrapped
//inside a class.
/* Encapsulation is a wrapping data members and members functions inside an entity */
class Animal {
    //state and properties
    private :
        int weight;
    public :
        int age;
        string weight;
    //behaviour or function
    void eat() {
        cout<<"Animal is Eating " <<endl;
    }
};

//inheritnace

//single level inheritance : one parent and one child class
class Animal {
    protected : //if it is private it wont inherit and public then can be access outside/inside of class
        int age;
};

class Dog : public Animal {
    private : 
        string name;
    //to access outside of class as it is marked under protected section
    public :
        void print() {
            cout << this-> age; //accessing the age inside of class dog
        }

        //getter and setters to access name in private section
        string getName() {
            return name;
        }
        void setName(string name) {
            this->name = name;
        } 
};

//Multi-Level Inheritance : one base class and one derived class and derived class be base class for another
//derived class
class Puppy : public Dog {
    public :
        int weight;
        void print() {
            cout << this-> age; //accessing the age inside of class Puppy
        }
};

//multiple inheritance : one derived class and two base class
class Tiger {
    public : 
        int weight; 
};
class Lion {
    public :
        int weight;
};
class Liger : public Tiger, public Lion {
    public :
        int age; //when derived class inherit the same data member so how to differentiate it :: operator
};

//Heirarchial Inheritance : two derived class and one base class
class Car {
    public : 
        int weight;
};
class Scorpio : public Car {
    public :
        string color;
        string model;
};
class Fortuner : public Car {
    public :
    string color;
    string model;
};

//function overloading : same name different parameters and return type must be same 
class Maths {
    public :
        int sum(int a, int b) {
            return a+b;
        }
        int sum(int a) {
            return a;
        }
        int sum(int a, double b) {
            return a+b;
        }
        int sum(int a, int b, int c) {
            return a+b+c;
        }
};

//operator overloading
class Operator {
    public : 
        int val;

        void operator+(Operator &obj2) {
            int value1 = this->val;
            int value2 = obj2.val;
            cout << (value1 - value2) <<endl;
        }
};

int main() {
    //single level inheritance
    Dog lebra;
    /*we cant access it outside of class because int age in animal is protected and mode of inheritance 
    is public the copy of int age will be protected and can be access inside of class 
    */
    cout << d1.age <<endl;

    //to call print func to access age inside the class dog
    lebra.print();
 
    //multi-level inheritance
    Puppy Sheru;
    //Sheru.print();
    /* it will show error as name is marked private inside dog class so it cant so it cant be accessed */
    Sheru.name;
    
    /* name is under private section of class dog so to access outside we need to use getters and setters
    and class puppy inherit class dog with public mode of inheritance all the behaviour and state 
    copied to class puppy and now we can access with getter and setters */
    Sheru.setName("kutta");
    cout<< Sheru.getName() <<endl;
    Sheru.print();

    //multiple inheritance 
    /* one derived to base class is being inherited */
    Liger a;
    cout << a.name << " " << a.age << " " << a.weight <<endl;

    //what if two base class have same data member diamond problem 
    /* this can be accomplished by :: operator */
    Liger a;
    cout << a.Tiger::weight << " " << a.Lion::weight <<endl; //this :: operator will differentiate btw 
    //same date members

    //Heirarchial Inheritance 
    Scorpio a;
    cout << a.model << " " << a.color << " " << a.weight <<endl;

    //Polymorphism 
    //1.Compile time polymorphism
    //a.function overloading
    Maths obj;
    cout << obj.sum(2) <<endl;
    cout << obj.sum(2,3,7) <<endl;
    cout << obj.sum(2,5.76) <<endl;

    //b.operator overloading
    Operator obj1, obj2; //create two objects
    obj1.val = 7; //for obj1 the value will be 7
    obj2.val = 2; //for obj2 the value will be 2
    //the + operator will now subtract the two values
    obj1 + obj2 ;

}