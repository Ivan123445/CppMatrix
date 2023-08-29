#ifndef CPP_MATRIX_S21_MATRIX_OOP_H
#define CPP_MATRIX_S21_MATRIX_OOP_H

#include <stdexcept>
#include <cmath>
#include <cfloat>

#define ACCURACY 1e-6

class S21Matrix {
private:
    int rows_, cols_;
    double *matrix_;

public:
    S21Matrix();
    S21Matrix(int rows, int cols);
    S21Matrix(const S21Matrix& other);
    S21Matrix(S21Matrix&& other) noexcept ;
    ~S21Matrix();

    [[nodiscard]] int GetRows() const {return rows_;}
    [[nodiscard]] int GetCols() const {return cols_;}
    void SetRows(int rows);
    void SetCols(int cols);

    [[nodiscard]] bool EqMatrix(const S21Matrix& other) const { return *this == other;}
    void SumMatrix(const S21Matrix& other) {*this += other;}
    void SubMatrix(const S21Matrix& other) {*this -= other;}
    void MulNumber(double num) {*this *= num;}
    void MulMatrix(const S21Matrix& other) {*this *= other;}
    [[nodiscard]] S21Matrix Transpose() const;
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
    S21Matrix& operator=(S21Matrix&& other) noexcept ;
    double& operator()(int i, int j) const;
private:
    void AllocMatrix();
    static void cut_matrix(const S21Matrix& matrix, S21Matrix& new_matrix, int row, int col);
};

#endif //CPP_MATRIX_S21_MATRIX_OOP_H
