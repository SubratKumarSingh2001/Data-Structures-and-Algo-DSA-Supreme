#include <iostream>
using namespace std;

float celsiusToFahren(int celsius) {
    float C = celsius; 
    float F;
    F = C*9/5+32;

    return F;
}


int main() {
    float celsius;
    cout<<"Enter the value of Celsius : "; cin>>celsius;
    float fahrenheit = celsiusToFahren(celsius);
    cout<<"The "<<celsius<<"C is "<<fahrenheit<<"F";

    return 0;
}