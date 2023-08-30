#include "tests.h"

TEST(Operators, Equal_op1) {
  S21Matrix a(2, 3), b(2, 3);
  ASSERT_TRUE(a == b);
}

TEST(Operators, Equal_op2) {
  S21Matrix a(2, 2), b(2, 2);
  a(0, 0) = b(0, 0) = 1;
  a(0, 1) = b(0, 1) = 2;
  a(1, 0) = b(1, 0) = 3;
  a(0, 1) = b(0, 1) = 4;

  ASSERT_TRUE(a == b);
}

TEST(Operators, Equal_op3) {
  S21Matrix a(2, 2), b(2, 2);
  a(0, 0) = 1;
  b(0, 0) = 2;
  a(0, 1) = b(0, 1) = 2;
  a(1, 0) = b(1, 0) = 3;
  a(0, 1) = b(0, 1) = 4;

  ASSERT_FALSE(a == b);
}

TEST(Operators, Plus_op1) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  S21Matrix m(rows, cols), mtx(rows, cols), check(rows, cols);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m(i, j) = rand();
      mtx(i, j) = rand();
      check(i, j) = m(i, j) + mtx(i, j);
    }
  }

  ASSERT_TRUE((m + mtx) == check);
}

TEST(Operators, Minus_op1) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  S21Matrix m(rows, cols), mtx(rows, cols), check(rows, cols);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m(i, j) = rand();
      mtx(i, j) = rand();
      check(i, j) = m(i, j) - mtx(i, j);
    }
  }

  ASSERT_TRUE((m - mtx) == check);
}

TEST(Operators, Num_mul_op1) {
  int rows = rand() % 10 + 1;
  int cols = rand() % 10 + 1;
  S21Matrix m(rows, cols), check(rows, cols);

  double mult_number = rand();
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m(i, j) = rand();
      check(i, j) = m(i, j) * mult_number;
    }
  }
  ASSERT_TRUE(m * mult_number == check);
}

TEST(Operators, Matrix_mul_op1) {
  int rows = rand() % 10 + 1;
  int cols = rand() % 10 + 1;
  S21Matrix m(rows, cols), mtx(cols, rows), check(rows, rows);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) m(i, j) = rand() % 1000;

  for (int i = 0; i < cols; i++)
    for (int j = 0; j < rows; j++) mtx(i, j) = rand() % 1000;

  for (int i = 0; i < m.GetRows(); i++) {
    for (int j = 0; j < mtx.GetCols(); j++) {
      for (int k = 0; k < m.GetCols(); k++) check(i, j) = m(i, k) * mtx(k, j);
    }
  }
  ASSERT_TRUE((m * mtx) == check);
}

TEST(Operators, Short_plus_op1) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  S21Matrix m(rows, cols), mtx(rows, cols), check(rows, cols);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m(i, j) = rand();
      mtx(i, j) = rand();
      check(i, j) = m(i, j) + mtx(i, j);
    }
  }
  m += mtx;
  ASSERT_TRUE(m == check);
}

TEST(Operators, Short_minus_op1) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  S21Matrix m(rows, cols), mtx(rows, cols), check(rows, cols);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m(i, j) = rand();
      mtx(i, j) = rand();
      check(i, j) = m(i, j) - mtx(i, j);
    }
  }
  m -= mtx;
  ASSERT_TRUE(m == check);
}

TEST(Operators, Short_num_mul_op1) {
  int rows = rand() % 10 + 1;
  int cols = rand() % 10 + 1;
  S21Matrix m(rows, cols), check(rows, cols);

  double mult_number = rand();
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m(i, j) = rand();
      check(i, j) = m(i, j) * mult_number;
    }
  }
  m *= mult_number;
  ASSERT_TRUE(m == check);
}

TEST(Operators, Short_matrix_mul_op1) {
  int rows = rand() % 10 + 1;
  int cols = rand() % 10 + 1;
  S21Matrix m(rows, cols), mtx(cols, rows), check(rows, rows);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) m(i, j) = rand() % 1000;

  for (int i = 0; i < cols; i++)
    for (int j = 0; j < rows; j++) mtx(i, j) = rand() % 1000;

  for (int i = 0; i < m.GetRows(); i++) {
    for (int j = 0; j < mtx.GetCols(); j++) {
      for (int k = 0; k < m.GetCols(); k++) check(i, j) = m(i, k) * mtx(k, j);
    }
  }
  m *= mtx;
  ASSERT_TRUE(m == check);
}

TEST(Operators, Assigment_op) {
  int rows = rand() % 10 + 1;
  int cols = rand() % 10 + 1;
  S21Matrix m(rows, cols), result;

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) m(i, j) = rand() % 1000;

  result = m;

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) ASSERT_TRUE(result(i, j) == m(i, j));
}

TEST(Operators, Move_assigment_op) {
  int rows = rand() % 10 + 1;
  int cols = rand() % 10 + 1;
  S21Matrix m(rows, cols), result, check;

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) m(i, j) = rand() % 1000;
  check = m;

  result = std::move(m);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) ASSERT_TRUE(result(i, j) == check(i, j));
}

TEST(Operators, Brakets_op) {
  S21Matrix matrix(2, 2);
  matrix(1, 1) = 1;
  matrix(0, 0) = 0;
  ASSERT_TRUE(matrix(1, 1) == 1);
  ASSERT_TRUE(matrix(0, 0) == 0);
}
