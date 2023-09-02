#include "../../s21_matrix_oop.h"

bool S21Matrix::operator==(const S21Matrix& other) const {
  if (&other == this) {
    return true;
  }
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    return false;
  }

  for (int i = 0; i < rows_ * cols_; ++i) {
    if (std::fabs(matrix_[i] - other.matrix_[i]) > accuracy) {
      return false;
    }
  }

  return true;
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Plus: Invalid arguments");
  }
  S21Matrix res(rows_, cols_);
  for (int i = 0; i < rows_ * cols_; ++i) {
    res.matrix_[i] = matrix_[i] + other.matrix_[i];
  }
  return res;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Minus: Invalid arguments");
  }
  S21Matrix res(rows_, cols_);
  for (int i = 0; i < rows_ * cols_; ++i) {
    res.matrix_[i] = matrix_[i] - other.matrix_[i];
  }
  return res;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  if (cols_ != other.rows_) {
    throw std::invalid_argument("Mul: Invalid arguments");
  }
  S21Matrix res(rows_, other.cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < other.cols_; ++j) {
      for (int k = 0; k < cols_; ++k) {
        res(i, j) = (*this)(i, k) * other(k, j);
      }
    }
  }

  return res;
}

S21Matrix S21Matrix::operator*(const double num) const {
  S21Matrix res(rows_, cols_);
  for (int i = 0; i < rows_ * cols_; ++i) {
    res.matrix_[i] = matrix_[i] * num;
  }
  return res;
}

S21Matrix S21Matrix::operator+=(const S21Matrix& other) {
  *this = *this + other;
  return *this;
}

S21Matrix S21Matrix::operator-=(const S21Matrix& other) {
  *this = *this - other;
  return *this;
}

S21Matrix S21Matrix::operator*=(const S21Matrix& other) {
  *this = *this * other;
  return *this;
}

S21Matrix S21Matrix::operator*=(const double num) {
  *this = *this * num;
  return *this;
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (&other == this) {
    return *this;
  }
  cols_ = other.cols_;
  rows_ = other.rows_;
  delete[] matrix_;
  AllocMatrix();
  std::copy(other.matrix_, other.matrix_ + rows_ * cols_, matrix_);

  return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) noexcept {
  if (&other == this) {
    return *this;
  }
  delete[] matrix_;
  cols_ = other.cols_;
  rows_ = other.rows_;
  matrix_ = other.matrix_;

  other.cols_ = other.rows_ = 0;
  other.matrix_ = nullptr;

  return *this;
}

double& S21Matrix::operator()(int i, int j) const {
  if (i < 0 || j < 0 || i > rows_ || j > cols_) {
    throw std::out_of_range("Brackets: Parameters out of range");
  }
  return matrix_[i * cols_ + j];
}