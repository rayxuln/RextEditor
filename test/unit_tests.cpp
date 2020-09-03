//
// Created by Raymond_Lx on 2020/9/3.
//

#include <iostream>

#include "gtest/gtest.h"

int main(int arcc, char **arcv)
{
    testing::InitGoogleTest(&arcc, arcv);
    return RUN_ALL_TESTS();
}

TEST(pre_test, test_for_test1)
{
    EXPECT_FALSE(false);
}

TEST(pre_test, test_for_test2)
{
    ASSERT_EQ(1, 1);
}