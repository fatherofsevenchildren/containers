#include <gtest/gtest.h>
#include "s21_vector.hpp"
#include <vector>
#include <iterator>

using namespace std;

TEST(Vectors, Constructors) {
  s21_vector<int> test;
  EXPECT_EQ(test.size(), 0);
}

TEST(Vectors, Constructors_size) {
  s21_vector<int> test(2);
  // test[1] = 5;
//   EXPECT_EQ(test.size(), 5);
//   EXPECT_EQ(test.capacity(), 5);
  EXPECT_EQ(test[1], 0);
  EXPECT_EQ(test[0], 0);
}

TEST(Vectors, Constructors_move) {
  s21_vector<int> test(2);
  test[1] = 5;
  s21_vector<int> test2(std::move(test));
  EXPECT_EQ(test.size(), 0);
  EXPECT_EQ(test.capacity(), 0);
//   EXPECT_EQ(test[1], 0);
  EXPECT_EQ(test2[1], 5);
}


TEST(Vectors, Constructors_copy) {
  s21_vector<int> test(7);
  test[3] = 5;
  test.push_back(3);
  EXPECT_EQ(test[3], 5);
  test.pop_back();
  s21_vector<int> test2(test);
  EXPECT_EQ(test2.size(), 7);
  EXPECT_EQ(test2.capacity(), 7);
}


TEST(Vectors, at) {
  s21_vector<int> test(2);
  test[1] = 5;
  EXPECT_EQ(test.at(1), 5);
}

TEST(Vectors, front_back) {
  s21_vector<int> test = {1,2};
  EXPECT_EQ(test.front(), 1);
  EXPECT_EQ(test.back(), 2);
}

TEST(Vectors, data) {
  s21_vector<int> test = {1,2};
  int* test_data = test.data();
  *test_data = 3;
  EXPECT_EQ(test.front(), 3);
}

TEST(Vectors, empty) {
  s21_vector<int> test1 = {1,2};
  s21_vector<int> test2;
  EXPECT_TRUE(test2.empty());
  EXPECT_FALSE(test1.empty());
}

TEST(Vectors, max_size) {
  s21_vector<int> test1;
  EXPECT_EQ(test1.max_size(),4611686018427387903);
}

TEST(Vectors, reserve) {
  s21_vector<int> test1 = {1,2,3};
  test1.reserve(10);
  EXPECT_EQ(test1.capacity(),10);
  EXPECT_EQ(test1[2],3);
  EXPECT_EQ(test1[5],0);
}

TEST(Vectors, shrink) {
  s21_vector<int> test1 = {1,2,3};
  test1.reserve(10);
  test1.shrink_to_fit();
  EXPECT_EQ(test1.capacity(), test1.size());
}

//--------iter----------------

TEST(Vectors, iter1) {
  s21_vector<int> test1 = {1,2,3};
  s21_vector<int>::iterator it1 = test1.begin();
  EXPECT_EQ(*it1, 1);
}

TEST(Vectors, iter_plus) {
  s21_vector<int> test1 = {1,2,3};
  s21_vector<int>::iterator it1 = test1.begin();
  EXPECT_EQ(*++it1, 2);
}

TEST(Vectors, iter_plus_plus) {
  s21_vector<int> test1 = {1,2,3};
  s21_vector<int>::iterator it1 = test1.begin();  
  EXPECT_EQ(*++++it1, 3);
}

TEST(Vectors, iter_minus) {
  s21_vector<int> test1 = {1,2,3};
  s21_vector<int>::iterator it1 = test1.end();  
  EXPECT_EQ(*--it1, 2);
}

TEST(Vectors, iter_postfix) {
  s21_vector<int> test1 = {1,2,3};
  s21_vector<int>::iterator it1 = test1.begin();  
  EXPECT_EQ(*it1++, 1);
  EXPECT_EQ(*it1, 2);
}

TEST(Vectors, iter_postfix_minus) {
  s21_vector<int> test1 = {1,2,3};
  s21_vector<int>::iterator it1 = test1.end();  
  EXPECT_EQ(*it1--, 3);
  EXPECT_EQ(*it1, 2);
}

//--------const iter----------------

TEST(Vectors, const_iter1) {
  s21_vector<int> test1 = {1,2,3};
  s21_vector<int>::const_iterator it1 = test1.cbegin();
  EXPECT_EQ(*it1, 1);
}

TEST(Vectors, const_iter_plus) {
  s21_vector<int> test1 = {1,2,3};
  s21_vector<int>::const_iterator it1 = test1.cbegin();
  EXPECT_EQ(*++it1, 2);
}

TEST(Vectors, const_iter_plus_plus) {
  s21_vector<int> test1 = {1,2,3};
  s21_vector<int>::const_iterator it1 = test1.cbegin();  
  EXPECT_EQ(*++++it1, 3);
}

TEST(Vectors, const_iter_minus) {
  s21_vector<int> test1 = {1,2,3};
  s21_vector<int>::const_iterator it1 = test1.cend();  
  EXPECT_EQ(*--it1, 2);
}

TEST(Vectors, const_iter_postfix) {
  s21_vector<int> test1 = {1,2,3};
  s21_vector<int>::const_iterator it1 = test1.cbegin();  
  EXPECT_EQ(*it1++, 1);
  EXPECT_EQ(*it1, 2);
}

TEST(Vectors, const_iter_postfix_minus) {
  s21_vector<int> test1 = {1,2,3};
  s21_vector<int>::const_iterator it1 = test1.cend();  
  EXPECT_EQ(*it1--, 3);
  EXPECT_EQ(*it1, 2);
}

TEST(Vectors, clear) {
  s21_vector<int> test1 = {1,2,3};
  test1.clear();  
  EXPECT_EQ(test1.capacity(), 3);
  EXPECT_EQ(test1.size(), 0);
}

TEST(Vectors, insert) {
  s21_vector<int> test1 = {1,2,3,4,5};
  s21_vector<int>::iterator it = test1.begin();
  it++;
    it = test1.insert(it,5);
  EXPECT_EQ(test1.capacity(), 10);
  EXPECT_EQ(test1.size(), 6);
  EXPECT_EQ(test1[1], 5);
}

TEST(Vectors, erase) {
  s21_vector<int> test1 = {1,2,3,4,5};
  s21_vector<int>::iterator it = test1.begin();
  it++;
  test1.erase(it);
  EXPECT_EQ(test1.capacity(), 5);
  EXPECT_EQ(test1.size(), 4);
  EXPECT_EQ(test1[1], 3);
  EXPECT_EQ(test1[0], 1);
  EXPECT_EQ(*it, 3);
}


TEST(Vectors, push_back) {
  s21_vector<int> test1 = {1,2,3,4,5};
  test1.push_back(6);
  EXPECT_EQ(test1.capacity(), 10);
  EXPECT_EQ(test1.size(), 6);
  EXPECT_EQ(test1[5], 6);
}

TEST(Vectors, insert_many_back) {
  s21_vector<int> test1 = {1,2};
  test1.insert_many_back(3,3,3);
  EXPECT_EQ(test1.capacity(), 8);
  EXPECT_EQ(test1.size(), 5);
  EXPECT_EQ(test1[0], 1);
  EXPECT_EQ(test1[1], 2);
  EXPECT_EQ(test1[2], 3);
  EXPECT_EQ(test1[3], 3);
  EXPECT_EQ(test1[4], 3);
}




int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

// using namespace std;

// int main() {
//     s21_vector<int> test1 = {1,4};
//     // test1.push_back(4);
//     test1.push_back(4);
//     cout <<  endl;
//     // s21_vector<int>::
//     test1.pop_back();
//     s21_vector<int>::iterator it = test1.begin();
//     it++;
//     test1.insert_many(it, 2,2,2);
//     for (int i = 0; i < test1.size(); i++) {
//       cout << test1[i];
//     }
//     cout <<  endl;
//     cout << test1.capacity() << endl;
//     cout << test1.size() << endl;
//     // cout << *it;
//     return 0;
// }


// при конструкторе копирования капасити будет равен сайзу а не капасити