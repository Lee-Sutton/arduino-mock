#ifndef MOCKS_H
#define MOCKS_H
#include <string>
/**
 * @brief Creates a mock of the Serial class available on the arduino
 */
struct MockSerial
{
    virtual void begin(int) = 0;
    virtual void print(std::string) = 0;
    virtual void print(double, int) = 0;
    virtual void println(std::string) = 0;
    virtual void println(double, int) = 0;
};

/**
 * @brief MockAnalog class can be used to mock the Arduino analogRead and analogWrite
 * functions. 
 */
struct MockAnalog
{
    virtual int analogRead(int) = 0;
    virtual void analogWrite(int, int) = 0;
};

/**
 * @brief MockMillis class can be used to mock the Arduino millis function
 */
struct MockMillis
{
    virtual int millis() = 0;
};


#endif /* ifndef MOCKS_H */
