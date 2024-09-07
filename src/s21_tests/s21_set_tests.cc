#include <gtest/gtest.h>

#include <set>

#include "../s21_containers.h"

namespace set_tests {

bool setsEqual(s21::set<int> S1, std::set<int> S2) {
  if (S1.size() != S2.size()) return false;
  auto it_S1 = S1.begin();
  auto it_S2 = S2.begin();
  for (; it_S2 != S2.end(); ++it_S1, ++it_S2) {
    if (*it_S1 != *it_S2) return false;
  }
  return true;
}

TEST(CONSTRUCTORS, SET_DEFAULT_CONSTRUCTOR) {
  s21::set<int> S1;
  std::set<int> S2;
  ASSERT_EQ(setsEqual(S1, S2), true);
}

TEST(CONSTRUCTORS, SET_LIST_CONSTRUCTOR) {
  s21::set<int> S1 = {1, 2, 3};
  std::set<int> S2 = {1, 2, 3};
  ASSERT_EQ(setsEqual(S1, S2), true);
}

TEST(CONSTRUCTORS, SET_COPY_CONSTRUCTOR) {
  s21::set<int> S1 = {1, 2, 3};
  s21::set<int> S2(S1);
  std::set<int> S3 = {1, 2, 3};
  std::set<int> S4(S3);
  ASSERT_EQ(setsEqual(S2, S4), true);
  ASSERT_EQ(setsEqual(S1, S3), true);
}

TEST(CONSTRUCTORS, SET_MOVE_CONSTRUCTOR) {
  s21::set<int> S1 = {1, 2, 3};
  s21::set<int> S2(std::move(S1));
  std::set<int> S3 = {1, 2, 3};
  std::set<int> S4(std::move(S3));
  ASSERT_EQ(setsEqual(S2, S4), true);
  ASSERT_EQ(setsEqual(S1, S3), true);
}

TEST(SET, UNIQUE_TEST) {
  s21::set<int> S1 = {1, 1, 1};
  std::set<int> S2 = {1, 1, 1};
  ASSERT_EQ(setsEqual(S1, S2), true);
  S1.insert(1);
  S2.insert(1);
  ASSERT_EQ(setsEqual(S1, S2), true);
}

TEST(METHOD_SIZE, SET_SIZE_DEFAULT_CONSTRUCTOR) {
  s21::set<int> S1;
  std::set<int> S2;
  ASSERT_EQ(S1.size(), S2.size());
}

TEST(METHOD_SIZE, SET_SIZE_LIST_CONSTRUCTOR) {
  s21::set<int> S1 = {1, 2, 3};
  std::set<int> S2 = {1, 2, 3};
  ASSERT_EQ(S1.size(), S2.size());
}

TEST(METHOD_SIZE, SET_SIZE_COPY_CONSTRUCTOR) {
  s21::set<int> S1 = {1, 2, 3};
  s21::set<int> S2(S1);
  std::set<int> S3 = {1, 2, 3};
  std::set<int> S4(S3);
  ASSERT_EQ(S1.size(), S3.size());
  ASSERT_EQ(S2.size(), S4.size());
}

TEST(METHOD_SIZE, SET_SIZE_MOVE_CONSTRUCTOR) {
  s21::set<int> S1 = {1, 2, 3};
  s21::set<int> S2(std::move(S1));
  std::set<int> S3 = {1, 2, 3};
  std::set<int> S4(std::move(S3));
  ASSERT_EQ(S1.size(), S3.size());
  ASSERT_EQ(S2.size(), S4.size());
}

TEST(METHOD_MAX_SIZE, SET_MAX_SIZE) {
  s21::set<int> S1 = {1, 2, 3};
  std::set<int> S2 = {1, 2, 3};
  EXPECT_NEAR(S1.max_size() / S2.max_size(), 1, 1);
}

TEST(METHOD_EMPTY, SET_EMPTY_DEFAULT_CONSTRUCTOR) {
  s21::set<int> S1;
  std::set<int> S2;
  ASSERT_EQ(S1.empty(), S2.empty());
}

TEST(METHOD_EMPTY, SET_EMPTY_LIST_CONSTRUCTOR) {
  s21::set<int> S1 = {1, 2, 3};
  std::set<int> S2 = {1, 2, 3};
  ASSERT_EQ(S1.empty(), S2.empty());
  s21::set<int> S3 = {};
  std::set<int> S4 = {};
  ASSERT_EQ(S3.empty(), S4.empty());
  s21::set<int> S5 = {1};
  std::set<int> S6 = {1};
  ASSERT_EQ(S5.empty(), S6.empty());
}

TEST(METHOD_EMPTY, SET_EMPTY_COPY_CONSTRUCTOR) {
  s21::set<int> S1 = {1, 2, 3};
  s21::set<int> S2(S1);
  std::set<int> S3 = {1, 2, 3};
  std::set<int> S4(S3);
  ASSERT_EQ(S1.empty(), S3.empty());
  ASSERT_EQ(S2.empty(), S4.empty());
  s21::set<int> S5;
  s21::set<int> S6(S5);
  std::set<int> S7;
  std::set<int> S8(S7);
  ASSERT_EQ(S5.empty(), S7.empty());
  ASSERT_EQ(S6.empty(), S8.empty());
}

TEST(METHOD_EMPTY, SET_EMPTY_MOVE_CONSTRUCTOR) {
  s21::set<int> S1 = {1, 2, 3};
  s21::set<int> S2(std::move(S1));
  std::set<int> S3 = {1, 2, 3};
  std::set<int> S4(std::move(S3));
  ASSERT_EQ(S1.empty(), S3.empty());
  ASSERT_EQ(S2.empty(), S4.empty());
  s21::set<int> S5;
  s21::set<int> S6(std::move(S5));
  std::set<int> S7;
  std::set<int> S8(std::move(S7));
  ASSERT_EQ(S5.empty(), S7.empty());
  ASSERT_EQ(S6.empty(), S8.empty());
}

TEST(METHOD_SWAP, SET_SWAP_ONE_LIST_EMPTY1) {
  s21::set<int> S1 = {1, 2, 3};
  s21::set<int> S2 = {};
  std::set<int> S3 = {1, 2, 3};
  std::set<int> S4 = {};
  S1.swap(S2);
  S3.swap(S4);
  ASSERT_EQ(setsEqual(S1, S3), true);
  ASSERT_EQ(setsEqual(S2, S4), true);
}

TEST(METHOD_SWAP, SET_SWAP_ONE_LIST_EMPTY2) {
  s21::set<int> S1 = {};
  s21::set<int> S2 = {1, 2, 3};
  std::set<int> S3 = {};
  std::set<int> S4 = {1, 2, 3};
  S1.swap(S2);
  S3.swap(S4);
  ASSERT_EQ(setsEqual(S1, S3), true);
  ASSERT_EQ(setsEqual(S2, S4), true);
}

TEST(METHOD_SWAP, SET_SWAP_NUMBER_OF_ELEMENTS) {
  s21::set<int> S1 = {1, 2, 3};
  s21::set<int> S2 = {4, 5, 6};
  std::set<int> S3 = {1, 2, 3};
  std::set<int> S4 = {4, 5, 6};
  S1.swap(S2);
  S3.swap(S4);
  ASSERT_EQ(setsEqual(S1, S3), true);
  ASSERT_EQ(setsEqual(S2, S4), true);
}

TEST(METHOD_SWAP, SET_SWAP_DIFFERENT_NUMBER_OF_ELEMENTS1) {
  s21::set<int> S1 = {1, 2, 3, 4, 5};
  s21::set<int> S2 = {4, 5, 6};
  std::set<int> S3 = {1, 2, 3, 4, 5};
  std::set<int> S4 = {4, 5, 6};
  S1.swap(S2);
  S3.swap(S4);
  ASSERT_EQ(setsEqual(S1, S3), true);
  ASSERT_EQ(setsEqual(S2, S4), true);
}

TEST(METHOD_SWAP, SET_SWAP_DIFFERENT_NUMBER_OF_ELEMENTS2) {
  s21::set<int> S1 = {1, 2, 3};
  s21::set<int> S2 = {4, 5, 6, 128, 40};
  std::set<int> S3 = {1, 2, 3};
  std::set<int> S4 = {4, 5, 6, 128, 40};
  S1.swap(S2);
  S3.swap(S4);
  ASSERT_EQ(setsEqual(S1, S3), true);
  ASSERT_EQ(setsEqual(S2, S4), true);
}

TEST(METHOD_CLEAR, SET_CLEAR) {
  s21::set<int> S1 = {1, 2, 3};
  std::set<int> S2 = {1, 2, 3};
  S1.clear();
  S2.clear();
  ASSERT_EQ(setsEqual(S1, S2), true);
}

TEST(METHOD_INSERT, SET_INSERT_EXISTING_ELEMENT) {
  s21::set<int> S1 = {1, 2, 3};
  std::set<int> S2 = {1, 2, 3};
  S1.insert(3);
  S2.insert(3);
  ASSERT_EQ(setsEqual(S1, S2), true);
}

TEST(METHOD_INSERT, SET_INSERT_0_ELEMENTS) {
  s21::set<int> S1 = {};
  std::set<int> S2 = {};
  S1.insert(3);
  S2.insert(3);
  ASSERT_EQ(setsEqual(S1, S2), true);
}

TEST(METHOD_INSERT, SET_INSERT_MIDDLE_ELEMENT) {
  s21::set<int> S1 = {1, 2, 4};
  std::set<int> S2 = {1, 2, 4};
  S1.insert(3);
  S2.insert(3);
  ASSERT_EQ(setsEqual(S1, S2), true);
}

TEST(METHOD_ERASE, SET_ERASE_ONE_CHILD1) {
  s21::set<int> S1 = {1, 2, 3};
  std::set<int> S2 = {1, 2, 3};
  auto it_S1 = S1.begin();
  auto it_S2 = S2.begin();
  S1.erase(it_S1);
  S2.erase(it_S2);
  ASSERT_EQ(setsEqual(S1, S2), true);
}

TEST(METHOD_ERASE, SET_ERASE_ONE_CHILD2) {
  s21::set<int> S1 = {3, 1, 2};
  std::set<int> S2 = {3, 1, 2};
  auto it_S1 = --S1.end();
  auto it_S2 = --S2.end();
  S1.erase(it_S1);
  S2.erase(it_S2);
  ASSERT_EQ(setsEqual(S1, S2), true);
}

TEST(METHOD_ERASE, SET_ERASE_ONE_CHILD3) {
  s21::set<int> S1 = {3, 4, 5};
  std::set<int> S2 = {3, 4, 5};
  S1.erase(++S1.begin());
  S2.erase(++S2.begin());
  ASSERT_EQ(setsEqual(S1, S2), true);
}

TEST(METHOD_ERASE, SET_ERASE_NO_CHILD1) {
  s21::set<int> S1 = {1, 2, 3};
  std::set<int> S2 = {1, 2, 3};
  auto it_S1 = --S1.end();
  auto it_S2 = --S2.end();
  S1.erase(it_S1);
  S2.erase(it_S2);
  ASSERT_EQ(setsEqual(S1, S2), true);
}

TEST(METHOD_ERASE, SET_ERASE_NO_CHILD2) {
  s21::set<int> S1 = {3, 1, 4};
  std::set<int> S2 = {3, 1, 4};
  S1.erase(S1.begin());
  S2.erase(S2.begin());
  ASSERT_EQ(setsEqual(S1, S2), true);
}

TEST(METHOD_ERASE, SET_ERASE_TWO_CHILDREN1) {
  s21::set<int> S1 = {3, 1, 2, 4, 5};
  std::set<int> S2 = {3, 1, 2, 4, 5};
  auto it_S1 = ++S1.begin();
  auto it_S2 = ++S2.begin();
  ++it_S1;
  ++it_S2;
  S1.erase(it_S1);
  S2.erase(it_S2);
  ASSERT_EQ(setsEqual(S1, S2), true);
}

TEST(METHOD_ERASE, SET_ERASE_TWO_CHILDREN2) {
  s21::set<int> S1 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  std::set<int> S2 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  auto it_S1 = S1.begin();
  auto it_S2 = S2.begin();
  for (int i = 0; i < 3; ++i, ++it_S1, ++it_S2)
    ;
  S1.erase(it_S1);
  S2.erase(it_S2);
  ASSERT_EQ(setsEqual(S1, S2), true);
}

TEST(METHOD_ERASE, SET_ERASE1) {
  s21::set<int> S1 = {3, 1, 2, 4, 5};
  std::set<int> S2 = {3, 1, 2, 4, 5};
  S1.erase(S1.begin());
  S2.erase(S2.begin());
  ASSERT_EQ(setsEqual(S1, S2), true);
}

TEST(METHOD_MERGE, SET_MERGE_DIFFERENT_ELEMENTS) {
  s21::set<int> S1 = {1, 3, 5};
  s21::set<int> S2 = {2, 4, 6};
  std::set<int> S3 = {1, 3, 5, 2, 4, 6};
  std::set<int> empty;
  S1.merge(S2);
  ASSERT_EQ(setsEqual(S1, S3), true);
  ASSERT_EQ(setsEqual(S2, empty), true);
}

TEST(METHOD_MERGE, SET_MERGE_IDENTICAL_ELEMENTS) {
  s21::set<int> S1 = {1, 3, 5};
  s21::set<int> S2 = {1, 3, 5};
  std::set<int> S3 = {1, 3, 5};
  S1.merge(S2);
  ASSERT_EQ(setsEqual(S1, S3), true);
  ASSERT_EQ(setsEqual(S2, S3), true);
}

TEST(METHOD_MERGE, SET_MERGE_FIRST_EMPTY) {
  s21::set<int> S1 = {};
  s21::set<int> S2 = {1, 3, 5};
  std::set<int> S3 = {1, 3, 5};
  std::set<int> empty;
  S1.merge(S2);
  ASSERT_EQ(setsEqual(S1, S3), true);
  ASSERT_EQ(setsEqual(S2, empty), true);
}

TEST(METHOD_MERGE, SET_MERGE_SECOND_EMPTY) {
  s21::set<int> S1 = {1, 3, 5};
  s21::set<int> S2 = {};
  std::set<int> S3 = {1, 3, 5};
  std::set<int> empty;
  S1.merge(S2);
  ASSERT_EQ(setsEqual(S1, S3), true);
  ASSERT_EQ(setsEqual(S2, empty), true);
}

TEST(METHOD_FIND, SET_FIND_EXISTING_ELEMENT) {
  s21::set<int> S1 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  std::set<int> S2 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  auto it_S1 = S1.find(75);
  auto it_S2 = S2.find(75);
  ASSERT_EQ(*it_S1, *it_S2);
}

TEST(METHOD_FIND, SET_FIND_NOT_EXISTING_ELEMENT1) {
  s21::set<int> S1 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  auto it_S1 = S1.find(43);
  ASSERT_EQ(*it_S1, 0);
}

TEST(METHOD_FIND, SET_FIND_NOT_EXISTING_ELEMENT2) {
  s21::set<int> S1 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  auto it_S1 = S1.find(0);
  ASSERT_EQ(*it_S1, 0);
}

TEST(METHOD_FIND, SET_FIND_NOT_EXISTING_ELEMENT3) {
  s21::set<int> S1 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  auto it_S1 = S1.find(100);
  ASSERT_EQ(*it_S1, 0);
}

TEST(METHOD_CONTAINS, SET_CONTAINS_EXISTING_ELEMENT) {
  s21::set<int> S1 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  std::set<int> S2 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  ASSERT_EQ(S1.contains(10), true);
}

TEST(METHOD_CONTAINS, SET_CONTAINS_NOT_EXISTING_ELEMENT) {
  s21::set<int> S1 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  std::set<int> S2 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  ASSERT_EQ(S1.contains(43), false);
}

TEST(METHOD_EMPLACE, SET_EMPLACE) {
  s21::set<int> S1 = {1, 2, 3};
  std::set<int> S2 = {1, 2, 3, 4, 5, 6};
  S1.emplace(4, 5, 6);
  ASSERT_EQ(setsEqual(S1, S2), true);
}

TEST(SET, SET_OPERATOR_EQUAL_COPY_NOT_EMPTY_LIST) {
  s21::set<int> S1 = {50, 25, 75, 10};
  s21::set<int> S2 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  std::set<int> S3 = {50, 25, 75, 10};
  std::set<int> S4 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  S1 = S2;
  S3 = S4;
  ASSERT_EQ(setsEqual(S1, S3), true);
  ASSERT_EQ(setsEqual(S2, S4), true);
}

TEST(SET, SET_OPERATOR_EQUAL_COPY_EMPTY_LIST) {
  s21::set<int> S1 = {50, 25, 75, 10};
  s21::set<int> S2 = {};
  std::set<int> S3 = {50, 25, 75, 10};
  std::set<int> S4 = {};
  S1 = S2;
  S3 = S4;
  ASSERT_EQ(setsEqual(S1, S3), true);
  ASSERT_EQ(setsEqual(S2, S4), true);
}

TEST(SET, SET_OPERATOR_EQUAL_COPY_SAME_SET) {
  s21::set<int> S1 = {50, 25, 75, 10};
  std::set<int> S2 = {50, 25, 75, 10};
  S1 = S1;
  S2 = S2;
  ASSERT_EQ(setsEqual(S1, S2), true);
}

TEST(SET, SET_OPERATOR_EQUAL_MOVE_NOT_EMPTY_LIST) {
  s21::set<int> S1 = {50, 25, 75, 10};
  s21::set<int> S2 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  std::set<int> S3 = {50, 25, 75, 10};
  std::set<int> S4 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  S1 = std::move(S2);
  S3 = std::move(S4);
  ASSERT_EQ(setsEqual(S1, S3), true);
  ASSERT_EQ(setsEqual(S2, S4), true);
}

TEST(SET, SET_OPERATOR_EQUAL_MOVE_EMPTY_LIST) {
  s21::set<int> S1 = {50, 25, 75, 10};
  s21::set<int> S2 = {};
  std::set<int> S3 = {50, 25, 75, 10};
  std::set<int> S4 = {};
  S1 = std::move(S2);
  S3 = std::move(S4);
  ASSERT_EQ(setsEqual(S1, S3), true);
  ASSERT_EQ(setsEqual(S2, S4), true);
}

TEST(SET, SET_OPERATOR_EQUAL_MOVE_SAME_SET) {
  s21::set<int> S1 = {50, 25, 75, 10};
  std::set<int> S2 = {50, 25, 75, 10};
  S1 = std::move(S1);
  S2 = std::move(S2);
  ASSERT_EQ(setsEqual(S1, S2), true);
}

TEST(ITERATORS, SET_PLUS_PLUS_OPERATOR) {
  s21::set<int> S1 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  std::set<int> S2 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  ASSERT_EQ(*(++S1.begin()), *(++S2.begin()));
}

TEST(ITERATORS, SET_MINUS_MINUS_OPERATOR1) {
  s21::set<int> S1 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  std::set<int> S2 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  auto it_S1 = ++S1.begin();
  auto it_S2 = ++S2.begin();
  ASSERT_EQ(*(--it_S1), *(--it_S2));
  ASSERT_EQ(*it_S1, *it_S2);
}

TEST(ITERATORS, SET_MINUS_MINUS_OPERATOR2) {
  s21::set<int> S1 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  std::set<int> S2 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  auto it_S1 = --S1.end();
  auto it_S2 = --S2.end();
  for (int i = 0; i < 10; ++i, --it_S1, --it_S2) {
  }
  ASSERT_EQ(*it_S1, *it_S2);
}

TEST(ITERATORS, SET_OPERATOR_PLUS_PLUS) {
  s21::set<int> S1 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  std::set<int> S2 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  auto it_S1 = S1.begin();
  auto it_S2 = S2.begin();
  ASSERT_EQ(*(it_S1++), *(it_S2++));
  ASSERT_EQ(*it_S1, *it_S2);
}

TEST(ITERATORS, SET_OPERATOR_MINUS_MINUS) {
  s21::set<int> S1 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  std::set<int> S2 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  auto it_S1 = ++S1.begin();
  auto it_S2 = ++S2.begin();
  ASSERT_EQ(*(it_S1--), *(it_S2--));
  ASSERT_EQ(*it_S1, *it_S2);
}

TEST(ITERATORS, SET_DEREFERENCE_OPERATOR_EXISTING_LIST_1) {
  s21::set<int> S1 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  std::set<int> S2 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  ASSERT_EQ(*S1.begin(), *S2.begin());
}

TEST(ITERATORS, SET_DEREFERENCE_OPERATOR_NOT_EXISTING_LIST) {
  try {
    s21::set<int>::iterator it_S1;
    *it_S1;
  } catch (const std::exception& e) {
    ASSERT_STREQ(e.what(), "Invalid index");
  }
}

TEST(ITERATORS, SET_NOT_EQUAL_OPERATOR) {
  s21::set<int> S1 = {1, 2, 3};
  std::set<int> S2 = {1, 2, 3};
  ASSERT_EQ(S1.begin() != S1.begin(), S2.begin() != S2.begin());
}

TEST(ITERATORS, SET_EQUAL_OPERATOR) {
  s21::set<int> S1 = {1, 2, 3};
  std::set<int> S2 = {1, 2, 3};
  ASSERT_EQ(S1.begin() == S1.begin(), S2.begin() == S2.begin());
}
}  // namespace set_tests