#include "matrix.h"

Matrix& Matrix::operator+=(const Matrix& other) {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
        return *this;
    }
    for (int i = 0; i < rows_ * cols_; ++i) {
        mvec_[i] += other.mvec_[i];
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
        return *this;
    }
    for (int i = 0; i < rows_ * cols_; ++i) {
        mvec_[i] -= other.mvec_[i];
    }
    return *this;
}

Matrix& Matrix::operator*=(real scalar) {
    for (int i = 0; i < rows_ * cols_; ++i) {
        mvec_[i] *= scalar;
    }
    return *this;
}

std::ostream& operator<<(std::iostream& os, const Matrix& matrix) {
    matrix.print(os);
    return os;
}

std::istream& operator>>(std::iostream& is, Matrix& matrix) {
    for (int i = 0; i < matrix.rows_ * matrix.cols_; ++i) {
        real value;
        is >> value;
        matrix.mvec_[i] = value;
    }
    return is;
}

Matrix operator+(const Matrix& A, const Matrix& B) {
    if (A.rows_ != B.rows_ || A.cols_ != B.cols_) {
        return Matrix();
    }
    Matrix result(A.rows_, A.cols_);
    for (int i = 0; i < A.rows_ * A.cols_; ++i) {
        result.mvec_[i] = A.mvec_[i] + B.mvec_[i];
    }
    return result;
}

Matrix operator-(const Matrix& A, const Matrix& B) {
    if (A.rows_ != B.rows_ || A.cols_ != B.cols_) {
        return Matrix();
    }
    Matrix result(A.rows_, A.cols_);
    for (int i = 0; i < A rows_ * A.cols_; ++i) {
        result.mvec_[i] = A.mvec_[i] - B.mvec_[i];
    }
    return result;
}

Matrix operator*(const Matrix& A, const Matrix& B) {
    if (A.cols_ != B.rows_) {
        return Matrix();
    }
    Matrix result(A.rows_, B.cols_);
    for (int i = 0; i < A rows_; ++i) {
        for (int j = 0; j < B cols_; ++j) {
            real sum = 0;
            for (int k = 0; k < A cols_; ++k) {
                sum += A(i, k) * B(k, j);
            }
            result(i, j) = sum;
        }
    }
    return result;
}
