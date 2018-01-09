#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <iostream>
#include "catch.hpp"
#include "fakeit.hpp"
#include "Arduino.h"
#include "main.ino"

using namespace fakeit;

TEST_CASE( "Loop tests", "[loop]" ) 
{
    When(Method(mock_serial,print)).AlwaysReturn();
    When(Method(mock_serial,println)).AlwaysReturn();
    Serial.println("testing");
}
