#include "doctest.h"
#include "Matrix.hpp"
#include <random>
using namespace zich;

std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
std::vector<double> arr1 = {1, 2, 3, 3, 2, 1, 1, 2, 3};

/*func to generate random float*/
double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

// constructor input
TEST_CASE("constructor")
{
    CHECK_THROWS_MESSAGE(Matrix(identity, -1, 1), "row must be positive");
    CHECK_THROWS_MESSAGE(Matrix(identity, 1, -1), "col must be positive");
    CHECK_THROWS_MESSAGE(Matrix(identity, -1, -1), "matrix size must be positive");
    CHECK_THROWS_MESSAGE(Matrix(identity, 9, 2), "matrix size dosen't match col*row");
    CHECK_THROWS_MESSAGE(Matrix(identity, 0, 9), "matrix size dosen't match col*row");
    CHECK_THROWS_MESSAGE(Matrix(identity, 9, 0), "matrix size dosen't match col*row");

    // arr.size == col*row
    CHECK_THROWS_MESSAGE(Matrix(identity, 3, 1), "arr.size != col*row");
    CHECK_NOTHROW_MESSAGE(Matrix(identity, 3, 3), "arr.size == col*row");
    CHECK_NOTHROW_MESSAGE(Matrix(identity, 9, 1), "arr.size == col*row");

    // if arr.size is prime --> can't make mat!
    for (size_t i = 2; i < 100; i++)
    {
        bool isPrime = false;
        std::vector<double> arr;
        arr.assign(i, 1.0);
        // loop to check if i is prime
        for (size_t j = 2; j <= i / 2; ++j)
        {
            if (i % j == 0)
            {
                CHECK_NOTHROW_MESSAGE(Matrix(arr, i, 1), "arr.size == col*row");
                isPrime = true;
                break;
            }
        }
        if (!isPrime)
            CHECK_THROWS_MESSAGE(Matrix(arr, i, 1), "arr size can't be prime");
    }
}

TEST_CASE("math_operators")
{
    SUBCASE("square_mat")
    {

        // check random squared matrix, size 1*1 --> 1000*1000
        srand(time(NULL));

        std::vector<double> arr = {1, 2, 3, 4};
        std::vector<double> arrAnsPlus = {2, 4, 6, 8};
        std::vector<double> arrAnsMinus = {0, 0, 0, 0};
        std::vector<double> arrAnsUMinus = {-1, -2, -3, -4};
        std::vector<double> arrDiffSize = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        Matrix mat(arr, 2, 2);
        Matrix matAnsPlus(arrAnsPlus, 2, 2);
        Matrix matAnsMinus(arrAnsMinus, 2, 2);
        Matrix matAnsUMinus(arrAnsUMinus, 2, 2);
        Matrix matAnsDiff(arrDiffSize, 3, 3);

        CHECK_EQ(mat + mat, matAnsPlus);
        CHECK_EQ(+mat, mat);
        CHECK_EQ(mat - mat, matAnsMinus);
        CHECK_EQ(-mat, matAnsUMinus);

        CHECK_THROWS_MESSAGE(mat + matAnsDiff, "matrixs must be same size");
        CHECK_THROWS_MESSAGE(mat - matAnsDiff, "matrixs must be same size");
        CHECK_THROWS_MESSAGE(mat += matAnsDiff, "matrixs must be same size");
        CHECK_THROWS_MESSAGE(mat -= matAnsDiff, "matrixs must be same size");
        // check if correct!
        CHECK_EQ(mat += mat, mat);
        CHECK_EQ(mat -= mat, mat);
    }
    SUBCASE("non-square_mat")
    {
        std::vector<double> arr3 = {1, 2, 3, 4, 5, 6};
        std::vector<double> arrAns = {2, 4, 6, 8, 10, 12};
        Matrix mat3(arr3, 3, 2);
        Matrix mat4(arr3, 2, 3);
        Matrix matAns(arrAns, 3, 2);
        CHECK_THROWS(mat3 + mat4);     // not same size
        CHECK_EQ(mat3 + mat3, matAns); // same size
    }
}
TEST_CASE("compare_operators")
{
    std::vector<double> arr1 = {1, 2, 3, 4, 5, 6};
    std::vector<double> arr2 = {6, 5, 4, 3, 2, 1};
    std::vector<double> arr3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix mat1(arr1, 3, 2);
    Matrix mat2(arr1, 2, 3);
    Matrix mat3(arr2, 3, 2);
    Matrix mat4(arr3, 3, 3);
    CHECK_FALSE_MESSAGE(mat1 == mat2, "diff size");
    CHECK_FALSE_MESSAGE(mat1 == mat3, "diff numbers in mat");
    CHECK(mat1 == mat1);

    CHECK_FALSE(mat1 != mat1);
    CHECK(mat1 != mat2);
    CHECK(mat1 != mat3);
    CHECK(mat4 != mat3);

    CHECK(mat4 > mat1);
    CHECK(mat1 < mat4);
    CHECK(mat4 >= mat1);
    CHECK(mat1 <= mat4);
    CHECK(mat1 >= mat2);
    CHECK(mat1 <= mat2);
}
TEST_CASE("increment/decreasement")
{
    std::vector<double> arr1 = {0, 0, 0, 0, 0, 0};
    std::vector<double> arr2 = {1, 1, 1, 1, 1, 1};
    Matrix mat1(arr1, 3, 2);
    Matrix mat2(arr2, 3, 2);
    mat1++;
    CHECK(mat1 == mat2);     // after mat++
    CHECK(++mat1 == ++mat2); // prefix both
    CHECK(mat1++ == mat2++); // postfix both
    CHECK(mat1++ == mat2);   // postfix 1 --> still equal
    CHECK(mat1++ != mat2);   // not equals anymore!
    CHECK(mat1-- != mat2);   // yet not equals
    CHECK(mat1 != mat2);     // now equals

    std::vector<double> arr3 = {-1, 4, 6, 2};
    Matrix mat3(arr3, 2, 2);
    std::vector<double> arr4 = {-1, 4, 6, 2};
    Matrix mat4(arr4, 2, 2);

    CHECK(mat3-- == mat4);
    CHECK(mat3 == --mat4);
}
TEST_CASE("multiplication")
{
    // m*n x n*l: mull is legall
    SUBCASE("legall_mull")
    {
        SUBCASE("squared_mat")
        {
            std::vector<double> arr3 = {1, 2, 3, 4};
            Matrix mat3(arr3, 2, 2);
            std::vector<double> arr4 = {0, -1, 2, 1};
            Matrix mat4(arr4, 2, 2);
            std::vector<double> arr5 = {4, 1, 8, 1};
            Matrix mat5(arr5, 2, 2);
            CHECK(mat3 * mat4 == mat5);
            CHECK(mat3 * mat4 != mat3);
        }

        SUBCASE("non-squared_mat")
        {
            std::vector<double> arr3 = {1, 2, 3, 4, 5, 6};
            Matrix mat3(arr3, 3, 2);
            std::vector<double> arr4 = {1, 2, 1, 2, 1, 2};
            Matrix mat4(arr4, 2, 3);
            std::vector<double> arr5 = {5, 4, 5, 11, 10, 11, 17, 16, 17};
            Matrix mat5(arr5, 3, 3);
            std::vector<double> arr6 = {12, 16, 15, 20};
            Matrix mat6(arr6, 2, 2);
            std::vector<double> arr7 = {-2, -4, -6, -8, -10, -12};
            Matrix mat7(arr7, 3, 2);
            CHECK(mat3 * mat4 == mat5);
            CHECK(mat4 * mat3 == mat6);
            CHECK((-2) * mat3 == mat7);
            CHECK(mat3 * (-2) == mat7);

            // change origin mat
            Matrix mat3Copy(arr3, 3, 2);
            mat3 *= mat4;
            CHECK(mat3 == mat5);
            CHECK(mat3 != mat3Copy);

            Matrix mat4Copy(arr4, 3, 2);
            mat4 *= 3;
            CHECK(mat4 != mat4Copy);
        }
    }
    // m*n x k*l: mull is ilegall if   n != k
    SUBCASE("illegall_mull")
    {
        std::vector<double> arr3 = {1, 2, 3, 4, 5, 6};
        Matrix mat3(arr3, 3, 2);
        std::vector<double> arr4 = {1, 2, 3, 4};
        Matrix mat4(arr4, 4, 1);
        std::vector<double> arr5 = {};
        Matrix mat5(arr5, 0, 0);
        std::vector<double> arr6 = {12, 16, 15, 20};
        Matrix mat6(arr6, 2, 2);
        std::vector<double> arr7 = {-2, -4, -6, -8, -10, -12, 1, 3, 2};
        Matrix mat7(arr7, 3, 3);

        CHECK_THROWS_MESSAGE(mat3 * mat3, "illegall mat sizes to mull");
        CHECK_THROWS_MESSAGE(mat3 * mat4, "illegall mat sizes to mull");
        CHECK_THROWS_MESSAGE(mat5 * mat4, "illegall mat sizes to mull");
        CHECK_THROWS_MESSAGE(mat7 * mat6, "illegall mat sizes to mull");
    }
}