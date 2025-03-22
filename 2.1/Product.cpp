#include "Product.h"
#include <sstream>

Product::Product() : first(100), second(1.0) {}

Product::Product(int calories, double weight) : first(calories), second(weight) {
    if (calories < 0 || weight < 0) {
        cerr << "Error: Calories and weight must be positive!\n";
        first = 100;
        second = 1.0;
    }
}

Product::Product(const Product& other) : first(other.first), second(other.second) {}

Product& Product::operator=(const Product& other) {
    if (this != &other) {
        first = other.first;
        second = other.second;
    }
    return *this;
}

Product& Product::operator++() {
    first += 10;
    return *this;
}

Product Product::operator++(int) {
    Product temp = *this;
    second += 0.1;
    return temp;
}

Product& Product::operator--() {
    if (first > 10) first -= 10;
    return *this;
}

Product Product::operator--(int) {
    Product temp = *this;
    if (second > 0.1) second -= 0.1;
    return temp;
}

istream& operator>>(istream& in, Product& p) {
    cout << "Enter calories per 100g: ";
    in >> p.first;
    cout << "Enter product weight (kg): ";
    in >> p.second;
    if (p.first < 0 || p.second < 0) {
        cerr << "Error: Values must be positive!\n";
        p.first = 100;
        p.second = 1.0;
    }
    return in;
}

ostream& operator<<(ostream& out, const Product& p) {
    out << "Calories per 100g: " << p.first
        << ", Weight (kg): " << p.second
        << ", Total Calories: " << p.power();
    return out;
}

Product::operator string() const {
    ostringstream oss;
    oss << "Calories per 100g: " << first
        << ", Weight (kg): " << second
        << ", Total Calories: " << power();
    return oss.str();
}

double Product::power() const {
    return first * (second * 10);
}

void Product::printSize() {
    cout << "Class Product size (without #pragma pack(1)): " << sizeof(Product) << " bytes\n";
}