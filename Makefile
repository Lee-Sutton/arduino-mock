test: mock_tests
	./bin/mock_tests

mock_tests: src/*.cpp include/*.h test/*.cpp test/*.ino
	g++ -std=c++11 test/test.cpp src/Arduino.cpp -o bin/mock_tests -I ./include/

clean:
	rm bin/mock_tests
