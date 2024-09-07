#include <gtest/gtest.h>

#include <stack>

#include "../s21_containers.h"

namespace stack_tests {

TEST(stack, contructor_1) {
  s21::stack<int> st;
  std::stack<int> s;
  EXPECT_EQ(s.size(), st.size());
}

TEST(stack, contructor_2) {
  s21::stack<int> st = {1, 2, 3};
  EXPECT_EQ(3, st.size());
}

TEST(stack, contructor_3) {
  s21::stack<int> st1 = {1, 2, 3};
  s21::stack<int> st2 = st1;
  std::stack<int> s1;
  s1.push(1);
  s1.push(2);
  s1.push(3);
  std::stack<int> s2 = s1;
  EXPECT_EQ(s1.top(), st1.top());
  EXPECT_EQ(s2.top(), st2.top());
  EXPECT_EQ(st1.size(), st2.size());
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s2.size(), st2.size());
  EXPECT_EQ(s1.size(), st1.size());
}

TEST(stack, top) {
  s21::stack<int> st;
  std::stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  st.push(1);
  st.push(2);
  st.push(3);
  EXPECT_EQ(s.top(), st.top());
}

TEST(stack, empty) {
  s21::stack<int> st;
  std::stack<int> s;
  EXPECT_EQ(s.empty(), st.empty());
  s.push(1);
  s.push(2);
  s.push(3);
  st.push(1);
  st.push(2);
  st.push(3);
  EXPECT_EQ(s.empty(), st.empty());
}

TEST(stack, size) {
  s21::stack<int> st;
  std::stack<int> s;
  EXPECT_EQ(s.size(), st.size());
  s.push(1);
  s.push(2);
  s.push(3);
  st.push(1);
  st.push(2);
  st.push(3);
  EXPECT_EQ(s.size(), st.size());
}

TEST(stack, push) {
  s21::stack<int> st;
  std::stack<int> s;
  s.push(1);
  st.push(1);
  EXPECT_EQ(s.top(), st.top());
  s.push(2);
  st.push(2);
  EXPECT_EQ(s.top(), st.top());
  s.push(3);
  st.push(3);
  EXPECT_EQ(s.top(), st.top());
}

TEST(stack, swap) {
  s21::stack<int> st1;
  std::stack<int> s1;
  s1.push(1);
  s1.push(2);
  s1.push(3);
  st1.push(1);
  st1.push(2);
  st1.push(3);
  s21::stack<int> st2;
  std::stack<int> s2;
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
  EXPECT_EQ(s1.top(), st1.top());
  EXPECT_EQ(s2.top(), st2.top());
}

TEST(List, insert_many_front) {
  s21::stack<int> l = {1, 2, 3};
  l.insert_many_front(4, 5, 6);
  EXPECT_EQ(l.size(), 6);
  EXPECT_EQ(l.top(), 4);
}
}  // namespace stack_tests