mock_tests: test.cpp Arduino.h catch.hpp fakeit.hpp main.ino
	g++ -std=c++11 test.cpp -o mock_tests -I /Users/Lee/Projects/arduino-mock/

clean:
	rm mock_tests

test: mock_tests
	./mock_tests
