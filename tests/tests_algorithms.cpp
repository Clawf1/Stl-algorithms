#include "../src/algorithms/include/algorithms/algorithms.h"
#include <gtest/gtest.h>
#include <vector>
#include <forward_list>


TEST(All_of, True_Test) {
    std::forward_list list = {1, 2, 3, 4, 5, 6};
    ASSERT_TRUE(all_of(list.begin(), list.end(), [](int x) { return x > 0; }));
}

TEST(All_of, False_Test) {
    std::forward_list list = {1, 2, 3, 4, 5, 6};
    ASSERT_FALSE(all_of(list.begin(), list.end(), [](int x) { return x == 0; }));
}


TEST(Any_of, True_Test) {
    std::forward_list list = {1, 2, 3, 4, 5, 6};
    ASSERT_TRUE(any_of(list.begin(), list.end(), [](int x) { return x == 1; }));
}

TEST(Any_of, False_Test) {
    std::forward_list list = {1, 2, 3, 4, 5, 6};
    ASSERT_FALSE(any_of(list.begin(), list.end(), [](int x) { return x == 0; }));
}


TEST(None_of, True_Test) {
    std::forward_list list = {1, 2, 3, 4, 5, 6};
    ASSERT_TRUE(none_of(list.begin(), list.end(), [](int x) { return x == 10; }));
}

TEST(None_of, False_Test) {
    std::forward_list list = {1, 2, 3, 4, 5, 6};
    ASSERT_FALSE(none_of(list.begin(), list.end(), [](int x) { return x == 6; }));
}


TEST(One_of, True_Test) {
    std::forward_list list = {1, 3, 5, 6};
    ASSERT_TRUE(one_of(list.begin(), list.end(), [](int x) { return x == 5; }));
}

TEST(One_of, False_Test) {
    std::forward_list list = {1, 2, 3, 1};
    ASSERT_FALSE(one_of(list.begin(), list.end(), [](int x) { return x == 1; }));
    ASSERT_FALSE(one_of(list.begin(), list.end(), [](int x) { return x == 5; }));
}


TEST(Find_not, True_Test) {
    std::forward_list list = {0, 0, 0, 2, 3};
    int a = 0;
    auto it = find_not(list.begin(), list.end(), a);
    auto eq = list.begin();
    for (int i = 0; i < 3; ++i) eq++;
    ASSERT_EQ(it, eq);
}

TEST(Find_not, False_Test) {
    std::forward_list list = {0, 0, 0, 0, 0};
    int a = 0;
    auto it = find_not(list.begin(), list.end(), a);
    auto eq = list.begin();
    ASSERT_FALSE(it == eq);
}


TEST(Find_backward, True_Test) {
    std::forward_list list = {1, 2, 3, 1, 2};
    int a = 1;
    auto it = find_backward(list.begin(), list.end(), a);
    auto eq = list.begin();
    for (int i = 0; i < 3; ++i) eq++;
    ASSERT_EQ(it, eq);
}

TEST(Find_backward, False_Test) {
    std::forward_list list = {1, 2, 3, 1, 2};
    int a = 1;
    auto it = find_backward(list.begin(), list.end(), a);
    auto eq = list.begin();
    ASSERT_FALSE(it == eq);
}


TEST(Is_sorted, True_Test) {
    std::forward_list list = {1, 2, 3, 4, 5, 6};
    ASSERT_TRUE(is_sorted(list.begin(), list.end(), [](int a, int b) { return a < b; }));
}

TEST(Is_sorted, False_Test) {
    std::forward_list list = {1, 5, 3, 4};
    ASSERT_FALSE(is_sorted(list.begin(), list.end(), [](int a, int b) { return a < b; }));
}


TEST(Is_partitioned, True_Test) {
    std::forward_list list = {1, 2, 3, 4, 5, 6, -1, -2};
    ASSERT_TRUE(is_partitioned(list.begin(), list.end(), [](int a) { return a < 0; }));
}

TEST(Is_partitioned, False_Test) {
    std::forward_list list = {-1, 1, 5, 3, 4, -3};
    ASSERT_FALSE(is_partitioned(list.begin(), list.end(), [](int a) { return a < 0; }));
}


TEST(Is_palindrom, True_Test) {
    std::list list1 = {1, 2, 3, 2, 1};
    std::list list2 = {1, 2, 2, 1};
    ASSERT_TRUE(is_palindrome(list1.begin(), list1.end()));
    ASSERT_TRUE(is_palindrome(list2.begin(), list2.end()));
}

TEST(Is_palindrom, False_Test) {
    std::list list = {1, 2, 3, 1, 2};
    ASSERT_FALSE(is_palindrome(list.begin(), list.end()));
}


TEST(XRange, CharTest) {
    std::vector ans = {'a', 'b', 'c', 'd'};
    auto x = xrange('a', 'e');
    std::vector<char> res{x.begin(), x.end()};
    ASSERT_TRUE(ans == res);
}

TEST(XRange, FloatTest) {
    std::vector<float> ans = {1.0, 1.5, 2.0, 2.5};
    auto x = xrange(1.0, 3.0, 0.5);
    std::vector<float> res{x.begin(), x.end()};
    ASSERT_TRUE(ans == res);
}

TEST(Zip, Different_type_zip) {
    std::vector<int> num = {1, 2, 3};
    std::list<std::string> str = {"zxc", "gg", "fxx"};
    std::vector<std::pair<int, std::string>> ans = {{1, "zxc"}, {2, "gg"}, {3, "fxx"}};
    std::vector<std::pair<int, std::string>> res;
    for(auto p : zip(num, str))
        res.push_back(p);
    ASSERT_TRUE(ans == res);
}

TEST(Zip, Different_type_size) {
    std::vector<int> num = {1, 2, 3, 4, 5};
    std::list<std::string> str = {"zxc", "gg", "fxx"};
    std::vector<std::pair<int, std::string>> ans = {{1, "zxc"}, {2, "gg"}, {3, "fxx"}};
    std::vector<std::pair<int, std::string>> res;
    for(auto p : zip(num, str))
        res.push_back(p);
    ASSERT_TRUE(ans == res);
}
