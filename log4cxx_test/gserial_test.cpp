#include <gtest/gtest.h>
#include "gserial.h"
#include <iostream>
#include "sleep.h"

using ::testing::_;
using ::testing::Return;
using ::testing::InSequence;

TEST(GSerialTest, ReadReturnsAlphabet) {
    MockGSerial mockSerial;

    // Set expectations for the read method to return the alphabet
    InSequence sequence;
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        EXPECT_CALL(mockSerial, read())
            .WillOnce(Return(ch));
    }

    // Now you can use the mockSerial object in your code and expect it to return the alphabet
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        char result = mockSerial.read();
        EXPECT_EQ(result, ch);
    }
}


TEST(GSerialTest, Foo) {
  for(int i = 0; i < 10 ; i ++ ) {
    Geodetics::GeoSleep(1);
  }
  EXPECT_EQ(1,1);
}


TEST(ABC, TEST2) {
    ASSERT_TRUE(2 == 2);
}

#ifdef WIN32
int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif
