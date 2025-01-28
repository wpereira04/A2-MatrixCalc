////////////////////////////////////////////////////////
//
// ECE 3574, A2, Walter Pereira Cruz
// File name: main.cpp
// Description: Contains the test values that were used in debugging
// Date:        01/27/2025
//
#include "matrix.h"

int main() {
	
	Matrix t = createMatrix(3,2);
	t[0][0] = 6;
	t[0][1] = 4;
	t[0][2] = 2;
	t[1][0] = 5;
	t[1][1] = 3;
	t[1][2] = 1;
	for (int i = 0; i < (t.size() * t[0].size()); i++) {
		int row = floor(i / t.size()); // basic calculation for the row using i and the dimensions of the matrices
		int col = i % t.size(); // basic calculation for the column using i and the dimensions of the matrices
		//std::cout << res[row][col] << " ";
	}
	//std::cout << s.size()<< res[0][0] << res[0][1] << res[1][0] << res[1][1];
	return t.size();
}