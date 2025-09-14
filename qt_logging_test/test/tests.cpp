#include <gtest/gtest.h>
#include "sleep.h"

// using ::testing::_;
// using ::testing::Return;
using ::testing::InSequence;

TEST(ABC, TEST1) {
    EXPECT_EQ(true, true);
}

TEST(ABC, TEST2) {
    ASSERT_TRUE(2 == 2);
}

TEST(ABC,Sleep) {
  EXPECT_EQ(1,1);
  std::cout << "Foo\n";
  Geodetics::GeoSleep(3);
  std::cout << "Bar\n";
}
