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

struct MockAnalog
{
    virtual int analogRead(int) = 0;
    virtual void analogWrite(int, int) = 0;
};


#endif /* ifndef MOCKS_H */
