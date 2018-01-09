#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <iostream>
#include "catch.hpp"
#include "fakeit.hpp"
#include "Arduino.h"
#include "main.ino"

using namespace fakeit;

TEST_CASE( "Serial class tests", "[Serial]" ) 
{
    When(Method(mock_serial,print)).AlwaysReturn();
    When(Method(mock_serial,println)).AlwaysReturn();
    Serial.println("testing println");
    Serial.print("testing print");
    Verify(Method(mock_serial, println).Using("testing println")).Once();
    Verify(Method(mock_serial, print).Using("testing print")).Once();

}

TEST_CASE( "Analog read write tests", "[Analog]" ) 
{
    When(Method(mock_analog, analogRead)).Return(100);
    REQUIRE(analogRead(0) == 100);
    Verify(Method(mock_analog, analogRead).Using(0)).Once();

    When(Method(mock_analog, analogWrite)).Return();
    analogWrite(10, 20);
    Verify(Method(mock_analog, analogWrite).Using(10, 20)).Once();
}

SCENARIO ("Mock Serial can be used in the arduino sketch") {
    GIVEN("An arduino sketch which includes Arduino.h") {
        WHEN("The mock tests are run") {
            When(Method(mock_serial,print)).AlwaysReturn();
            When(Method(mock_serial,println)).AlwaysReturn();
            THEN("The arduino sketch can be run locally using the mock Arduino.h")
            loop(); // Loop from main.ino
            // TODO Verify methods have been called
        }
    }
}
