#ifndef CPP_MATRIX_S21_MATRIX_OOP_H
#define CPP_MATRIX_S21_MATRIX_OOP_H

#include <cfloat>
#include <cmath>
#include <stdexcept>

auto constexpr accuracy = 1e-6;

class S21Matrix {
 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;
  ~S21Matrix();

  [[nodiscard]] int GetRows() const { return rows_; }
  [[nodiscard]] int GetCols() const { return cols_; }
  void SetRows(int rows);
  void SetCols(int cols);

  [[nodiscard]] bool EqMatrix(const S21Matrix& other) const;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(double num);
  void MulMatrix(const S21Matrix& other);
  [[nodiscard]] S21Matrix Transpose() const noexcept;
  [[nodiscard]] S21Matrix CalcComplements() const;
  [[nodiscard]] double Determinant() const;
  [[nodiscard]] S21Matrix InverseMatrix() const;

  bool operator==(const S21Matrix& other) const;
  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix operator*(double num) const;
  S21Matrix operator+=(const S21Matrix& other);
  S21Matrix operator-=(const S21Matrix& other);
  S21Matrix operator*=(const S21Matrix& other);
  S21Matrix operator*=(double num);
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other) noexcept;
  double& operator()(int i, int j) const;

 private:
  int rows_ = 0, cols_ = 0;
  double* matrix_ = nullptr;

  void AllocMatrix();
  [[nodiscard]] S21Matrix cut_matrix(int row, int col) const;
};

#endif  // CPP_MATRIX_S21_MATRIX_OOP_H
