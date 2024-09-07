#include <gtest/gtest.h>

#include <initializer_list>
#include <map>

#include "../s21_containers.h"

namespace map_tests {

bool mapsEqual(s21::map<int, char> M1, std::map<int, char> M2) {
  if (M1.size() != M2.size()) return false;
  s21::map<int, char>::iterator it_M1 = M1.begin();
  std::map<int, char>::iterator it_M2 = M2.begin();
  for (; it_M2 != M2.end(); ++it_M1, ++it_M2) {
    if (*it_M1 != *it_M2) return false;
  }
  return true;
}

void printM1(s21::map<int, char> M1) {
  s21::map<int, char>::iterator it_M1 = M1.begin();
  std::cout << std::endl;
  for (; it_M1 != M1.end(); ++it_M1) {
    std::cout << (*it_M1).first << " " << (*it_M1).second << std::endl;
  }
  std::cout << std::endl;
}

void printM2(std::map<int, char> M2) {
  std::map<int, char>::iterator it_M2 = M2.begin();
  std::cout << std::endl;
  for (; it_M2 != M2.end(); ++it_M2) {
    std::cout << (*it_M2).first << " " << (*it_M2).second << std::endl;
  }
  std::cout << std::endl;
}

TEST(MAP_CONSTRUCTORS, MAP_DEFAULT_CONSTRUCTOR) {
  s21::map<int, char> M1;
  std::map<int, char> M2;
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(MAP_CONSTRUCTORS, MAP_LIST_CONSTRUCTOR) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(MAP_CONSTRUCTORS, MAP_COPY_CONSTRUCTOR) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::map<int, char> M2(M1);
  std::map<int, char> M3 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M4(M3);
  ASSERT_EQ(mapsEqual(M2, M4), true);
  ASSERT_EQ(mapsEqual(M1, M3), true);
}

TEST(MAP_CONSTRUCTORS, MAP_MOVE_CONSTRUCTOR) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::map<int, char> M2(std::move(M1));
  std::map<int, char> M3 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M4(std::move(M3));
  ASSERT_EQ(mapsEqual(M2, M4), true);
  ASSERT_EQ(mapsEqual(M1, M3), true);
}

TEST(MAP_METHOD_AT, MAP_AT_IN_BOUNDS1) {
  s21::map<int, char> M1 = {{3, 'a'}, {2, 'b'}, {1, 'c'}};
  std::map<int, char> M2 = {{3, 'a'}, {2, 'b'}, {1, 'c'}};
  ASSERT_EQ(M1.at(2), M2.at(2));
}

TEST(MAP_METHOD_AT, MAP_AT_IN_BOUNDS2) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  ASSERT_EQ(M1.at(2), M2.at(2));
}

TEST(MAP_METHOD_AT, MAP_AT_OUT_OF_BOUNDS) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  ASSERT_THROW(M2.at(36), std::out_of_range);
  ASSERT_THROW(M1.at(36), std::out_of_range);
}

TEST(MAP_METHOD_AT, MAP_AT_ENTERING_VALUE) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  M1.at(2) = 'q';
  M2.at(2) = 'q';
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(MAP_METHOD_EMPTY, MAP_EMPTY_DEFAULT_CONSTRUCTOR) {
  s21::map<int, char> M1;
  std::map<int, char> M2;
  ASSERT_EQ(M1.empty(), M2.empty());
}

TEST(MAP_METHOD_EMPTY, MAP_EMPTY_LIST_CONSTRUCTOR) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  ASSERT_EQ(M1.empty(), M2.empty());
  s21::map<int, char> M3 = {};
  std::map<int, char> M4 = {};
  ASSERT_EQ(M3.empty(), M4.empty());
  s21::map<int, char> M5 = {{1, 'a'}};
  std::map<int, char> M6 = {{1, 'a'}};
  ASSERT_EQ(M5.empty(), M6.empty());
}

TEST(MAP_METHOD_EMPTY, MAP_EMPTY_COPY_CONSTRUCTOR) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::map<int, char> M2(M1);
  std::map<int, char> M3 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M4(M3);
  ASSERT_EQ(M1.empty(), M3.empty());
  ASSERT_EQ(M2.empty(), M4.empty());
  s21::map<int, char> M5;
  s21::map<int, char> M6(M5);
  std::map<int, char> M7;
  std::map<int, char> M8(M7);
  ASSERT_EQ(M5.empty(), M7.empty());
  ASSERT_EQ(M6.empty(), M8.empty());
}

TEST(MAP_METHOD_EMPTY, MAP_EMPTY_MOVE_CONSTRUCTOR) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::map<int, char> M2(std::move(M1));
  std::map<int, char> M3 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M4(std::move(M3));
  ASSERT_EQ(M1.empty(), M3.empty());
  ASSERT_EQ(M2.empty(), M4.empty());
  s21::map<int, char> M5;
  s21::map<int, char> M6(std::move(M5));
  std::map<int, char> M7;
  std::map<int, char> M8(std::move(M7));
  ASSERT_EQ(M5.empty(), M7.empty());
  ASSERT_EQ(M6.empty(), M8.empty());
}

TEST(MAP_METHOD_SIZE, MAP_SIZE_DEFAULT_CONSTRUCTOR) {
  s21::map<int, char> M1;
  std::map<int, char> M2;
  ASSERT_EQ(M1.size(), M2.size());
}

TEST(MAP_METHOD_SIZE, MAP_SIZE_LIST_CONSTRUCTOR) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  ASSERT_EQ(M1.size(), M2.size());
}

TEST(MAP_METHOD_SIZE, MAP_SIZE_COPY_CONSTRUCTOR) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::map<int, char> M2(M1);
  std::map<int, char> M3 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M4(M3);
  ASSERT_EQ(M1.size(), M3.size());
  ASSERT_EQ(M2.size(), M4.size());
}

TEST(MAP_METHOD_SIZE, MAP_SIZE_MOVE_CONSTRUCTOR) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::map<int, char> M2(std::move(M1));
  std::map<int, char> M3 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M4(std::move(M3));
  ASSERT_EQ(M1.size(), M3.size());
  ASSERT_EQ(M2.size(), M4.size());
}

TEST(MAP_METHOD_MAX_SIZE, MAP_MAX_SIZE) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  EXPECT_NEAR(M1.max_size() / M2.max_size(), 1, 1);
}

TEST(MAP_METHOD_CLEAR, MAP_CLEAR) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  M1.clear();
  M2.clear();
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(MAP_METHOD_INSERT, MAP_INSERT_BY_PAIR_EXISTING_ELEMENT) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  M1.insert(std::pair<int, char>(3, 'c'));
  M2.insert(std::pair<int, char>(3, 'c'));
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(MAP_METHOD_INSERT, MAP_INSERT_BY_VALUE_SEPARATED_EXISTING_ELEMENT) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  M1.insert(3, 'c');
  M2.insert(std::pair<int, char>(3, 'c'));
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(MAP_METHOD_INSERT, MAP_INSERT_0_ELEMENTS) {
  s21::map<int, char> M1 = {};
  std::map<int, char> M2 = {};
  M1.insert(std::pair<int, char>(3, 'c'));
  M2.insert(std::pair<int, char>(3, 'c'));
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(MAP_METHOD_INSERT, MAP_INSERT_MIDDLE_ELEMENT) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {4, 'd'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {4, 'd'}};
  M1.insert(std::pair<int, char>(3, 'c'));
  M2.insert(std::pair<int, char>(3, 'c'));
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(MAP_METHOD_INSERT_OR_ASSIGN, MAP_INSERT_MIDDLE_ELEMENT_DOES_NOT_CONTAIN) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {4, 'd'}};
  auto res = M1.insert_or_assign(3, 'c');

  ASSERT_EQ(res.second, true);
}

TEST(MAP_METHOD_INSERT_OR_ASSIGN, MAP_INSERT_MIDDLE_ELEMENT_CONTAINS) {
  s21::map<int, char> M1 = {{1, 'a'}, {3, 'c'}, {4, 'd'}};
  auto res = M1.insert_or_assign(3, 'c');
  ASSERT_EQ(res.second, false);
}

TEST(MAP_METHOD_ERASE, MAP_ERASE_NO_CHILD) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::map<int, char>::iterator it_M1 = --M1.end();
  std::map<int, char>::iterator it_M2 = --M2.end();
  M1.erase(it_M1);
  M2.erase(it_M2);
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(MAP_METHOD_ERASE, MAP_ERASE_TWO_CHILDREN) {
  s21::map<int, char> M1 = {{3, 'c'}, {1, 'a'}, {2, 'b'}, {4, 'd'}, {5, 'e'}};
  std::map<int, char> M2 = {{3, 'c'}, {1, 'a'}, {2, 'b'}, {4, 'd'}, {5, 'e'}};
  s21::map<int, char>::iterator it_M1 = ++M1.begin();
  std::map<int, char>::iterator it_M2 = ++M2.begin();
  ++it_M1;
  ++it_M2;
  M1.erase(it_M1);
  M2.erase(it_M2);
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(MAP_METHOD_SWAP, MAP_SWAP_ONE_LIST_EMPTY1) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::map<int, char> M2 = {};
  std::map<int, char> M3 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M4 = {};
  M1.swap(M2);
  M3.swap(M4);
  ASSERT_EQ(mapsEqual(M1, M3), true);
  ASSERT_EQ(mapsEqual(M2, M4), true);
}

TEST(MAP_METHOD_SWAP, MAP_SWAP_ONE_LIST_EMPTY2) {
  s21::map<int, char> M1 = {};
  s21::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M3 = {};
  std::map<int, char> M4 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  M1.swap(M2);
  M3.swap(M4);
  ASSERT_EQ(mapsEqual(M1, M3), true);
  ASSERT_EQ(mapsEqual(M2, M4), true);
}

TEST(MAP_METHOD_SWAP, MAP_SWAP_NUMBER_OF_ELEMENTS) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::map<int, char> M2 = {{4, 'd'}, {5, 'e'}, {6, 'f'}};
  std::map<int, char> M3 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M4 = {{4, 'd'}, {5, 'e'}, {6, 'f'}};
  M1.swap(M2);
  M3.swap(M4);
  ASSERT_EQ(mapsEqual(M1, M3), true);
  ASSERT_EQ(mapsEqual(M2, M4), true);
}

TEST(MAP_METHOD_MERGE, MAP_MERGE_DIFFERENT_ELEMENTS) {
  s21::map<int, char> M1 = {{1, 'a'}, {3, 'c'}, {5, 'e'}};
  s21::map<int, char> M2 = {{2, 'b'}, {4, 'd'}, {6, 'f'}};
  std::map<int, char> M3 = {{1, 'a'}, {3, 'c'}, {5, 'e'},
                            {2, 'b'}, {4, 'd'}, {6, 'f'}};
  std::map<int, char> empty;
  M1.merge(M2);
  ASSERT_EQ(mapsEqual(M1, M3), true);
  ASSERT_EQ(mapsEqual(M2, empty), true);
}

TEST(MAP_METHOD_CONTAINS, MAP_CONTAINS_EXISTING_ELEMENT) {
  s21::map<int, char> M1 = {{50, 'a'}, {25, 'b'}, {75, 'c'},
                            {10, 'd'}, {40, 'e'}, {51, 'f'}};
  ASSERT_EQ(M1.contains(std::pair<int, char>(10, 'd')), true);
}

TEST(MAP_METHOD_EMPLACE, MAP_EMPLACE) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {
      {1, 'a'},
      {2, 'b'},
      {3, 'c'},
      {4, 'd'},
  };
  M1.emplace(std::pair<int, char>(4, 'd'));
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(MAP_OPERATOR_OVERLOADS, MAP_OPERATOR_ASSIGNMENT_COPY_SAME_SET) {
  s21::map<int, char> M1 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  std::map<int, char> M2 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  M1 = M1;
  M2 = M2;
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(MAP_OPERATOR_OVERLOADS, MAP_OPERATOR_ASSIGNMENT_COPY) {
  s21::map<int, char> M1 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  s21::map<int, char> M2 = {{10, 'q'}, {20, 'w'}, {30, 'e'}, {40, 'r'}};
  std::map<int, char> M3 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  std::map<int, char> M4 = {{10, 'q'}, {20, 'w'}, {30, 'e'}, {40, 'r'}};
  M1 = M2;
  M3 = M4;
  ASSERT_EQ(mapsEqual(M1, M3), true);
  ASSERT_EQ(mapsEqual(M2, M4), true);
}

TEST(MAP_OPERATOR_OVERLOADS, MAP_OPERATOR_ASSIGNMENT_MOVE_SAME_SET) {
  s21::map<int, char> M1 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  std::map<int, char> M2 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  M1 = std::move(M1);
  M2 = std::move(M2);
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(MAP_OPERATOR_OVERLOADS, MAP_OPERATOR_ACCESS) {
  s21::map<int, char> M1 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  std::map<int, char> M2 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  ASSERT_EQ(M1[75], M2[75]);
}

TEST(MAP_OPERATOR_OVERLOADS, MAP_OPERATOR_INSERT) {
  s21::map<int, char> M1 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  std::map<int, char> M2 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(MAP_ITERATORS, MAP_PLUS_PLUS_OPERATOR) {
  s21::map<int, char> M1 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  std::map<int, char> M2 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  s21::map<int, char>::iterator it_M1 = ++M1.begin();
  std::map<int, char>::iterator it_M2 = ++M2.begin();
  ASSERT_EQ((*it_M1).first, (*it_M2).first);
  ASSERT_EQ((*it_M1).second, (*it_M2).second);
}

TEST(MAP_ITERATORS, MAP_MINUS_MINUS_OPERATOR) {
  s21::map<int, char> M1 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  std::map<int, char> M2 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  s21::map<int, char>::iterator it_M1 = --M1.end();
  std::map<int, char>::iterator it_M2 = --M2.end();
  ASSERT_EQ((*it_M1).first, (*it_M2).first);
  ASSERT_EQ((*it_M1).second, (*it_M2).second);
}

TEST(MAP_ITERATORS, MAP_OPERATOR_PLUS_PLUS) {
  s21::map<int, char> M1 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  std::map<int, char> M2 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  s21::map<int, char>::iterator it_M1 = M1.begin();
  std::map<int, char>::iterator it_M2 = M2.begin();
  it_M1++;
  it_M2++;
  ASSERT_EQ((*it_M1).first, (*it_M2).first);
  ASSERT_EQ((*it_M1).second, (*it_M2).second);
}

TEST(MAP_ITERATORS, MAP_OPERATOR_MINUS_MINUS) {
  s21::map<int, char> M1 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  std::map<int, char> M2 = {
      {50, 'a'},
      {25, 'b'},
      {75, 'c'},
      {10, 'd'},
  };
  s21::map<int, char>::iterator it_M1 = M1.end();
  std::map<int, char>::iterator it_M2 = M2.end();
  it_M1--;
  it_M2--;
  ASSERT_EQ(*it_M1, *it_M2);
}

TEST(MAP_ITERATORS, MAP_DEREFERENCE_OPERATOR_EXISTING_LIST) {
  s21::map<int, char> M1 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  std::map<int, char> M2 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  ASSERT_EQ((*(M1.begin())).first, ((*M2.begin())).first);
  ASSERT_EQ((*(M1.begin())).second, ((*M2.begin())).second);
}

TEST(MAP_ITERATORS, MAP_DEREFERENCE_OPERATOR_NOT_EXISTING_LIST) {
  try {
    s21::map<int, char>::iterator it_S1;
    *it_S1;
  } catch (const std::exception& e) {
    ASSERT_STREQ(e.what(), "Invalid index");
  }
}

TEST(MAP_ITERATORS, MAP_NOT_EQUAL_OPERATOR) {
  s21::map<int, char> M1 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  std::map<int, char> M2 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  ASSERT_EQ(M1.begin() != M1.begin(), M2.begin() != M2.begin());
}

TEST(MAP_ITERATORS, MAP_EQUAL_OPERATOR) {
  s21::map<int, char> M1 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  std::map<int, char> M2 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  ASSERT_EQ(M1.begin() == M1.begin(), M2.begin() == M2.begin());
}
}  // namespace map_tests