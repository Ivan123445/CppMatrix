#include "tests.h"

TEST(Init, Init_Test) {
  S21Matrix matrix;

  ASSERT_EQ(matrix.GetRows(), 0);
  ASSERT_EQ(matrix.GetCols(), 0);
}

TEST(Init, Init_Test2) {
  S21Matrix matrix(1, 1);

  ASSERT_EQ(matrix.GetRows(), 1);
  ASSERT_EQ(matrix.GetCols(), 1);
  ASSERT_EQ(matrix(0, 0), 0);
}

TEST(Init, Init_Test3) {
  S21Matrix temp_matrix(1, 1);
  temp_matrix(0, 0) = 1;
  S21Matrix matrix = temp_matrix;
  ASSERT_EQ(matrix.GetRows(), 1);
  ASSERT_EQ(matrix.GetCols(), 1);
  ASSERT_EQ(matrix(0, 0), 1);
}

TEST(Init, Init_Test4) {
  S21Matrix temp_matrix(1, 1);
  temp_matrix(0, 0) = 1;
  S21Matrix matrix(std::move(temp_matrix));

  ASSERT_EQ(matrix.GetRows(), 1);
  ASSERT_EQ(matrix.GetCols(), 1);
  ASSERT_EQ(matrix(0, 0), 1);
}
