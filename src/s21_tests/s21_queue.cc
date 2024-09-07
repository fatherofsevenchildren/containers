#include <gtest/gtest.h>

#include <queue>

#include "../s21_containers.h"

namespace queue_tests {

TEST(queue, contructor_1) {
  s21::queue<int> st;
  std::queue<int> s;
  EXPECT_EQ(s.size(), st.size());
}

TEST(queue, contructor_2) {
  s21::queue<int> st = {1, 2, 3};
  EXPECT_EQ(3, st.size());
}

TEST(queue, contructor_3) {
  s21::queue<int> st1;
  st1.push(1);
  st1.push(2);
  st1.push(3);
  s21::queue<int> st2 = st1;
  std::queue<int> s1;
  s1.push(1);
  s1.push(2);
  s1.push(3);
  std::queue<int> s2 = s1;
  EXPECT_EQ(st1.size(), st2.size());
  EXPECT_EQ(s2.size(), st2.size());
  EXPECT_EQ(s1.size(), st1.size());
}

TEST(queue, contructor_4) {
  s21::queue<int> st1 = {1, 2, 3};
  s21::queue<int> st2 = std::move(st1);
  std::queue<int> s1;
  s1.push(1);
  s1.push(2);
  s1.push(3);
  std::queue<int> s2 = std::move(s1);
  EXPECT_EQ(st1.size(), 0);
  EXPECT_EQ(st2.size(), 3);
  EXPECT_EQ(s2.size(), st2.size());
  EXPECT_EQ(s1.size(), st1.size());
}

TEST(queue, eq) {
  s21::queue<int> st1 = {1, 2, 3};
  s21::queue<int> st2;
  st2 = st1;
  std::queue<int> s1;
  s1.push(1);
  s1.push(2);
  s1.push(3);
  std::queue<int> s2;
  s2 = s1;
  EXPECT_EQ(st1.size(), st2.size());
  EXPECT_EQ(s2.size(), st2.size());
  EXPECT_EQ(s1.size(), st1.size());
}

TEST(queue, eq_move) {
  s21::queue<int> st1 = {1, 2, 3};
  s21::queue<int> st2;
  st2 = std::move(st1);
  std::queue<int> s1;
  s1.push(1);
  s1.push(2);
  s1.push(3);
  std::queue<int> s2;
  s2 = std::move(s1);
  EXPECT_EQ(st1.size(), 0);
  EXPECT_EQ(st2.size(), 3);
  EXPECT_EQ(s2.size(), st2.size());
  EXPECT_EQ(s1.size(), st1.size());
}

TEST(queue, front_back) {
  s21::queue<int> st;
  std::queue<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  st.push(1);
  st.push(2);
  st.push(3);
  EXPECT_EQ(s.front(), st.front());
  EXPECT_EQ(s.back(), st.back());
}

TEST(queue, empty) {
  s21::queue<int> st;
  std::queue<int> s;
  EXPECT_EQ(s.empty(), st.empty());
  s.push(1);
  s.push(2);
  s.push(3);
  st.push(1);
  st.push(2);
  st.push(3);
  EXPECT_EQ(s.empty(), st.empty());
}

TEST(queue, size) {
  s21::queue<int> st;
  std::queue<int> s;
  EXPECT_EQ(s.size(), st.size());
  s.push(1);
  s.push(2);
  s.push(3);
  st.push(1);
  st.push(2);
  st.push(3);
  EXPECT_EQ(s.size(), st.size());
}

TEST(queue, push) {
  s21::queue<int> st;
  std::queue<int> s;
  s.push(1);
  st.push(1);
  EXPECT_EQ(s.front(), st.front());
  EXPECT_EQ(s.back(), st.back());
  s.push(2);
  st.push(2);
  EXPECT_EQ(s.front(), st.front());
  EXPECT_EQ(s.back(), st.back());
  s.push(3);
  st.push(3);
  EXPECT_EQ(s.front(), st.front());
  EXPECT_EQ(s.back(), st.back());
}

TEST(queue, swap) {
  s21::queue<int> st1;
  std::queue<int> s1;
  s1.push(1);
  s1.push(2);
  s1.push(3);
  st1.push(1);
  st1.push(2);
  st1.push(3);
  s21::queue<int> st2;
  std::queue<int> s2;
  s2.push(4);
  s2.push(5);
  s2.push(6);
  st2.push(4);
  st2.push(5);
  st2.push(6);
  st1.swap(st2);
  s1.swap(s2);
  EXPECT_EQ(s1.size(), st1.size());
  EXPECT_EQ(s2.size(), st2.size());
  EXPECT_EQ(s1.front(), st1.front());
  EXPECT_EQ(s2.front(), st2.front());
  EXPECT_EQ(s1.back(), st1.back());
  EXPECT_EQ(s2.back(), st2.back());
}

TEST(List, insert_many_back) {
  s21::queue<int> l = {1, 2, 3};
  l.insert_many_back(4, 5, 6);
  EXPECT_EQ(l.size(), 6);
  EXPECT_EQ(l.front(), 1);
  EXPECT_EQ(l.back(), 6);
}
}  // namespace queue_tests