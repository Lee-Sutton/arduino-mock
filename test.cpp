#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <iostream>
#include <string>
#include "catch.hpp"
#include "fakeit.hpp"
#include "Arduino.h"
#include "mocks.h"
#include "main.ino"

using namespace fakeit;

TEST_CASE( "Serial class tests", "[Serial]" ) {
    When(Method(mock_serial, begin)).Return();
    Serial.begin(9600);
    Verify(Method(mock_serial, begin).Using(9600)).Once();
    When(OverloadedMethod(mock_serial, print, void(std::string))).AlwaysReturn();
    When(OverloadedMethod(mock_serial, print, void(double, int))).AlwaysReturn();
    When(OverloadedMethod(mock_serial, println, void(std::string))).AlwaysReturn();
    When(OverloadedMethod(mock_serial, println, void(double, int))).AlwaysReturn();
    Serial.print("testing print");
    Serial.print(1.0, 6);
    Serial.println("testing println");
    Serial.println(2.0, 5);
    Verify(OverloadedMethod(mock_serial, print, void(std::string)).Using("testing print")).Once();
    Verify(OverloadedMethod(mock_serial, print, void(double, int)).Using(1.0, 6)).Once();
    Verify(OverloadedMethod(mock_serial, println, void(std::string)).Using("testing println")).Once();
    Verify(OverloadedMethod(mock_serial, println, void(double, int)).Using(2.0, 5)).Once();

}

TEST_CASE( "Analog read write tests", "[Analog]" ) {
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
            When(OverloadedMethod(mock_serial, print, void(std::string))).AlwaysReturn();
            When(OverloadedMethod(mock_serial, println, void(std::string))).AlwaysReturn();
            THEN("The arduino sketch can be run locally using the mock Arduino.h")
            loop(); // Loop from main.ino
        }
    }
}
