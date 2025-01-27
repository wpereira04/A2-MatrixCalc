////////////////////////////////////////////////////////
//
// ECE 3574, A2, Walter Pereira Cruz
// File name: matrix.cpp
// Description: Contains the defenitions for the function
//				matrix.h
// Date:        01/26/2025
//
#include "matrix.h"


Matrix createMatrix(int rows, int cols) {
	// resizes the vectors to the proper sizes
	std::vector<std::vector<double>> curr;
	curr.resize(cols);
	for (int i = 0; i < curr.capacity(); i++) {
		curr[i].resize(rows); // resizes each vector inside of the first vector
	}
	return curr;
}

Matrix addMatrices(const Matrix& m1, const Matrix& m2)
{	
	// throws an exception if the matrix operation is not possible
	if ((m1.size() != m2.size())||(m1[0].size()!=m2[0].size())) {
		throw std::invalid_argument("Matrices are of different sizes");
	}
	// creates result matrix
	Matrix res = createMatrix(m1[0].size(), m1.size());
	// adds the different elements of the matrices one by one
	for (int i = 0; i < (m1.size() * m1[0].size()); i++) {
		int row = floor(i/m1.size()); // basic calculation for the row using i and the dimensions of the matrices
		int col = i % m1.size(); // basic calculation for the column using i and the dimensions of the matrices
		res[col][row] = m1[col][row] + m2[col][row]; // calculates sum and puts in corresponding result space
	}
	return res;
}

Matrix subtractMatrices(const Matrix& m1, const Matrix& m2) {
	// throws an exception if the matrix operation is not possible
	if ((m1.size() != m2.size()) || (m1[0].size() != m2[0].size())) {
		throw std::invalid_argument("Matrices are of different sizes");
	}
	// creates result matrix
	Matrix res = createMatrix(m1[0].size(), m1.size());
	// subtracts the different elements of the matrices one by one
	for (int i = 0; i < (m1.size() * m1[0].size()); i++) {
		int row = floor(i / m1.size()); // basic calculation for the row using i and the dimensions of the matrices
		int col = i % m1.size(); // basic calculation for the column using i and the dimensions of the matrices
		res[col][row] = m1[col][row] - m2[col][row]; // calculates difference and puts in corresponding result space
	}
	return res;
}

Matrix multiplyMatrices(const Matrix& m1, const Matrix& m2) {
	// throws an exception if the matrix operation is not possible
	if ((m1.size() != m2[0].size()) || (m1[0].size() != m2.size())) {
		throw std::invalid_argument("Matrices are of incompatible sizes");
	}
	// creates result matrix
	Matrix res = createMatrix(m2.size(), m2.size());
	int sizeMult = m1.size();
	if (sizeMult < m2.size()) sizeMult = m2.size();
	for (int i = 0; i < m2.size()*(m1.size() * m1[0].size()); i++) {
		int row1 = floor(i / (2 * sizeMult)); // row1 is used by m1 due to the nature of dot product. 3x2 * 2x3
		int row2 = floor(i / m1.size()); //sets row2 so it the column of m2 is goes 0 then 1
		row2 = row2 % m2.size(); // makes it so when m1 goes to row 2, the column "pointer" is reset to 0
		int col = i % m1.size(); // this variable acts as columns for m1 but rows for m2
		res[row2][row1] += m1[col][row1] * m2[row2][col]; // name of variables don't make sense for m2 but the same values can be used as shown
	}
	return res;
}