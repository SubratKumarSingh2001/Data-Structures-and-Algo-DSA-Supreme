#include <iostream>
using namespace std;

int main() {
	  int n;
	  cin >> n;

	for(int row=0; row<n; row=row+1) {
		
		int col;
		for( col=0; col<row+1; col=col+1) {
			int ans = col + 1;
			char ch = ans + 'A' -1;
			cout << ch;
		}
		
		//reverse counting printing
		for(int col=row; col>=1; col=col-1) {
			int ans = col;
			char ch = ans + 'A' -1;
			cout << ch;
		}
		cout << endl;
	}

	// for(int row=0; row<n; row=row+1) {
		
	// 	for(int col=0; col<row+1; col = col + 1) {
	// 		cout << row+1;
	// 		if(col != row)
	// 			cout << "*";
	// 	}
	// 	cout << endl;
	// }

	// for(int row=0; row<n; row=row+1) {
		
	// 	for(int col=0; col<n-row; col = col + 1) {
	// 		cout << n-row;
	// 		if(col != n-row-1)
	// 			cout << "*";
	// 	}
	// 	cout << endl;
	// }

	

	// for(int row=0; row<n; row = row + 1) {
	// 	//half pyrmaid
	// 	for(int col =0; col<n-row; col = col + 1) {
	// 		cout << "*";
	// 	}

	// 	//space wlaa full puramid 
	// 	for(int col=0; col<2*row+1; col = col + 1) {
	// 		cout <<" ";
	// 	}
		
	// 	//half pyramid
	// 	for(int col =0; col<n-row; col = col + 1) {
	// 		cout << "*";
	// 	}
	// 	cout << endl;
	// }

	// for(int row=0; row<n; row = row + 1) {
	// 	//half pyrmaid
	// 	for(int col =0; col<row+1; col = col + 1) {
	// 		cout << "*";
	// 	}

	// 	//space wlaa full puramid 
	// 	for(int col=0; col<2*n-2*row-1; col = col + 1) {
	// 		cout <<" ";
	// 	}
		
	// 	//half pyramid
	// 	for(int col =0; col<row+1; col = col + 1) {
	// 		cout << "*";
	// 	}
	// 	cout << endl;
	// }

	//hollow dioamond
	// for(int row=0; row<n; row=row+1) {
	// 	//spaces
	// 	for(int col=0;col<n-row-1; col = col + 1) {
	// 		cout << " ";
	// 	}

	// 	//stars
	// 	for(int col=0; col<2*row+1; col = col + 1) {
	// 		//if first character or if last character
	// 		if(col == 0 || col == 2*row) {
	// 			//first character or last character
	// 			cout << "*";
	// 		}
	// 		else{
	// 			cout << " ";
	// 		}
	// 	}

	// 	cout << endl;
	// }

	// for(int row=0; row<n; row=row+1) {
	// 	//spaces
	// 	for(int col=0; col<row; col=col+1) {
	// 		cout <<" ";
	// 	}

		
	// 	//star
	// 	for(int col=0; col<2*n-2*row-1; col = col + 1){
	// 		//if first or last character
	// 		if(col == 0 || col == 2*n - 2*row -2 ) {
	// 			cout << "*";
	// 		}
	// 		else {
	// 			cout << " ";
	// 		}
			
	// 	}
	// 	cout << endl;
		
	// }

	//full puramid
	// for(int row=0; row<n; row= row+1) {
	// 	//space
	// 	for(int col=0; col<n-row-1; col = col + 1) {
	// 		cout <<" ";
	// 	}

	// 	//stars
	// 	for(int col=0; col <row+1; col = col + 1) {
	// 		cout << "* ";
	// 	}
	// 	cout << endl;
	// }
	// //inverted full p[yramid]
	// for(int row=0; row<n; row=row+1) {
	// 	//spaces
	// 	for(int col=0; col<row; col = col + 1) {
	// 		cout << " ";
	// 	}

	// 	//stars
	// 	for(int col=0; col<n-row; col = col + 1) {
	// 		cout << "* ";
	// 	}
	// 	cout << endl;
	// }


}