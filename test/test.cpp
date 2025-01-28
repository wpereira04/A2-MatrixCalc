////////////////////////////////////////////////////////
//
// ECE 3574, A2, Walter Pereira Cruz
// File name: test.cpp
// Description: Contains the tests for the functions from matrix.h
// Date:        01/27/2025
//
#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "matrix.h"

TEST_CASE("Testing matrix.cpp definitions") {
	// Matrices to be used in tests
	Matrix s = createMatrix(2, 3);
	s[0][0] = 1;
	s[0][1] = 2;
	s[0][2] = 3;
	s[1][0] = 4;
	s[1][1] = 5; 
	s[1][2] = 6;

	Matrix t = createMatrix(3, 2);
	t[0][0] = 6;
	t[0][1] = 5;
	t[1][0] = 4;
	t[1][1] = 3;
	t[2][0] = 2;
	t[2][1] = 1;

	Matrix same = createMatrix(2, 2);
	same[0][0] = 1;
	same[0][1] = 3;
	same[1][0] = 2;
	same[1][1] = 4;

	Matrix diff = createMatrix(2, 2);
	diff[0][0] = 4; 
	diff[0][1] = 2;
	diff[1][0] = 3;
	diff[1][1] = 1;

	SECTION("Testing createMatrix") {
		Matrix test = createMatrix(3, 2);
		REQUIRE(test.size() == 3);
		for (int i = 0; i < test.size(); i++) {
			REQUIRE(test[i].size() == 2);
		}
	}

	SECTION("Testing addMatrices") {
		Matrix expect = same;  // copy of `same`
		expect[0][0] = 2;
		expect[0][1] = 6;  
		expect[1][0] = 4;
		expect[1][1] = 8;

		REQUIRE(addMatrices(same, same) == expect);  // tests adding same values

		expect[0][0] = 5;
		expect[0][1] = 5;
		expect[1][0] = 5;
		expect[1][1] = 5;

		REQUIRE(addMatrices(same, diff) == expect);  // tests adding different values
		REQUIRE_THROWS(addMatrices(s, t));  // tests throw
	}

	SECTION("Testing subtractMatrices") {
		Matrix expct = createMatrix(2, 2);  // Zero filled matrix

		REQUIRE(subtractMatrices(same, same) == expct);  // tests subtracting same values

		expct[0][0] = -3;
		expct[0][1] = 1; 
		expct[1][0] = -1;
		expct[1][1] = 3;

		REQUIRE(subtractMatrices(same, diff) == expct);  // tests subtracting different values
		REQUIRE_THROWS(subtractMatrices(s, t));  // tests throw
	}

	SECTION("Testing multiplyMatrices") {
		Matrix expct1 = createMatrix(2, 2);
		expct1[0][0] = 20;
		expct1[0][1] = 14;  
		expct1[1][0] = 56; 
		expct1[1][1] = 41;

		Matrix expct2 = createMatrix(3, 3);  
		expct2[0][0] = 26;
		expct2[0][1] = 37;
		expct2[0][2] = 48;
		expct2[1][0] = 16;
		expct2[1][1] = 23;
		expct2[1][2] = 30;
		expct2[2][0] = 6; 
		expct2[2][1] = 9; 
		expct2[2][2] = 12;

		REQUIRE(multiplyMatrices(s, t) == expct1);  // tests matrix multiplication in one way
		REQUIRE(multiplyMatrices(t, s) == expct2);  // tests matrix multiplication in the reverse way
		REQUIRE_THROWS(multiplyMatrices(s, diff));  // tests throw
	}
}