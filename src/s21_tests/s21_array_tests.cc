#include <gtest/gtest.h>

#include <vector>

#include "../s21_containersplus.h"

namespace array_tests {
TEST(Array, Constructors_move) {
  s21::array<int, 5> test;
  std::array<int, 5> t;
  test[1] = 5;
  t[1] = 5;
  s21::array<int, 5> test2(std::move(test));
  std::array<int, 5> t2(std::move(t));
  EXPECT_EQ(test2[1], t2[1]);
}

TEST(Array, Constructors_copy) {
  s21::array<int, 5> test;
  test[3] = 5;
  s21::array<int, 5> test2(test);
  std::array<int, 5> t;
  t[3] = 5;
  std::array<int, 5> t2(t);
  EXPECT_EQ(test2.at(3), t2.at(3));
}

TEST(Array, at) {
  s21::array<int, 5> test;
  test[1] = 5;
  std::array<int, 5> t;
  t[1] = 5;
  EXPECT_EQ(test.at(1), t.at(1));
}

TEST(Array, front_back) {
  s21::array<int, 5> test = {1, 2, 3, 4, 5};
  std::array<int, 5> t = {1, 2, 3, 4, 5};
  EXPECT_EQ(test.front(), t.front());
  EXPECT_EQ(test.back(), t.back());
}

TEST(Array, data) {
  s21::array<int, 5> test;
  int* test_data = test.data();
  *test_data = 3;
  std::array<int, 5> t;
  int* td = t.data();
  *td = 3;
  EXPECT_EQ(test.front(), t.front());
}

TEST(Array, empty) {
  s21::array<int, 5> test1;
  s21::array<int, 0> test2;
  std::array<int, 5> t1;
  std::array<int, 0> t2;
  EXPECT_EQ(test2.empty(), t2.empty());
  EXPECT_EQ(test1.empty(), t1.empty());
}

TEST(Array, max_size) {
  s21::array<int, 7> test1;
  test1[0] = 1;
  test1[2] = 1;
  test1[3] = 1;
  test1[4] = 1;
  test1[1] = 1;
  EXPECT_EQ(test1.max_size(), 7);
}

TEST(Array, swap) {
  s21::array<int, 5> test1 = {2, 2, 2, 2, 2};
  s21::array<int, 5> test2 = {3, 3, 3, 3, 3};
  test1.swap(test2);
  std::array<int, 5> t1 = {2, 2, 2, 2, 2};
  std::array<int, 5> t2 = {3, 3, 3, 3, 3};
  t1.swap(t2);
  EXPECT_EQ(test1[1], t1[1]);
  EXPECT_EQ(test2[1], t2[1]);
}

TEST(Array, fill) {
  s21::array<int, 5> test1 = {2, 2, 2, 2, 2};
  test1.fill(4);
  std::array<int, 5> t = {2, 2, 2, 2, 2};
  t.fill(4);
  EXPECT_EQ(test1[1], t[1]);
}
}  // namespace array_tests