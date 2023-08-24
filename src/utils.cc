#include "../s21_matrix_oop.h"

void S21Matrix::AllocMatrix() {
    if (rows_ < 0 || cols_ < 0) {
        throw std::invalid_argument("Invalid parameters");
    }
    try {
        matrix_ = new double [rows_*cols_];
    } catch (std::bad_alloc &exception) {
        throw exception;
    }
}

void S21Matrix::SetRows(int rows) {
    if (rows != rows_) {
        S21Matrix res(rows, cols_);
        for(int i = 0; i < cols_; ++i) {
            for (int j = 0; j < std::min(rows, rows_); ++j) {
                res.matrix_[i * cols_ + j] = matrix_[i * cols_ + j];
            }
        }
        *this = std::move(res);
    }
}

void S21Matrix::SetCols(int cols) {
    if (cols != cols_) {
        S21Matrix res(rows_, cols);
        for(int i = 0; i < std::min(cols, cols_); ++i) {
            for (int j = 0; j < rows_; ++j) {
                res.matrix_[i * cols_ + j] = matrix_[i * cols_ + j];
            }
        }
        *this = std::move(res);
    }
}
