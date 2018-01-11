#ifndef Arduino_H
#define Arduino_H
#include "fakeit.hpp"
#include "catch.hpp"
#include "mocks.h"
#include <string>
using namespace fakeit;

/**
 * Global functions analogRead and analogWrite
 */
int analogRead(int value);
void analogWrite(int pin, int value);

/**
 * Arduino requires global access to the mock objects
 */
extern fakeit::Mock<MockSerial> mock_serial;
extern fakeit::Mock<MockAnalog> mock_analog;
extern MockSerial& Serial;

#endif /* ifndef Arduino_H */
