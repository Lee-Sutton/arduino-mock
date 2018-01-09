#ifndef Arduino_H
#define Arduino_H
#include "fakeit.hpp"
#include "catch.hpp"
#include <string>
using namespace fakeit;

/**
 * @brief Creates a mock of the Serial class available on the arduino
 */
struct MockSerial
{
    virtual void print(std::string) = 0;
    virtual void println(std::string) = 0;
};

struct MockAnalog
{
    virtual int analogRead(int) = 0;
    virtual void analogWrite(int, int) = 0;
};

/**
 * Arduino requires global access to the mock objects
 */
fakeit::Mock<MockSerial> mock_serial;
MockSerial& Serial = mock_serial.get();

/**
 * Global functions analogRead and analogWrite
 */
fakeit::Mock<MockAnalog> mock_analog;

int analogRead(int value)
{
    MockAnalog& analog = mock_analog.get();
    return analog.analogRead(value);
}


void analogWrite(int pin, int value)
{
    MockAnalog& analog = mock_analog.get();
    return analog.analogWrite(pin, value);
}

#endif /* ifndef Arduino_H */
