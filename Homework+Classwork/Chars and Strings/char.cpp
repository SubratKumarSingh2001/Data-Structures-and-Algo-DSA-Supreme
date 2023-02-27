#include <iostream>
using namespace std;

int main() {
    // char name[100];
    // cin>>name;
    // cout<<name;
    
    //we can store character in int datatype as it will take its ascii value
    // int arr[10] = {2, 4, 'a','b',5, 7, 8};
    // for(int i=0; i<7; i++) {
    //     cout<< arr[i]<<" ";
    // }
    
    //we can store int value in char datatype using single quotes
    // int arr[10] = {2, 4, 'a','b',5, 7, 8};
    // for(int i=0; i<7; i++) {
    //     cout<< arr[i]<<" ";
    // }
 
    //you can take single character as an input
    // char ch[100];
    // ch[0]='S';
    // ch[1]='u';
    // ch[2]='b';
    // cout<<ch[0]<<ch[1]<<ch[2];
    // cin>>ch[3]>>ch[4]>>ch[5];
    // for(int i=0; i<6; i++) {
    //     cout<< ch[i];
    // }

    //after the complettion of string the last block is occupied with \0 indicating null character string termiante
    // char name[100];
    // cin>>name;
    // for(int i=0; i<7; i++) {
    //     cout<<"value at " <<i << "is "<<name[i]<<endl;
    // }
    
    //after actually last block hold i.e null character
    // int last = (int)name[6];
    // cout<<last;
    
    //if you want to take strings along with spaces;
    char name[100];
    cin.getline(name, 50);
    cout<< name;
    
    
}