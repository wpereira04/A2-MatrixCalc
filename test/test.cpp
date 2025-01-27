////////////////////////////////////////////////////////
//
// ECE 3574, A2, Walter Pereira Cruz
// File name: test.cpp
// Description: Contains the tests for the functions from matrix.h
// Date:        01/26/2025
//
#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "matrix.h"

TEST_CASE("Testing matrix.cpp") {
	// matrices to be used in tests. Makes it easier to write tests.
	Matrix s = createMatrix(2, 3);
	s[0][0] = 1;
	s[0][1] = 4;
	s[1][0] = 2;
	s[1][1] = 5;
	s[2][0] = 3;
	s[2][1] = 6;
	Matrix t = createMatrix(3, 2);
	t[0][0] = 6;
	t[0][1] = 4;
	t[0][2] = 2;
	t[1][0] = 5;
	t[1][1] = 3;
	t[1][2] = 1;
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
	SECTION("Testing createMatrix", "[createMatrix]") {
		Matrix test1 = createMatrix(3, 2);
		// checks if the matrix are of the right size
		for (int i = 0; i < test1.size(); i++) { 
			REQUIRE(test1.size() == 2);
			REQUIRE(test1[i].size() == 3);
		}
	}
	SECTION("Testing addMatrices", "[addMatrices]") {
		Matrix expct = same; // adding doesn't affect dimensions. expct[col][row]
		expct[0][0] = 2; // same (0,0) is 1, so 1 + 1 = 2
		expct[0][1] = 6; // same (0,1) is 3, so 3 + 3 = 6
		expct[1][0] = 4; // same (1,0) is 2, so 2 + 2 = 4
		expct[1][1] = 8; // same (1,1) is 4, so 4 + 4 = 8
		REQUIRE(expct == addMatrices(same, same)); // tests adding same values
		// same + diff == [1,2,3,4] + [4,3,2,1] == [5,5,5,5]
		expct[0][0] = 5; 
		expct[0][1] = 5;
		expct[1][0] = 5;
		expct[1][1] = 5;
		REQUIRE(expct == addMatrices(same, diff)); // tests adding different values
		REQUIRE_THROWS(addMatrices(s, t)); // tests throw
	}
	SECTION("Testing subtractMatrices", "[subtractMatrices]") {
		Matrix expct = createMatrix(2,2); // matrix of zeros. same - same should result in all zeros
		REQUIRE(expct == subtractMatrices(same, same)); // tests subtracting same values
		// same - diff == [1,2,3,4] - [4,3,2,1] == [-3,-1,1,3]
		expct[0][0] = -3;
		expct[0][1] = 1;
		expct[1][0] = -1;
		expct[1][1] = 3;
		REQUIRE(expct == subtractMatrices(same, diff)); // tests subtracting different values
		REQUIRE_THROWS(subtractMatrices(s, t)); // tests throw
	}
	SECTION("Testing multiplyMatrices", "[multiplyMatrices]") {
		Matrix expct1 = createMatrix(2, 2);
		// s * t == [[1,2,3],[4,5,6]] * (dot product) [[6,5],[4,3],[2,1]] == [[1*6+2*4+3*2, 1*5+2*3+3*1],[4*6+5*4+6*2, 4*5+5*3+6*1]]
		// ^^ == [[20,14],[56,41]]
		expct1[0][0] = 20;
		expct1[1][0] = 14;
		expct1[0][1] = 56;
		expct1[1][1] = 41;

		// t * s == [[6,5],[4,3],[2,1]] * (dot product) [[1,2,3],[4,5,6]] == [[26,37,48],[16,23,30],[6,9,12]]
		Matrix expct2 = { {26,16,6},{37,23,9},{48,30,12} };
		// t, s is 3x3
		// s, t is 2x2

		REQUIRE(multiplyMatrices(s, t) == expct1); // tests matrix multiplication in one way
		REQUIRE(multiplyMatrices(t, s) == expct2); // tests matrix multiplication in the reverse way
		REQUIRE_THROWS(multiplyMatrices(s, diff)); // tests throw
	}
}