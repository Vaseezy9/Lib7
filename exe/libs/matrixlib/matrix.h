#include <iostream>
#include <vector>

namespace math {
    typedef double real;

    class Matrix {
        private:
            int cols_;
            int rows_;
            std::vector<real> mvec_;
        public:
            Matrix() = default;

            Matrix(int rows, int cols) : cols_(cols), rows_(rows), mvec_(std::vector<real>(rows * cols)) {}

            real& operator()(int row, int col) {
                return mvec_[row * cols_ + col];
            }

            real operator()(int row, int col) const {
                return mvec_[row * cols_ + col];
            }

            void print() {
                for (int i = 0; i < rows_; ++i) {
                    for (int j = 0; j < cols_; ++j) {
                        std::cout << mvec_[i * cols_ + j] << " ";
                    }
                    std::cout << std::endl;
                }
            }

            Matrix& operator+=(const Matrix& other);

            Matrix& operator-=(const Matrix& other);

            Matrix& operator*=(real scalar);

            friend std::ostream& operator<<(std::iostream& os, const Matrix& matrix);

            friend std::istream& operator>>(std::iostream& is, Matrix& matrix);

            friend Matrix operator+(const Matrix& A, const Matrix& B);

            friend Matrix operator-(const Matrix& A, const Matrix& B);

            friend Matrix operator*(const Matrix& A, const Matrix& B);
    };
}
