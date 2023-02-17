#include <iostream>
using namespace std;
bool find(int arr[][3], int row, int col, int key)
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == key)
            {
                return true;
                break;
            }
        }
    }
    return false;
}
int main()
{
    int arr[3][3];
    int row = 3;
    int col = 3;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
    int key;
    cout << "Enter the key what you want to search: ";
    cin >> key;
    if (find(arr, row, col, key))
    {
        cout << "found it";
    }
    else
    {
        cout << "not found it";
    }
}