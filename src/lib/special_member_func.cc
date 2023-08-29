#include <algorithm>

#include "../../s21_matrix_oop.h"

S21Matrix::S21Matrix()
    :rows_(0), cols_(0), matrix_(nullptr) {}

S21Matrix::S21Matrix(int rows, int cols)
    :rows_(rows), cols_(cols), matrix_(nullptr) {
    AllocMatrix();
    std::fill(matrix_, matrix_ + rows_*cols_, 0);
}

S21Matrix::S21Matrix(const S21Matrix &other)
    :rows_(other.rows_), cols_(other.cols_), matrix_(nullptr) {
    AllocMatrix();
    std::copy(other.matrix_, other.matrix_ + rows_ * cols_, this->matrix_);
}

S21Matrix::S21Matrix(S21Matrix &&other) noexcept
    :rows_(other.rows_), cols_(other.cols_), matrix_(nullptr) {
    this->matrix_ = other.matrix_;
}

S21Matrix::~S21Matrix() {
    delete[] matrix_;
    rows_ = cols_ = 0;
    matrix_ = nullptr;
}
