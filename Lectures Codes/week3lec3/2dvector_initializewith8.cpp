#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int row, col;
    cout << "Enter the number of rows and columns: ";
    cin >> row >> col;
    vector<vector<int>> arr(row, vector<int>(col, -8));
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}