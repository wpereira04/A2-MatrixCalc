////////////////////////////////////////////////////////
//
// ECE 3574, A2, Walter Pereira Cruz
// File name: matrix.cpp
// Description: Contains the defenitions for the function
//				matrix.h
// Date:        01/26/2025
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

	int rows = m1.size(); // rows of m1 and m2 are same
	int cols = m1[0].size(); // cols of m1 and m2 are same
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

	int rows = m1.size(); // rows of m1 and m2 are same
	int cols = m1[0].size(); // cols of m1 and m2 are same
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

	int rows = m1.size(); // rows of m1
	int cols = m2[0].size(); // cols of m2
	int innerDim = m2.size(); // rows of m2 must be the same as cols of m1
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

/*
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
	if ((m1.size() != m2[0].size()) || (m1.size() == 0)) {
		throw std::invalid_argument("Matrices are of incompatible sizes");
	}
	Matrix resu = createMatrix(m1[0].size(),m2.size());
	for (std::size_t i = 0; i < m1[0].size(); i++) {
		for (std::size_t j = 0; j < m2.size(); j++) {
			double sum = 0;
			for (std::size_t k = 0; k < m1.size(); k++) {
				sum += m1[k][i] * m2[j][k];
			}
			resu[j][i] = sum;
		}
	}
	return resu;
	if ((m1.size() != m2.size()) || (m1[0].size() != m2[0].size())) {
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
	if (m1.size() != m2[0].size()) {
		throw std::invalid_argument("Matrices are of incompatible sizes");
	}
	// creates result matrix
	Matrix res = createMatrix(m1[0].size(), m2.size());
	std::size_t sizeMult = m1.size();
	if (sizeMult < m2.size()) sizeMult = m2.size();
	for (std::size_t i = 0; i < m2.size() * (m1.size() * m1[0].size()); i++) {
		int row1 = floor(i / (2 * sizeMult)); // row1 is used by m1 due to the nature of dot product. 3x2 * 2x3  TODO: THIS LINE JUST SEEMS WRONG
		int row2 = floor(i / m1.size()); //sets row2 so it the column of m2 is goes 0 then 1
		row2 = row2 % m2.size(); // makes it so when m1 goes to row 2, the column "pointer" is reset to 0
		int col = i % m1.size(); // this variable acts as columns for m1 but rows for m2
		res[row2][row1] += m1[col][row1] * m2[row2][col]; // name of variables don't make sense for m2 but the same values can be used as shown
	}
	return res;
}
*/