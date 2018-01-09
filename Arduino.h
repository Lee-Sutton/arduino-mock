#ifndef Arduino_H
#define Arduino_H
#include "fakeit.hpp"
#include "catch.hpp"
#include <string>
using namespace fakeit;

struct MockSerial
{
    virtual void print(std::string) = 0;
    virtual void println(std::string) = 0;
};

fakeit::Mock<MockSerial> mock_serial;
MockSerial& Serial = mock_serial.get();
#endif /* ifndef Arduino_H */
