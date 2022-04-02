#include "Matrix.hpp"
namespace zich{
        Matrix::Matrix(std::vector<double> mat, int row=1, int col=1){
            std::vector<double> v((size_t)(col*row) , 0.0);
            this->_mat = v;
            this->_row = row;
            this->_col = col;
        }
        Matrix::~Matrix(){}
        Matrix Matrix::operator+(const Matrix& other){
            return other;}
        Matrix Matrix::operator+=(const Matrix& other){
            return other;
        }
        Matrix Matrix::operator+(){
            return *this;
        }

        Matrix Matrix::operator-(const Matrix& other){return other;}
        Matrix Matrix::operator-=(const Matrix& other){return other;}
        Matrix Matrix::operator-(){return *this;}

        bool Matrix::operator>(const Matrix& other){return true;}
        bool Matrix::operator<(const Matrix& other){return true;}
        bool Matrix::operator>=(const Matrix& other){return true;}
        bool Matrix::operator<=(const Matrix& other){return true;}
        bool Matrix::operator==(const Matrix& other){return true;}
        bool Matrix::operator!=(const Matrix& other){return true;}

        Matrix Matrix::operator++(){return *this;} // prefix
        Matrix Matrix::operator++(int){return *this;} // postfix
        Matrix Matrix::operator--(){return *this;} // prefix
        Matrix Matrix::operator--(int){return *this;} // postfix

        Matrix Matrix::operator*(int scalar){return *this;}
        Matrix Matrix::operator*(const Matrix& other){return *this;}
        Matrix Matrix::operator*=(int scalar){return *this;}
        Matrix Matrix::operator*=(const Matrix& other){return *this;}

        Matrix operator*(double scalar, const Matrix& A){return A;}
        Matrix operator*=(double scalar, Matrix& A){return A;}

        std::ostream& operator<<(std::ostream& out, const Matrix& mat){return out;}
        std::istream& operator >> (std::istream &in,  Matrix& mat){return in;}
}