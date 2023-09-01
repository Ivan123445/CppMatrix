#include "../../s21_matrix_oop.h"

S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

S21Matrix::S21Matrix(int rows, int cols) : matrix_(nullptr) {
  if (rows < 0 || cols < 0) {
    throw std::out_of_range("S21Matrix: Parameters out of range");
  }
  rows_ = rows;
  cols_ = cols;
  AllocMatrix();
  std::fill(matrix_, matrix_ + rows_ * cols_, 0);
}

S21Matrix::S21Matrix(const S21Matrix &other) { *this = other; }

S21Matrix::S21Matrix(S21Matrix &&other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(nullptr) {
  other.rows_ = 0;
  other.cols_ = 0;
  this->matrix_ = other.matrix_;
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() {
  delete[] matrix_;
  rows_ = cols_ = 0;
  matrix_ = nullptr;
}
