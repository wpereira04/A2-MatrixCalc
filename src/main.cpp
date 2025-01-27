////////////////////////////////////////////////////////
//
// ECE 3574, A2, Walter Pereira Cruz
// File name: main.cpp
// Description: Contains the test values that were used in debugging
// Date:        01/26/2025
//
#include "matrix.h"
#include <iostream>
int main() {
	Matrix s = createMatrix(3, 3);
	s[0][0] = 1;
	s[0][1] = 4;
	s[0][2] = 7;
	s[1][0] = 2;
	s[1][1] = 5;
	s[1][2] = 8;
	s[2][0] = 3;
	s[2][1] = 6;
	s[2][2] = 9;
	Matrix t = createMatrix(3,2);
	t[0][0] = 6;
	t[0][1] = 4;
	t[0][2] = 2;
	t[1][0] = 5;
	t[1][1] = 3;
	t[1][2] = 1;
	Matrix res = multiplyMatrices(s, t);
	for (int i = 0; i < (res.size() * res[0].size()); i++) {
		int row = floor(i / res.size()); // basic calculation for the row using i and the dimensions of the matrices
		int col = i % res.size(); // basic calculation for the column using i and the dimensions of the matrices
		std::cout << res[col][row] << " ";
	}
	//std::cout << s.size()<< res[0][0] << res[0][1] << res[1][0] << res[1][1];
	return s.size();
}