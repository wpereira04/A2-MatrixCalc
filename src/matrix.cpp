////////////////////////////////////////////////////////
//
// ECE 3574, A2, Walter Pereira Cruz
// File name: matrix.cpp
// Description: Contains the defenitions for the function
//				matrix.h
// Date:        01/27/2025
//
#include "matrix.h"



// creates a zero filled matrix of dimensions of rows and columns
Matrix createMatrix(int rows, int cols) {
	Matrix matri(rows, std::vector<double>(cols, 0.0));
	return matri;
}

// adds two matrices and returns matrix. throws exception on invalid
Matrix addMatrices(const Matrix& m1, const Matrix& m2) {
	// throws an exception if the matrix operation is not possible
	if (m1.size() != m2.size()||m1[0].size() != m2[0].size()) {
		throw std::invalid_argument("Matrices are of different sizes");
	}

	std::size_t rows = m1.size(); // rows of m1 and m2 are same
	std::size_t cols = m1[0].size(); // cols of m1 and m2 are same
	Matrix res = createMatrix(rows, cols); // result matrix
	// goes through all elements in matrices
	for (std::size_t i = 0; i < rows; i++) { // loops through rows
		for (std::size_t j = 0; j < cols; ++j) { // loops through cols
			res[i][j] = m1[i][j] + m2[i][j]; // adds the elements
		}
	}
	return res;
}

// Function to subtract two matrices
Matrix subtractMatrices(const Matrix& m1, const Matrix& m2) {
	// throws an exception if the matrix operation is not possible
	if (m1.size() != m2.size() || m1[0].size() != m2[0].size()) {
		throw std::invalid_argument("Matrices are of different sizes");
	}

	std::size_t rows = m1.size(); // rows of m1 and m2 are same
	std::size_t cols = m1[0].size(); // cols of m1 and m2 are same
	Matrix res = createMatrix(rows, cols); // result matrix

	for (std::size_t i = 0; i < rows; i++) { // loops through rows
		for (std::size_t j = 0; j < cols; j++) { // loops through cols
			res[i][j] = m1[i][j] - m2[i][j]; // subtracts the elements
		}
	}
	return res;
}

// Function to multiply two matrices
Matrix multiplyMatrices(const Matrix& m1, const Matrix& m2) {
	// throws an exception if the matrix operation is not possible
	if (m1[0].size() != m2.size()) {
		throw std::invalid_argument("Matrices are of incompatible sizes");
	}

	std::size_t rows = m1.size(); // rows of m1
	std::size_t cols = m2[0].size(); // cols of m2
	std::size_t innerDim = m2.size(); // rows of m2 must be the same as cols of m1
	Matrix res = createMatrix(rows, cols); // result matrix

	for (std::size_t i = 0; i < rows; i++) {
		for (std::size_t j = 0; j < cols; j++) {
			double sum = 0;
			for (std::size_t k = 0; k < innerDim; k++) { // gets sum for each element in the result matrix
				sum += m1[i][k] * m2[k][j];
			}
			res[i][j] = sum; // puts sum into res matrix
		}
	}
	return res;
}
