#include "Matrix.hpp"
#include <iostream>
namespace zich{
        Matrix::Matrix(std::vector<double> mat, int row=1, int col=1){
            std::vector<double> v;
            copy(mat.begin(), mat.end(), back_inserter(v));
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

        bool Matrix::operator>(const Matrix& other) const{return true;}
        bool Matrix::operator<(const Matrix& other) const{return true;}
        bool Matrix::operator>=(const Matrix& other) const{return true;}
        bool Matrix::operator<=(const Matrix& other) const{return true;}
        bool Matrix::operator==(const Matrix& other) const{
            if(
            this->_col == other._col &&
            this->_row == other._row &&
            this->_mat == other._mat){
                return true;
            }
            return false;}
        bool Matrix::operator!=(const Matrix& other) const{return true;}

        Matrix Matrix::operator++(){return *this;} // prefix
        Matrix Matrix::operator++(int){return *this;} // postfix
        Matrix Matrix::operator--(){return *this;} // prefix
        Matrix Matrix::operator--(int){return *this;} // postfix

        Matrix Matrix::operator*(double scalar){return *this;}
        Matrix Matrix::operator*(const Matrix& other){return *this;}
        Matrix Matrix::operator*=(double scalar){return *this;}
        Matrix Matrix::operator*=(const Matrix& other){return *this;}

        Matrix operator*(double scalar, const Matrix& A){return A;}
        Matrix operator*=(double scalar, Matrix& A){return A;}

        std::ostream& operator<<(std::ostream& out, const Matrix& mat){
            for(size_t i=0, k=0; i<mat._row; i++){
                out << "[";
                for(size_t j=0; j<mat._col; j++){
                    if(j == mat._col-1){
                        if(i!=mat._row-1){
                            out << mat._mat.at(k) << "]\n";
                        }else{
                            out << mat._mat.at(k);
                        }
                        
                    }else{
                        out << mat._mat.at(k) << " ";
                    }
                    k++;
                }
            }
            return out << "]";
            }
        std::istream& operator >> (std::istream &in,  Matrix& mat){return in;}
}