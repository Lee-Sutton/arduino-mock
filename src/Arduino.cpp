#include "Arduino.h"
#include "mocks.h"

fakeit::Mock<MockSerial> mock_serial;
MockSerial& Serial = mock_serial.get();
fakeit::Mock<MockAnalog> mock_analog;
fakeit::Mock<MockMillis> mock_millis;

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

int millis()
{
    MockMillis& mock_millis_ref = mock_millis.get();
    return mock_millis_ref.millis();
}

