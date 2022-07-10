#include "../structure.hpp"
#include "gtest/gtest.h"

TEST(BaseTest, contain_test)
{
    EXPECT_EQ(contain({12, 15}, 12), true);
    EXPECT_EQ(contain({12, 15}, 15), true);
    EXPECT_EQ(contain({12, 15}, 11), true);
}

TEST(baseTest, colided_test)
{
    EXPECT_EQ(isColided(12, 12, 10, 10), true);
    EXPECT_EQ(isColided(12, 12, 12, 11), true);
    EXPECT_EQ(isColided(12, 12, 15, 15), true);
    EXPECT_EQ(isColided(12, 12, 0, 0)  , false);
    EXPECT_EQ(isColided(12, 12, 50, 12), false);
}

// int main(int argc, char* argv[])
// {
//     ::testing::InitGoogleTest(&argc,argv);
//     RUN_ALL_TESTS();
// }