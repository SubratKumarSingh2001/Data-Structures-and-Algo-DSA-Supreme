#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>> &mat) {
    int m = mat.size();

    // anticlockwise rotation in 90deg
    // first transpose the matrix
    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // now reverse each column to get the required matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m / 2; j++) {
            int temp = mat[j][i];
            mat[j][i] = mat[m - j - 1][i];
            mat[m - j - 1][i] = temp;
        }
    }

    //clockwise rotation in 90deg
    // first transpose the matrix
    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // now reverse each column to get the required matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m / 2; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[i][m-j-1];
            mat[i][m-j-1] = temp;
        }
    }
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    cout<<"Original Matrix is : "<<endl;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            cout <<  matrix[i][j] << " ";
        }
        cout << endl;
    }
    rotate(matrix);
    cout<<"Matrix after 90 deg clockwise rotation : " <<endl;

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}