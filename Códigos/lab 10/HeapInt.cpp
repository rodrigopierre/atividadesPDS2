#include "HeapInt.hpp"

HeapInt::HeapInt() {
    value = new int(0);
}

bool HeapInt::operator==(const HeapInt& other) const {
    return *value == *other.value;
}

HeapInt::HeapInt(int val) {
    value = new int(val);
}

HeapInt::HeapInt(const HeapInt& other) {
    value = new int(*other.value);
}

HeapInt::~HeapInt() {
    delete value;
}

HeapInt& HeapInt::operator=(int val) {
    *value = val;
    return *this;
}

HeapInt& HeapInt::operator=(const HeapInt& other) {
    if (this != &other) {
        *value = *other.value;
    }
    return *this;
}

HeapInt HeapInt::operator+(const HeapInt& other) const {
    return HeapInt(*value + *other.value);
}

std::ostream& operator<<(std::ostream& out, const HeapInt& obj) {
    out << *obj.value;
    return out;
}

HeapInt HeapInt::operator-(const HeapInt& other) const {
    return HeapInt(*value - *other.value);
}

std::istream& operator>>(std::istream& in, HeapInt& obj) {
    in >> *obj.value;
    return in;
}

