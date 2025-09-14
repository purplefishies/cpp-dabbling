#include <gmock/gmock.h>

class GSerial {
public:
    virtual ~GSerial() {}

    virtual char read() = 0;
};

class MockGSerial : public GSerial {
public:
    MOCK_METHOD(char, read, (), (override));
};


