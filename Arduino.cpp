#include "Arduino.h"
#include "mocks.h"

fakeit::Mock<MockSerial> mock_serial;
MockSerial& Serial = mock_serial.get();
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

