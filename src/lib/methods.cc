#include "../../s21_matrix_oop.h"

S21Matrix S21Matrix::Transpose() const {
    S21Matrix res (cols_, rows_);

    for (int i = 0; i < cols_; ++i) {
        for (int j = 0; j < rows_; ++j) {
            res(i, j) = (*this)(j, i);
        }
    }
    return res;
}

S21Matrix S21Matrix::CalcComplements() const {
    if (rows_ != cols_) {
        throw std::invalid_argument("Invalid parameters");
    }

    S21Matrix res(rows_, cols_);
    for (int i = 0; i < res.rows_; ++i) {
        for (int j = 0; j < res.cols_; ++j) {
            S21Matrix additional_matrix(rows_-1, cols_-1);
            cut_matrix(*this, additional_matrix, j, i);

            int sign = (i + j) % 2 ? -1 : 1;
            res(i, j) = sign * additional_matrix.Determinant();
        }
    }
    return res;
}

double S21Matrix::Determinant() const{
    if (rows_ != cols_) {
        throw std::invalid_argument("Invalid parameters");
    }
    if (rows_ == 1) {
        return matrix_[0];
    }
    if (rows_ == 2) {
        return (*this)(0, 0) * (*this)(1, 1) -
                (*this)(1, 0) * (*this)(0, 1);
    }
    S21Matrix temp_matrix(rows_-1, cols_-1);

    int sign = 1;
    double temp_det = 0;
    for (int i = 0; i < rows_; ++i) {
        cut_matrix(*this, temp_matrix, i, 0);

        temp_det += sign * temp_matrix(i, 0) * temp_matrix.Determinant();
        sign *= -1;
    }
    return temp_det;
}

S21Matrix S21Matrix::InverseMatrix() const{
    if (rows_ != cols_) {
        throw std::invalid_argument("Invalid parameters");
    }
    S21Matrix res;
    double det = this->Determinant();
    if (fabs(det) < DBL_EPSILON) {  // is there inv matrix?
        throw std::invalid_argument("Invalid parameters");
    }

    if (this->cols_ == 1) {
        res.SetCols(1);
        res.SetRows(1);
        res(0, 0) = 1 / (*this)(0, 0);

    } else {
        S21Matrix complements_matrix = this->CalcComplements();

        res = complements_matrix * (1/det);
    }

    return res;
}