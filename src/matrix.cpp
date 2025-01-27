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
	for (std::size_t i = 0; i < curr.capacity(); i++) {
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
	for (std::size_t i = 0; i < (m1.size() * m1[0].size()); i++) {
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
	for (std::size_t i = 0; i < (m1.size() * m1[0].size()); i++) {
		int row = floor(i / m1.size()); // basic calculation for the row using i and the dimensions of the matrices
		int col = i % m1.size(); // basic calculation for the column using i and the dimensions of the matrices
		res[col][row] = m1[col][row] - m2[col][row]; // calculates difference and puts in corresponding result space
	}
	return res;
}

Matrix multiplyMatrices(const Matrix& m1, const Matrix& m2) {
	if ((m1.size() != m2.size())||(m1[0].size()!= m2[0].size())) {
		throw std::invalid_argument("Matrices are of incompatible sizes");
	}
	Matrix res = createMatrix(m1[0].size(), m1.size());
	// subtracts the different elements of the matrices one by one
	for (std::size_t i = 0; i < (m1.size() * m1[0].size()); i++) {
		int row = floor(i / m1.size()); // basic calculation for the row using i and the dimensions of the matrices
		int col = i % m1.size(); // basic calculation for the column using i and the dimensions of the matrices
		res[col][row] = m1[col][row] * m2[col][row]; // calculates difference and puts in corresponding result space
	}
	return res;
	// throws an exception if the matrix operation is not possible
	// TODO: Try doing literal matrix multiplication even if it isn't an actual operation
	// columns of A must be same size of Rows of B
	
}