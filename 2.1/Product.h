#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

using namespace std;

class Product {
private:
    int first;
    double second;

public:
    Product();
    Product(int calories, double weight);
    Product(const Product& other);

    Product& operator=(const Product& other);

    Product& operator++();
    Product operator++(int);
    Product& operator--();
    Product operator--(int);

    friend istream& operator>>(istream& in, Product& p);
    friend ostream& operator<<(ostream& out, const Product& p);

    operator string() const;

    double power() const;

    static void printSize();
};

#endif 