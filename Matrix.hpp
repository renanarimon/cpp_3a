#pragma once
#include<iostream>
#include <vector>
namespace zich{
    class Matrix
    {
    private:
        std::vector<double> _mat;
        int _row;
        int _col;

        friend std::istream & operator >> (std::istream& in,  Matrix& mat); //cin
        friend std::ostream& operator<<(std::ostream& out, const Matrix& mat); //cout
        
        friend Matrix operator*(double scalar, const Matrix& mat); //mat2 = scalar*mat1
        friend Matrix operator*=(double scalar, Matrix& other); //mat1 = scalar*mat1


    public:
        Matrix(std::vector<double> mat, int row, int col); //constructor
        Matrix(); // empty constructor
        ~Matrix(); //distructor
        Matrix operator+(const Matrix& other); // mat = this+other
        Matrix operator+=(const Matrix& other); // this = this+other
        Matrix operator+(); // this = +(this)

        Matrix operator-(const Matrix& other);// mat = this-other
        Matrix operator-=(const Matrix& other);// this = this-other
        Matrix operator-();// mat = -(this)


        bool operator>(const Matrix& other); //this > other --> true
        bool operator<(const Matrix& other); //this < other --> true
        bool operator>=(const Matrix& other); //this >= other --> true
        bool operator<=(const Matrix& other); //this <= other --> true
        bool operator==(const Matrix& other); //this == other --> true
        bool operator!=(const Matrix& other); //this != other --> true

        Matrix operator++(); // ++this
        Matrix operator++(int); // this++
        Matrix operator--(); // --this
        Matrix operator--(int); // this--

        Matrix operator*(double scalar); // mat = this*scalar
        Matrix operator*(const Matrix& other); // mat = this*other
        Matrix operator*=(double scalar); // this = this*scalar
        Matrix operator*=(const Matrix& other); // this = this*other

    };

    
}
