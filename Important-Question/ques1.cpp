#include <iostream>
using namespace std;

int main() {
    float c=3.2;
    if(c==3.2f) {
        cout<<"Subrat is Good Man";
    }
    else {
        cout<<"He is bad";
    }

    return 0;
}

/* Might be wondering that output will be Subrat is a good Man as c==3.2 is true but actually not . Correct
   output will be else part because c==3.2 condition is not true because by default a decimal value is of 
   double datatype and here variable c is of float type so i.e float == double not true. Hence else part will
   be executed. to make 3.2 floating type we can use to write it like 3.2f where "f" stand for float datatype
*/