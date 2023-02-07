#include <iostream>
using namespace std;

int main() {
    char oper; 
    float num1, num2; 
    cout << "Enter an operator (+, -, *, /): "; cin >> oper; 
    cout << "Enter two numbers: " << endl; 
    cin >> num1 >> num2;

    switch (oper) { // as we are asking for char input so operators should be single inverted quotes to display  
         case '+':   // char datatype
             cout << num1 << " + " << num2 << " = " << num1 + num2; break; // use of break statement otherwise it will check
         case '-':                                                         // for all the cases
             cout << num1 << " - " << num2 << " = " << num1 - num2; break;
         case '/':
             cout << num1 << " / " << num2 << " = " << num1 / num2; break; // use of * in dividing  case
         case '*':
             cout << num1 << " * " << num2 << " = " << num1 * num2; break; // use / in multiply case
         default:
             // operator is doesn't match any case constant (+, -, *, /)
             cout << "Error! The operator is not correct";
             break;
     }
    return 0;
}