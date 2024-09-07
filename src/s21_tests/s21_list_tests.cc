#include <gtest/gtest.h>

#include <list>

#include "../s21_containers.h"

namespace list_tests {

TEST(List, constructor_1) {
  s21::list<int> list;
  std::list<int> l;
  EXPECT_EQ(list.size(), l.size());
}

TEST(List, constructor_2) {
  s21::list<int> list(5);
  std::list<int> l(5);
  EXPECT_EQ(list.size(), l.size());
}

TEST(List, constructor_3) {
  s21::list<int> list = {1, 2, 3, 4, 5};
  std::list<int> l = {1, 2, 3, 4, 5};
  EXPECT_EQ(list.size(), l.size());
  EXPECT_EQ(list.front(), l.front());
  EXPECT_EQ(list.back(), l.back());
}

TEST(List, constructor_4) {
  s21::list<int> list1 = {1, 2, 3, 4, 5};
  s21::list<int> list2 = list1;
  std::list<int> l1 = {1, 2, 3, 4, 5};
  std::list<int> l2 = l1;
  EXPECT_EQ(list1.size(), l1.size());
  EXPECT_EQ(list1.front(), l1.front());
  EXPECT_EQ(list1.back(), l1.back());
  EXPECT_EQ(list2.size(), l2.size());
  EXPECT_EQ(list2.front(), l2.front());
  EXPECT_EQ(list2.back(), l2.back());
}

TEST(List, constructor_5) {
  s21::list<int> list1 = {1, 2, 3, 4, 5};
  s21::list<int> list2 = std::move(list1);
  std::list<int> l1 = {1, 2, 3, 4, 5};
  std::list<int> l2 = std::move(l1);
  EXPECT_EQ(list1.size(), l1.size());
  EXPECT_EQ(list2.size(), l2.size());
  EXPECT_EQ(list2.front(), l2.front());
  EXPECT_EQ(list2.back(), l2.back());
}
TEST(List, front_1) {
  s21::list<int> list = {1, 2, 3, 4, 5};
  std::list<int> l = {1, 2, 3, 4, 5};
  EXPECT_EQ(l.front(), list.front());
}
TEST(List, front_2) {
  s21::list<int> list = {3, 2, 3, 4, 5};
  std::list<int> l = {3, 2, 3, 4, 5};
  EXPECT_EQ(l.front(), list.front());
}
TEST(List, back_1) {
  s21::list<int> list = {1, 2, 3, 4, 5};
  std::list<int> l = {1, 2, 3, 4, 5};
  EXPECT_EQ(l.front(), list.front());
}
TEST(List, back_2) {
  s21::list<int> list = {3, 2, 3, 4, 32};
  std::list<int> l = {3, 2, 3, 4, 32};
  EXPECT_EQ(l.front(), list.front());
}
TEST(List, test_1) {
  s21::list<int> list = {1, 2, 3, 4, 5};
  std::list<int> l = {1, 2, 3, 4, 5};
  auto it1 = list.begin();
  auto it2 = list.begin();
  auto i1 = l.begin();
  auto i2 = l.begin();
  EXPECT_EQ(i1 == i2, it1 == it2);
  EXPECT_EQ(i1 != i2, it1 != it2);
  EXPECT_EQ(*(i1), *(it1));
  EXPECT_EQ(*(++i1), *(++it1));
  EXPECT_EQ(i1 == i2, it1 == it2);
  EXPECT_EQ(i1 != i2, it1 != it2);
  EXPECT_EQ(*(++i1), *(++it1));
  EXPECT_EQ(*(++i1), *(++it1));
  EXPECT_EQ(*(++i1), *(++it1));
  EXPECT_EQ(*(++ ++ ++ ++ ++ ++i1), *(++ ++ ++ ++ ++ ++it1));
}

TEST(List, test_2) {
  s21::list<int> list = {1, 2, 3, 4, 5};
  std::list<int> l = {1, 2, 3, 4, 5};
  auto it1 = list.end();
  auto it2 = list.end();
  auto i1 = l.end();
  auto i2 = l.end();
  EXPECT_EQ(i1 == i2, it1 == it2);
  EXPECT_EQ(i1 != i2, it1 != it2);
  EXPECT_EQ(*(--i1), *(--it1));
  EXPECT_EQ(i1 == i2, it1 == it2);
  EXPECT_EQ(i1 != i2, it1 != it2);
  EXPECT_EQ(*(--i1), *(--it1));
  EXPECT_EQ(*(--i1), *(--it1));
  EXPECT_EQ(*(--i1), *(--it1));
  EXPECT_EQ(*(-- -- -- -- -- --i1), *(-- -- -- -- -- --it1));
}

TEST(List, test_3) {
  const s21::list<int> list = {1, 2, 3, 4, 5};
  auto it1 = list.cend();
  auto it2 = list.cend();
  auto it3 = list.cbegin();
  const std::list<int> l = {1, 2, 3, 4, 5};
  auto i1 = l.cend();
  auto i2 = l.cend();
  auto i3 = l.cbegin();
  EXPECT_EQ(i1 == i2, it1 == it2);
  EXPECT_EQ(i1 == i3, it1 == it3);
  EXPECT_EQ(i1 != i2, it1 != it2);
  EXPECT_EQ(i1 != i3, it1 != it3);
  EXPECT_EQ(*(--i1), *(--it1));
  EXPECT_EQ(*(--i1), *(--it1));
  EXPECT_EQ(*(--i1), *(--it1));
  EXPECT_EQ(*(--i1), *(--it1));
  EXPECT_EQ(*(-- -- -- -- -- --i1), *(-- -- -- -- -- --it1));
}
TEST(List, empty_1) {
  s21::list<int> list = {1, 2, 3, 4, 5};
  std::list<int> l = {1, 2, 3, 4, 5};
  EXPECT_EQ(list.empty(), l.empty());
}
TEST(List, empty_2) {
  s21::list<int> list;
  std::list<int> l;
  EXPECT_EQ(l.empty(), list.empty());
}
TEST(List, size_1) {
  s21::list<int> list = {1, 2, 3};
  std::list<int> l = {1, 2, 3};
  EXPECT_EQ(l.size(), list.size());
}
TEST(List, size_2) {
  s21::list<int> list = {1, 2, 3, 4, 5};
  std::list<int> l = {1, 2, 3, 4, 5};
  EXPECT_EQ(l.size(), list.size());
}
TEST(List, size_3) {
  s21::list<int> list;
  std::list<int> l;
  EXPECT_EQ(l.size(), list.size());
}

TEST(List, clear_1) {
  s21::list<int> list = {1, 2, 3, 4, 5};
  std::list<int> l = {1, 2, 3, 4, 5};
  list.clear();
  l.clear();
  EXPECT_EQ(list.size(), l.size());
}

TEST(List, insert) {
  s21::list<int> list = {1, 2, 3, 4, 5};
  auto it = list.begin();
  std::list<int> l = {1, 2, 3, 4, 5};
  auto i = l.begin();
  list.insert(it, 20);
  l.insert(i, 20);
  EXPECT_EQ(*(--i), *(--it));
  list.insert(++ ++ ++it, 200);
  l.insert(++ ++ ++i, 200);
  EXPECT_EQ(*(--it), *(--i));
  EXPECT_EQ(*(-- -- -- -- -- --it), *(-- -- -- -- -- --i));
  EXPECT_EQ(*(++ ++ ++ ++ ++ ++it), *(++ ++ ++ ++ ++ ++i));
}

TEST(List, erase) {
  s21::list<int> list = {1, 2, 3, 4, 5};
  auto it = list.begin();
  s21::list<int> l = {1, 2, 3, 4, 5};
  auto i = l.begin();
  ++it;
  ++i;
  list.erase(it);
  l.erase(i);
  EXPECT_EQ(list.size(), l.size());
}

TEST(List, push_back) {
  s21::list<int> list = {1, 2, 3, 4, 5};
  list.push_back(200);
  std::list<int> l = {1, 2, 3, 4, 5};
  l.push_back(200);
  EXPECT_EQ(l.size(), list.size());
  EXPECT_EQ(l.back(), list.back());
}
TEST(List, push_front) {
  s21::list<int> list = {1, 2, 3, 4, 5};
  list.push_front(200);
  std::list<int> l = {1, 2, 3, 4, 5};
  l.push_front(200);
  EXPECT_EQ(l.size(), list.size());
  EXPECT_EQ(l.front(), list.front());
}
TEST(List, pop_back) {
  s21::list<int> list = {1, 2, 3, 4, 5};
  list.pop_back();
  std::list<int> l = {1, 2, 3, 4, 5};
  l.pop_back();
  EXPECT_EQ(l.size(), list.size());
  EXPECT_EQ(l.back(), list.back());
}
TEST(List, pop_front) {
  s21::list<int> list = {1, 2, 3, 4, 5};
  list.pop_front();
  std::list<int> l = {1, 2, 3, 4, 5};
  l.pop_front();
  EXPECT_EQ(l.size(), list.size());
  EXPECT_EQ(l.front(), list.front());
}

TEST(List, swap) {
  s21::list<int> list1 = {0, 1, 2, 3, 4};
  s21::list<int> list2 = {5, 6, 7, 8};
  list1.swap(list2);
  std::list<int> l1 = {0, 1, 2, 3, 4};
  std::list<int> l2 = {5, 6, 7, 8};
  l1.swap(l2);
  EXPECT_EQ(list1.size(), l1.size());
  EXPECT_EQ(list2.size(), l2.size());
  EXPECT_EQ(list2.front(), l2.front());
  EXPECT_EQ(list2.back(), l2.back());
  EXPECT_EQ(list1.front(), l1.front());
  EXPECT_EQ(list1.back(), l1.back());
}

TEST(List, merge) {
  s21::list<int> list1 = {0, 1, 2, 3, 4};
  s21::list<int> list2 = {5, 6, 7, 8};
  list1.merge(list2);
  std::list<int> l1 = {0, 1, 2, 3, 4};
  std::list<int> l2 = {5, 6, 7, 8};
  l1.merge(l2);
  EXPECT_EQ(list1.size(), l1.size());
  EXPECT_EQ(list2.size(), l2.size());
  EXPECT_EQ(list1.front(), l1.front());
  EXPECT_EQ(list1.back(), l1.back());
}
TEST(List, splice) {
  s21::list<int> list1 = {0, 1, 2, 3, 4};
  s21::list<int> list2 = {5, 6, 7, 8};
  auto it = list1.begin();
  std::list<int> l1 = {0, 1, 2, 3, 4};
  std::list<int> l2 = {5, 6, 7, 8};
  auto i = l1.begin();
  ++ ++it;
  ++ ++i;
  list1.splice(it, list2);
  l1.splice(i, l2);
  EXPECT_EQ(list1.size(), l1.size());
  EXPECT_EQ(list2.size(), l2.size());
  EXPECT_EQ(list1.front(), l1.front());
  EXPECT_EQ(list1.back(), l1.back());
  i = l1.begin();
  it = list1.begin();
  EXPECT_EQ(*it, *i);
}
TEST(List, reverse) {
  s21::list<int> list = {0, 1, 2, 3, 4};
  list.reverse();
  std::list<int> l = {0, 1, 2, 3, 4};
  l.reverse();
  EXPECT_EQ(list.front(), l.front());
  EXPECT_EQ(list.back(), l.back());
  EXPECT_EQ(list.size(), l.size());
}
TEST(List, unique) {
  s21::list<int> list = {0, 2, 2, 2, 4};
  list.unique();
  auto it = list.begin();
  std::list<int> l = {0, 2, 2, 2, 4};
  l.unique();
  auto i = l.begin();
  ++it;
  ++i;
  EXPECT_EQ(list.size(), l.size());
  EXPECT_EQ(list.front(), l.front());
  EXPECT_EQ(list.back(), l.back());
  EXPECT_EQ(*it, *i);
  ++it;
  ++i;
  EXPECT_EQ(*it, *i);
}
TEST(List, sort) {
  s21::list<int> list = {7, 5, 9, 3, 2};
  list.sort();
  auto it = list.begin();
  std::list<int> l = {7, 5, 9, 3, 2};
  l.sort();
  auto i = l.begin();
  EXPECT_EQ(list.size(), l.size());
  EXPECT_EQ(*it, *i);
  EXPECT_EQ(*(++it), *(++i));
  EXPECT_EQ(*(++it), *(++i));
  EXPECT_EQ(*(++it), *(++i));
  EXPECT_EQ(*(++it), *(++i));
  EXPECT_EQ(*(++ ++it), *(++ ++i));
  EXPECT_EQ(*(++it), *(++i));
  EXPECT_EQ(*(++it), *(++i));
  EXPECT_EQ(*(++it), *(++i));
  EXPECT_EQ(*(++it), *(++i));
  EXPECT_EQ(*(++ ++it), *(++ ++i));
  EXPECT_EQ(*(++it), *(++i));
  EXPECT_EQ(*it, *i);
  EXPECT_EQ(*(--it), *(--i));
  EXPECT_EQ(*(-- --it), *(-- --i));
  EXPECT_EQ(*(--it), *(--i));
  EXPECT_EQ(*(--it), *(--i));
  EXPECT_EQ(*(--it), *(--i));
  EXPECT_EQ(*(--it), *(--i));
  EXPECT_EQ(*(-- --it), *(-- --i));
  EXPECT_EQ(*(--it), *(--i));
  EXPECT_EQ(*(--it), *(--i));
  EXPECT_EQ(*(--it), *(--i));
  EXPECT_EQ(*(--it), *(--i));
}

TEST(List, equal) {
  s21::list<int> list1 = {7, 5, 9, 3, 2};
  s21::list<int> list2;
  std::list<int> l1 = {7, 5, 9, 3, 2};
  std::list<int> l2;
  EXPECT_EQ(list1.size(), l1.size());
  EXPECT_EQ(list2.size(), l2.size());
  list2 = list1;
  l2 = l1;
  EXPECT_EQ(list1.size(), l1.size());
  EXPECT_EQ(list2.size(), l2.size());
  auto i1 = l1.begin();
  auto i2 = l2.begin();
  auto it1 = list1.begin();
  auto it2 = list2.begin();
  EXPECT_EQ(*i1, *it1);
  EXPECT_EQ(*(++i2), *(++it2));
  EXPECT_EQ(*(++i2), *(++it2));
  EXPECT_EQ(*(++i2), *(++it2));
  EXPECT_EQ(*(++i2), *(++it2));
  EXPECT_EQ(*(++ ++i2), *(++ ++it2));
  EXPECT_EQ(*(++i2), *(++it2));
  EXPECT_EQ(*(++i2), *(++it2));
  EXPECT_EQ(*(++i2), *(++it2));
  EXPECT_EQ(*(++i2), *(++it2));
  EXPECT_EQ(*(++ ++i2), *(++ ++it2));
  EXPECT_EQ(*(i1), *(it1));
  EXPECT_EQ(*(++i1), *(++it1));
  EXPECT_EQ(*(++i1), *(++it1));
  EXPECT_EQ(*(++i1), *(++it1));
  EXPECT_EQ(*(++i1), *(++it1));
  EXPECT_EQ(*(++ ++i1), *(++ ++it1));
  EXPECT_EQ(*(++i1), *(++it1));
  EXPECT_EQ(*(++i1), *(++it1));
  EXPECT_EQ(*(++i1), *(++it1));
  EXPECT_EQ(*(++i1), *(++it1));
  EXPECT_EQ(*(++ ++i1), *(++ ++it1));
  EXPECT_EQ(*i1, *it1);
  EXPECT_EQ(*(-- --i2), *(-- --it2));
  EXPECT_EQ(*(--i2), *(--it2));
  EXPECT_EQ(*(--i2), *(--it2));
  EXPECT_EQ(*(--i2), *(--it2));
  EXPECT_EQ(*(--i2), *(--it2));
  EXPECT_EQ(*(-- --i2), *(-- --it2));
  EXPECT_EQ(*(--i2), *(--it2));
  EXPECT_EQ(*(--i2), *(--it2));
  EXPECT_EQ(*(--i2), *(--it2));
  EXPECT_EQ(*(--i2), *(--it2));
  EXPECT_EQ(*(i1), *(it1));
  EXPECT_EQ(*(-- --i1), *(-- --it1));
  EXPECT_EQ(*(--i1), *(--it1));
  EXPECT_EQ(*(--i1), *(--it1));
  EXPECT_EQ(*(--i1), *(--it1));
  EXPECT_EQ(*(--i1), *(--it1));
  EXPECT_EQ(*(-- --i1), *(-- --it1));
  EXPECT_EQ(*(--i1), *(--it1));
  EXPECT_EQ(*(--i1), *(--it1));
  EXPECT_EQ(*(--i1), *(--it1));
  EXPECT_EQ(*(--i1), *(--it1));
}

TEST(List, move_equal) {
  s21::list<int> list1 = {7, 5, 9, 3, 2};
  s21::list<int> list2;
  std::list<int> l1 = {7, 5, 9, 3, 2};
  std::list<int> l2;
  list2 = std::move(list1);
  l2 = std::move(l1);
  EXPECT_EQ(list1.size(), l1.size());
  EXPECT_EQ(list2.size(), l2.size());
  auto i2 = l2.begin();
  auto it2 = list2.begin();
  EXPECT_EQ(*i2, *it2);
  EXPECT_EQ(*(++i2), *(++it2));
  EXPECT_EQ(*(++i2), *(++it2));
  EXPECT_EQ(*(++i2), *(++it2));
  EXPECT_EQ(*(++i2), *(++it2));
  EXPECT_EQ(*(++ ++i2), *(++ ++it2));
  EXPECT_EQ(*(++i2), *(++it2));
  EXPECT_EQ(*(++i2), *(++it2));
  EXPECT_EQ(*(++i2), *(++it2));
  EXPECT_EQ(*(++i2), *(++it2));
  EXPECT_EQ(*(++ ++i2), *(++ ++it2));
  EXPECT_EQ(*(-- --i2), *(-- --it2));
  EXPECT_EQ(*(--i2), *(--it2));
  EXPECT_EQ(*(--i2), *(--it2));
  EXPECT_EQ(*(--i2), *(--it2));
  EXPECT_EQ(*(--i2), *(--it2));
  EXPECT_EQ(*(-- --i2), *(-- --it2));
  EXPECT_EQ(*(--i2), *(--it2));
  EXPECT_EQ(*(--i2), *(--it2));
  EXPECT_EQ(*(-- --i2), *(-- --it2));
}

TEST(List, insert_many_front) {
  s21::list<int> l = {1, 2, 3};
  l.insert_many_front(4, 5, 6);
  auto it = l.begin();
  EXPECT_EQ(*it, 4);
  EXPECT_EQ(*++it, 5);
  EXPECT_EQ(*++it, 6);
  EXPECT_EQ(*++it, 1);
  EXPECT_EQ(*++it, 2);
  EXPECT_EQ(*++it, 3);
}

TEST(List, insert_many_back) {
  s21::list<int> l = {1, 2, 3};
  l.insert_many_back(4, 5, 6);
  auto it = l.begin();
  EXPECT_EQ(*it, 1);
  EXPECT_EQ(*++it, 2);
  EXPECT_EQ(*++it, 3);
  EXPECT_EQ(*++it, 4);
  EXPECT_EQ(*++it, 5);
  EXPECT_EQ(*++it, 6);
}

TEST(List, insert_many) {
  s21::list<int> l = {1, 2, 3};
  auto it = l.begin();
  ++ ++it;
  l.insert_many(it, 4, 5, 6);
  it = l.begin();
  EXPECT_EQ(*it, 1);
  EXPECT_EQ(*++it, 2);
  EXPECT_EQ(*++it, 4);
  EXPECT_EQ(*++it, 5);
  EXPECT_EQ(*++it, 6);
  EXPECT_EQ(*++it, 3);
}

}  // namespace list_tests