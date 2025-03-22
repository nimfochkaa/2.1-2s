#include "Product.h"

int main() {
    Product p1;              
    Product p2(200, 2.5);    
    Product p3 = p2;          

    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "p3 (copy of p2): " << p3 << endl;

    Product p4;
    cin >> p4;
    cout << "Entered product: " << p4 << endl;
    return 0;
}