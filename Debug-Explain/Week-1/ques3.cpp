#include <iostream>
using namespace std;

int main() { // we can use void as return type but standard c++ complier wont understand it
     float l=10, b=78;
	 float P = 2*(l+b); // datatype of variable P not declared also * multiply operator after 2
	 printf("Perimeter=%f", P); // %f is used to print floating point number in c language along with printf
     
     return 0;
}
