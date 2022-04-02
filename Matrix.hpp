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
        friend std::ostream& operator<<(std::ostream&, const Matrix&);
        friend std::istream & operator >> (std::istream &in,  Matrix& mat);
        friend Matrix operator*(double scalar, const Matrix& A);
        friend Matrix operator*=(double scalar, Matrix& A);


    public:
        Matrix(std::vector<double> mat, int row, int col);
        Matrix();
        ~Matrix();
        Matrix operator+(const Matrix& other);
        Matrix operator+=(const Matrix& other);
        Matrix operator+();

        Matrix operator-(const Matrix& other);
        Matrix operator-=(const Matrix& other);
        Matrix operator-();

        bool operator>(const Matrix& other);
        bool operator<(const Matrix& other);
        bool operator>=(const Matrix& other);
        bool operator<=(const Matrix& other);
        bool operator==(const Matrix& other);
        bool operator!=(const Matrix& other);

        Matrix operator++(); // prefix
        Matrix operator++(int); // postfix
        Matrix operator--(); // prefix
        Matrix operator--(int); // postfix

        Matrix operator*(int scalar);
        Matrix operator*(const Matrix& other);
        Matrix operator*=(int scalar);
        Matrix operator*=(const Matrix& other);

    };

    
}
