#include "../../s21_matrix_oop.h"

void S21Matrix::AllocMatrix() {
  if (rows_ < 0 || cols_ < 0) {
    throw std::invalid_argument("Alloc: Invalid parameters");
  }
  try {
    matrix_ = new double[rows_ * cols_];
  } catch (std::bad_alloc& exception) {
    throw exception;
  }
}

void S21Matrix::SetRows(int rows) {
  if (rows != rows_) {
    S21Matrix res(rows, cols_);
    for (int i = 0; i < cols_; ++i) {
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
    for (int i = 0; i < std::min(cols, cols_); ++i) {
      for (int j = 0; j < rows_; ++j) {
        res.matrix_[i * cols_ + j] = matrix_[i * cols_ + j];
      }
    }
    *this = std::move(res);
  }
}

S21Matrix S21Matrix::cut_matrix(int row, int col) const {
  S21Matrix new_matrix(rows_ - 1, cols_ - 1);
  int miss_row = 0;
  for (int i = 0; i < rows_ - 1; ++i) {
    if (i == row) {
      miss_row = 1;
    }
    int miss_col = 0;
    for (int j = 0; j < rows_ - 1; ++j) {
      if (j == col) {
        miss_col = 1;
      }
      new_matrix(i, j) = (*this)(i + miss_row, j + miss_col);
    }
  }
  return new_matrix;
}
