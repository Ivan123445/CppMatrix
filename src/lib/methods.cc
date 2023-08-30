#include "../../s21_matrix_oop.h"

S21Matrix S21Matrix::Transpose() const {
  S21Matrix res(cols_, rows_);

  for (int i = 0; i < cols_; ++i) {
    for (int j = 0; j < rows_; ++j) {
      res(i, j) = (*this)(j, i);
    }
  }
  return res;
}

S21Matrix S21Matrix::CalcComplements() const {
  S21Matrix res(rows_, cols_);

  for (int i = 0; i < res.rows_; ++i) {
    for (int j = 0; j < res.cols_; ++j) {
      S21Matrix small_matrix = cut_matrix(i, j);

      res(i, j) = small_matrix.Determinant() *
                  ((i + j) % 2 == 0 ? 1 : -1);  // det * sign
    }
  }

  return res;
}

double S21Matrix::Determinant() const {
  double temp_det = 0;
  if (rows_ == 1) {
    temp_det = (*this)(0, 0);
    return temp_det;
  }

  if (rows_ == 2) {
    temp_det = (*this)(0, 0) * (*this)(1, 1) - ((*this)(1, 0) * (*this)(0, 1));
    return temp_det;
  }

  int sign = 1;
  S21Matrix temp_matrix(rows_ - 1, cols_ - 1);
  for (int i = 0; i < rows_; ++i) {
    temp_matrix = cut_matrix(i, 0);
    temp_det += sign * (*this)(i, 0) * temp_matrix.Determinant();
    sign *= -1;
  }

  return temp_det;
}

S21Matrix S21Matrix::InverseMatrix() const {
  double det = Determinant();
  if (std::abs(det) < DBL_EPSILON) {
    throw std::invalid_argument("Inverse: Invalid parameter");
  }

  S21Matrix result = CalcComplements().Transpose() * (1.0 / det);
  return result;
}
