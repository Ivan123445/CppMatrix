#include "tests.h"

TEST(Utils, SetRows) {
  S21Matrix m(1, 1);
  ASSERT_EQ(m.GetCols(), 1);
  ASSERT_EQ(m.GetRows(), 1);
  m.SetRows(2);
  ASSERT_EQ(m.GetCols(), 1);
  ASSERT_EQ(m.GetRows(), 2);
  ASSERT_EQ(m(1, 0), 0);
  m(1, 0) = 3;
  ASSERT_EQ(m(1, 0), 3);
}

TEST(Utils, SetCols) {
  S21Matrix m(1, 1);
  ASSERT_EQ(m.GetCols(), 1);
  ASSERT_EQ(m.GetRows(), 1);
  m.SetCols(2);
  ASSERT_EQ(m.GetCols(), 2);
  ASSERT_EQ(m.GetRows(), 1);
  ASSERT_EQ(m(0, 1), 0);
  m(0, 1) = 3;
  ASSERT_EQ(m(0, 1), 3);
}
