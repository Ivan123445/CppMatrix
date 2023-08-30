#include "tests.h"

TEST(Methods, Transpose) {
  S21Matrix matrix(2, 3);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3;
  matrix(1, 0) = 4;
  matrix(1, 1) = 5;
  matrix(1, 2) = 6;

  S21Matrix new_matrix = matrix.Transpose();

  ASSERT_EQ(new_matrix.GetRows(), 3);
  ASSERT_EQ(new_matrix.GetCols(), 2);
  ASSERT_EQ(new_matrix(0, 0), 1);
  ASSERT_EQ(new_matrix(1, 0), 2);
  ASSERT_EQ(new_matrix(2, 0), 3);
  ASSERT_EQ(new_matrix(0, 1), 4);
  ASSERT_EQ(new_matrix(1, 1), 5);
  ASSERT_EQ(new_matrix(2, 1), 6);
}

TEST(Methods, CalcComplements) {
  S21Matrix expected(3, 3), m(3, 3), result;

  m(0, 0) = 1;
  m(0, 1) = 2;
  m(0, 2) = 3;

  m(1, 0) = 0;
  m(1, 1) = 4;
  m(1, 2) = 2;

  m(2, 0) = 5;
  m(2, 1) = 2;
  m(2, 2) = 1;

  expected(0, 0) = 0;
  expected(0, 1) = 10;
  expected(0, 2) = -20;

  expected(1, 0) = 4;
  expected(1, 1) = -14;
  expected(1, 2) = 8;

  expected(2, 0) = -8;
  expected(2, 1) = -2;
  expected(2, 2) = 4;

  result = m.CalcComplements();

  ASSERT_TRUE(result == expected);
}

TEST(Methods, Determinant1) {
  const int size = 5;
  S21Matrix m(size, size);

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) m(i, j) = j;

  ASSERT_EQ(m.Determinant(), 0);
}

TEST(Methods, Determinant2) {
  const int size = 3;
  S21Matrix m(size, size);

  m(0, 0) = 2;
  m(0, 1) = 3;
  m(0, 2) = 1;
  m(1, 0) = 7;
  m(1, 1) = 4;
  m(1, 2) = 1;
  m(2, 0) = 9;
  m(2, 1) = -2;
  m(2, 2) = 1;

  ASSERT_EQ(m.Determinant(), -32);
}

TEST(Methods, InverseMatrix1) {
  S21Matrix A(4, 4), X(4, 4), Z;

  A(0, 0) = -1.0;
  A(0, 1) = 2.0;
  A(0, 2) = 7.0;
  A(0, 3) = 9.0;
  A(1, 0) = 1.0;
  A(1, 1) = 0.0;
  A(1, 2) = 0.0;
  A(1, 3) = 0.0;
  A(2, 0) = 47.0;
  A(2, 1) = 13.0;
  A(2, 2) = 17.0;
  A(2, 3) = 21.0;
  A(3, 0) = 22.0;
  A(3, 1) = 7.0;
  A(3, 2) = 1.0;
  A(3, 3) = 3.0;

  Z = A.InverseMatrix();

  X(0, 0) = 0.0;
  X(0, 1) = 1.0;
  X(0, 2) = 0.0;
  X(0, 3) = 0.0;
  X(1, 0) = -5.0 / 23.0;
  X(1, 1) = -121.0 / 23.0;
  X(1, 2) = 2.0 / 23.0;
  X(1, 3) = 1.0 / 23.0;
  X(2, 0) = -18.0 / 23.0;
  X(2, 1) = -379.0 / 46.0;
  X(2, 2) = 19.0 / 46.0;
  X(2, 3) = -25.0 / 46.0;
  X(3, 0) = 53.0 / 69.0;
  X(3, 1) = 1061.0 / 138.0;
  X(3, 2) = -47.0 / 138.0;
  X(3, 3) = 19.0 / 46.0;

  ASSERT_TRUE(X == Z);
}

TEST(Methods, InverseMatrix2) {
  S21Matrix A(3, 3), X(3, 3), Z;

  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(0, 2) = 3.0;
  A(1, 0) = 4.0;
  A(1, 1) = 5.0;
  A(1, 2) = 6.0;
  A(2, 0) = 8.0;
  A(2, 1) = 6.0;
  A(2, 2) = 9.0;

  Z = A.InverseMatrix();

  X(0, 0) = -3.0 / 5.0;
  X(0, 1) = 0.0;
  X(0, 2) = 1.0 / 5.0;

  X(1, 0) = -4.0 / 5.0;
  X(1, 1) = 1.0;
  X(1, 2) = -2.0 / 5.0;
  X(2, 0) = 16.0 / 15.0;
  X(2, 1) = -2.0 / 3.0;
  X(2, 2) = 1.0 / 5.0;

  ASSERT_TRUE(X == Z);
}
