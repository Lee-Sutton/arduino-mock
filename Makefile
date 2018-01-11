test: mock_tests
	./mock_tests

mock_tests: test.cpp Arduino.h Arduino.cpp catch.hpp fakeit.hpp main.ino
	g++ -std=c++11 test.cpp Arduino.cpp -o mock_tests -I .

clean:
	rm mock_tests
