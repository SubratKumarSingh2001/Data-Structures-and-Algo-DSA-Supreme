#include <iostream>
using namespace std;

int main() {
    //declare a integer type variable
    // int age;
    
    // //print Enter the score
    // cout << "Enter the age " << endl;
    
    // //take input into score variable
    // cin >> age;
    
    // //if condition
    // if(age >=18) {
    //  cout << "I can vote" << endl;
    // }
    // else {
    //  cout << "I cannot vote" << endl;
    // }


    // int marks;
    // cin >> marks;

    //nested if-else
    // if(marks >=90) {
    //  cout << "A grade";
    // }
    // else if(marks >=80){
    //  cout << "B Grade";
    // }
    // else if(marks>=60){
    //  cout << "C Grade";
    // }
    // else if(marks >=40) {
    //  cout << "D grade";
    // }
    // else{
    //  cout << "F Grade";
    // }
        

    //if-elseif-else

    // if(marks >=90) {
    //  cout << "A";
    // }
    // else if (marks >= 80){
    //  cout << "B";
    // }
    // else if(marks >= 60) {
    //  cout << "C";
    // }
    // else if(marks >=40) {
    //  cout << "D";
    // }
    // else{
    //  cout << "F";
    // }

    // for(int i=0; i<5; i = i+1 ) {
    //  cout <<" Love Babbar "<< endl;
    // }

    // for(int i=0; i<5; i = i + 1){
    //  cout << i << endl;
    // }

    // for(int i=5; i>0; i = i-1) {
    //  cout << i << endl;
    // } 

    // for(int i=1; i<=10; i=i+1){
    //  cout << 2*i << endl;
    // }

    // for(int i=0; i<=5; i=i+2){
    //  cout << i << endl;
    // }

    // for(int i=1; i<=5; i=i+2){
    //  cout << i << endl;
    // }

    // for(int i=1; i<10; i=i*2){
    //  cout << i << endl;
    // }

    // for(int i=100; i>0; i=i/2){
    //  cout << i << endl;
    // }

    // for(int i=5; (i>=0 && i<=10); i=i+1) {
    //  cout << i << endl;
    // }

    // int i=0;
    // for(; ; ) {
    //  if(i<5)
    //  {
    //      cout << i << endl;
    //      i=i+1;
    //  }
    // }

//Printing Solid rectangle
    //outer loop - row obeserve
    // for(int row=0; row<3; row=row+1) {
    //  //inner loop - col observe
    //  for(int col=0; col<5; col=col+1) {
    //      cout << "* ";
    //  }
    //  cout << endl;
    // }


    // for(int col=0; col<5; col=col+1) {
        
    //  for(int row=0; row<3; row=row+1) {
    //      cout << "* ";
    //  }
    //  cout << endl;
    // }

    // int n;
    // cin >> n;
    //Solid Rectangle
    //outer looop
    // row += 1 is same as row = row +1
    // for(int row=0;row<n; row += 1) {
    //  ///inner 
    //  //col += 1 is same as col = col + 1
    //  for(int col=0; col<n; col+=1) {
    //      cout << "* ";
    //  }
    //  cout << endl;
    // }

    // int rowCount, colCount;
    // cin >> rowCount;
    // cin >> colCount;
    
    // //Hollow Rectangle
    // for(int row=0; row<rowCount; row=row+1) {
    //  //first row or last row -> print 5 *
    //  if(row == 0  || row == rowCount-1 ){
    //      for(int col=0; col<colCount; col++) {
    //          cout << "* ";
    //      }
    //  }
    //  else {
    //      //remainging middle rows
    //      //first star
    //      cout << "* ";
    //      //spaces
    //      for(int i=0; i< colCount-2; i=i+1){
    //          cout << "  ";
    //      }
    //      //last star
    //      cout << "* ";
    //  }
    //  cout << endl;
    // }

    //number of rows
    // int n;
    // cin >> n;

    // for(int row=0; row<n; row=row+1) {
    //  for(int col=0; col < row+1; col = col + 1) {
    //      cout << "*";
    //  }
    //  cout << endl;
    // }

    //number of rows
    // int n;
    // cin >> n;

    // for(int row=0; row<n; row=row+1) {
    //  for(int col=0; col<n-row; col=col+1){
    //      cout << "*";
    //  }
    //  cout << endl;
    // }


    //number of rows = n
//  int n ;
//  cin >> n;
//  for(int row=0; row<n; row=row+1) {
//      for(int col=0; col<row+1; col=col+1) {
//          cout << col+1;
//      }
//      cout << endl;
//  }

    //number of rows -> n

    int n;
    cin >> n;
    for(int row=0; row<n; row=row+1) {
        for(int col=0; col<n-row; col = col+1) {
            cout << col+1 ;
        }
        cout << endl;
    }

    
 }

