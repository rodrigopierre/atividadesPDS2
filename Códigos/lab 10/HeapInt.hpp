#ifndef HEAPINT_HPP
#define HEAPINT_HPP
#include <iostream>

class HeapInt {
private:
    int* value;

public:
    HeapInt();
    HeapInt(int val);
    HeapInt(const HeapInt& other);
    ~HeapInt();
    HeapInt& operator=(int val);
    HeapInt& operator=(const HeapInt& other);
    HeapInt operator+(const HeapInt& other) const;
    HeapInt operator-(const HeapInt& other) const;
    bool operator==(const HeapInt& other) const;
    friend std::istream& operator>>(std::istream& in, HeapInt& obj);
    friend std::ostream& operator<<(std::ostream& out, const HeapInt& obj);
};
#endif
