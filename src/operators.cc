#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
        throw std::invalid_argument("Invalid parameters");
    }
    S21Matrix res(rows_, cols_);
    for (int i = 0; i < rows_ * cols_; ++i) {
        res.matrix_[i] = matrix_[i] + other.matrix_[i];
    }
    return res;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
        throw std::invalid_argument("Invalid parameters");
    }
    S21Matrix res(rows_, cols_);
    for (int i = 0; i < rows_ * cols_; ++i) {
        res.matrix_[i] = matrix_[i] + other.matrix_[i];
    }
    return res;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
    if (cols_ != other.rows_) {
        throw std::invalid_argument("Invalid parameters");
    }
    S21Matrix res(rows_, other.cols_);
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < other.cols_; ++j) {
            for (int k = 0; k < cols_; ++k) {
                res.matrix_[i*cols_ + j] = matrix_[i*cols_ + k] * other.matrix_[k*other.cols_ + j];
            }
        }
    }

    return res;
}

S21Matrix S21Matrix::operator*(const double num) const {
    S21Matrix res(rows_, cols_);
    for (int i = 0; i < rows_ * cols_; ++i) {
        res.matrix_[i] = matrix_[i]*num;
    }
    return res;
}

bool S21Matrix::operator==(const S21Matrix& other) const {
    if (&other == this) {
        return true;
    }
    if (rows_ != other.rows_ || cols_ != other.cols_) {
        return false;
    }

    for (int i = 0; i < rows_ * cols_; ++i) {
        if (matrix_[i] != other.matrix_[i]) {
            return false;
        }
    }

    return true;
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

S21Matrix& S21Matrix::operator=(const S21Matrix& other){
    if (&other == this) {
        return *this;
    }
    this->cols_ = other.cols_;
    this->rows_ = other.rows_;
    delete[] matrix_;
    AllocMatrix();
    std::copy(other.matrix_, other.matrix_ + rows_ * cols_, this->matrix_);

    return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other)  noexcept {
    delete[] matrix_;
    cols_ = other.cols_;
    rows_ = other.rows_;
    matrix_ = other.matrix_;

    other.cols_ = other.rows_ = 0;
    other.matrix_ = nullptr;

    return *this;
}

double& S21Matrix::operator()(int i, int j) const{
    if (i < 0 || j < 0 || i > rows_ || j > cols_) {
        throw std::invalid_argument("Invalid parameters");
    }
    return matrix_[i*cols_ + j];
}