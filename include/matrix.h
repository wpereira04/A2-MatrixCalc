////////////////////////////////////////////////////////
//
// ECE 3574, A2, Walter Pereira Cruz
// File name: matrix.h
// Description: Contains the functions belonging to the assignment
// Date:        01/26/2025
//
#ifndef MY_CLASS_H // include guard
#define MY_CLASS_H

#include <vector>  // Make sure vector is included here
#include <stdexcept>
#include <exception>

using Matrix = std::vector<std::vector<double>>;

// creates a zero filled matrix of size cols x rows
Matrix createMatrix(int rows, int cols);

// performs matrix addition of two matrix inputs
Matrix addMatrices(const Matrix& m1, const Matrix& m2);

// performs matrix subtraction of two matrix inputs
Matrix subtractMatrices(const Matrix& m1, const Matrix& m2);

// performs matrix multiplication (i.e. dot product) of two matrix inputs
Matrix multiplyMatrices(const Matrix& m1, const Matrix& m2);

#endif /* MY_CLASS_H */
