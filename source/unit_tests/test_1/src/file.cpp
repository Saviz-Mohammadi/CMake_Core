#include <file.hpp>
#include <gtest/gtest.h>
#include <iostream>

// Example function to test
int add(int a, int b) {
    return a + b;
}

// Test case for the add function
TEST(AddTest, PositiveNumbers) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(10, 5), 15);
}

TEST(AddTest, NegativeNumbers) {
    EXPECT_EQ(add(-2, -3), -5);
    EXPECT_EQ(add(-10, -5), -15);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
