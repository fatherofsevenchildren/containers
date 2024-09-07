#include <gtest/gtest.h>

#include <vector>

#include "../s21_containers.h"

namespace vector_tests {
TEST(Vectors, Constructors) {
  s21::vector<int> test;
  std::vector<int> t;
  EXPECT_EQ(test.size(), t.size());
}

TEST(Vectors, Constructors_size) {
  s21::vector<int> test(2);
  std::vector<int> t(2);
  EXPECT_EQ(test[1], t[1]);
  EXPECT_EQ(test[0], t[0]);
}

TEST(Vectors, Constructors_move) {
  s21::vector<int> test(2);
  test[1] = 5;
  s21::vector<int> test2(std::move(test));
  std::vector<int> t(2);
  t[1] = 5;
  std::vector<int> t2(std::move(t));
  EXPECT_EQ(test.size(), t.size());
  EXPECT_EQ(test.capacity(), t.capacity());
  EXPECT_EQ(test2[1], t2[1]);
}

TEST(Vectors, Constructors_copy) {
  s21::vector<int> test(7);
  test[3] = 5;
  test.push_back(3);
  std::vector<int> t(7);
  t[3] = 5;
  t.push_back(3);
  EXPECT_EQ(test[3], t[3]);
  test.pop_back();
  t.pop_back();
  s21::vector<int> test2(test);
  std::vector<int> t2(t);
  EXPECT_EQ(test2.size(), t2.size());
  EXPECT_EQ(test2.capacity(), t2.capacity());
}

TEST(Vectors, at) {
  s21::vector<int> test(2);
  test[1] = 5;
  std::vector<int> t(2);
  t[1] = 5;
  EXPECT_EQ(test.at(1), t.at(1));
}

TEST(Vectors, front_back) {
  s21::vector<int> test = {1, 2};
  std::vector<int> t = {1, 2};
  EXPECT_EQ(test.front(), t.front());
  EXPECT_EQ(test.back(), t.back());
}

TEST(Vectors, data) {
  s21::vector<int> test = {1, 2};
  int* test_data = test.data();
  *test_data = 3;
  std::vector<int> t = {1, 2};
  int* td = t.data();
  *td = 3;
  EXPECT_EQ(test.front(), t.front());
}

TEST(Vectors, empty) {
  s21::vector<int> test1 = {1, 2};
  s21::vector<int> test2;
  std::vector<int> t1 = {1, 2};
  std::vector<int> t2;
  EXPECT_EQ(test2.empty(), t2.empty());
  EXPECT_EQ(test1.empty(), t1.empty());
}

TEST(Vectors, reserve) {
  s21::vector<int> test = {1, 2, 3};
  test.reserve(10);
  std::vector<int> t = {1, 2, 3};
  t.reserve(10);
  EXPECT_EQ(test.capacity(), t.capacity());
  EXPECT_EQ(test[2], t[2]);
}

TEST(Vectors, shrink) {
  s21::vector<int> test1 = {1, 2, 3};
  test1.reserve(10);
  test1.shrink_to_fit();
  EXPECT_EQ(test1.capacity(), test1.size());
}

//--------iter----------------

TEST(Vectors, iter1) {
  s21::vector<int> test1 = {1, 2, 3};
  s21::vector<int>::iterator it1 = test1.begin();
  std::vector<int> t1 = {1, 2, 3};
  std::vector<int>::iterator i1 = t1.begin();
  EXPECT_EQ(*it1, *i1);
}

TEST(Vectors, iter_plus) {
  s21::vector<int> test1 = {1, 2, 3};
  s21::vector<int>::iterator it1 = test1.begin();
  std::vector<int> t1 = {1, 2, 3};
  std::vector<int>::iterator i1 = t1.begin();
  EXPECT_EQ(*++it1, *++i1);
}

TEST(Vectors, iter_plus_plus) {
  s21::vector<int> test1 = {1, 2, 3};
  s21::vector<int>::iterator it1 = test1.begin();
  std::vector<int> t1 = {1, 2, 3};
  std::vector<int>::iterator i1 = t1.begin();
  EXPECT_EQ(*++ ++it1, *++ ++i1);
}

TEST(Vectors, iter_minus) {
  s21::vector<int> test1 = {1, 2, 3};
  s21::vector<int>::iterator it1 = test1.end();
  std::vector<int> t1 = {1, 2, 3};
  std::vector<int>::iterator i1 = t1.end();
  EXPECT_EQ(*--it1, *--i1);
}

TEST(Vectors, iter_postfix) {
  s21::vector<int> test1 = {1, 2, 3};
  s21::vector<int>::iterator it1 = test1.begin();
  std::vector<int> t1 = {1, 2, 3};
  std::vector<int>::iterator i1 = t1.begin();
  EXPECT_EQ(*it1++, *i1++);
  EXPECT_EQ(*it1, *i1);
}

TEST(Vectors, iter_postfix_minus) {
  s21::vector<int> test1 = {1, 2, 3};
  s21::vector<int>::iterator it1 = test1.end();
  std::vector<int> t1 = {1, 2, 3};
  std::vector<int>::iterator i1 = t1.end();
  EXPECT_EQ(*--it1, *--i1);
  EXPECT_EQ(*--it1, *--i1);
}

// //--------const iter----------------

TEST(Vectors, const_iter1) {
  s21::vector<int> test1 = {1, 2, 3};
  s21::vector<int>::const_iterator it1 = test1.cbegin();
  std::vector<int> t1 = {1, 2, 3};
  std::vector<int>::const_iterator i1 = t1.cbegin();
  EXPECT_EQ(*it1, *i1);
}

TEST(Vectors, const_iter_plus) {
  s21::vector<int> test1 = {1, 2, 3};
  s21::vector<int>::const_iterator it1 = test1.cbegin();
  std::vector<int> t1 = {1, 2, 3};
  std::vector<int>::const_iterator i1 = t1.cbegin();
  EXPECT_EQ(*++it1, *++i1);
}

TEST(Vectors, const_iter_plus_plus) {
  s21::vector<int> test1 = {1, 2, 3};
  s21::vector<int>::const_iterator it1 = test1.cbegin();
  std::vector<int> t1 = {1, 2, 3};
  std::vector<int>::const_iterator i1 = t1.cbegin();
  EXPECT_EQ(*++ ++it1, *++ ++i1);
}

TEST(Vectors, const_iter_minus) {
  s21::vector<int> test1 = {1, 2, 3};
  s21::vector<int>::const_iterator it1 = test1.cend();
  std::vector<int> t1 = {1, 2, 3};
  std::vector<int>::const_iterator i1 = t1.cend();
  EXPECT_EQ(*--it1, *--i1);
}

TEST(Vectors, const_iter_postfix) {
  s21::vector<int> test1 = {1, 2, 3};
  s21::vector<int>::const_iterator it1 = test1.cbegin();
  std::vector<int> t1 = {1, 2, 3};
  std::vector<int>::const_iterator i1 = t1.cbegin();
  EXPECT_EQ(*it1++, *i1++);
  EXPECT_EQ(*it1, *i1);
}

TEST(Vectors, const_iter_postfix_minus) {
  s21::vector<int> test1 = {1, 2, 3};
  s21::vector<int>::const_iterator it1 = test1.cend();
  std::vector<int> t1 = {1, 2, 3};
  std::vector<int>::const_iterator i1 = t1.cend();
  EXPECT_EQ(*--it1, *--i1);
  EXPECT_EQ(*--it1, *--i1);
}

TEST(Vectors, clear) {
  s21::vector<int> test1 = {1, 2, 3};
  test1.clear();
  std::vector<int> t1 = {1, 2, 3};
  t1.clear();
  EXPECT_EQ(test1.capacity(), t1.capacity());
  EXPECT_EQ(test1.size(), t1.size());
}

TEST(Vectors, insert) {
  s21::vector<int> test1 = {1, 2, 3, 4, 5};
  s21::vector<int>::iterator it = test1.begin();
  it++;
  it = test1.insert(it, 5);
  std::vector<int> t1 = {1, 2, 3, 4, 5};
  std::vector<int>::iterator i = t1.begin();
  i++;
  i = t1.insert(i, 5);
  EXPECT_EQ(test1.capacity(), t1.capacity());
  EXPECT_EQ(test1.size(), t1.size());
  EXPECT_EQ(test1[1], t1[1]);
  EXPECT_EQ(*it, *i);
}

TEST(Vectors, erase) {
  s21::vector<int> test1 = {1, 2, 3, 4, 5};
  s21::vector<int>::iterator it = test1.begin();
  it++;
  test1.erase(it);
  std::vector<int> t1 = {1, 2, 3, 4, 5};
  std::vector<int>::iterator i = t1.begin();
  i++;
  t1.erase(i);
  EXPECT_EQ(test1.capacity(), t1.capacity());
  EXPECT_EQ(test1.size(), t1.size());
  EXPECT_EQ(test1[1], t1[1]);
  EXPECT_EQ(test1[0], t1[0]);
  EXPECT_EQ(*it, *i);
}

TEST(Vectors, push_back) {
  s21::vector<int> test1 = {1, 2, 3, 4, 5};
  test1.push_back(6);
  std::vector<int> t1 = {1, 2, 3, 4, 5};
  t1.push_back(6);
  EXPECT_EQ(test1.capacity(), t1.capacity());
  EXPECT_EQ(test1.size(), t1.size());
  EXPECT_EQ(test1[5], t1[5]);
}

TEST(Vectors, insert_many_back) {
  s21::vector<int> test1 = {1, 2};
  test1.insert_many_back(3, 3, 3);
  EXPECT_EQ(test1.capacity(), 8);
  EXPECT_EQ(test1.size(), 5);
  EXPECT_EQ(test1[0], 1);
  EXPECT_EQ(test1[1], 2);
  EXPECT_EQ(test1[2], 3);
  EXPECT_EQ(test1[3], 3);
  EXPECT_EQ(test1[4], 3);
}
}  // namespace vector_tests