#include <iostream>
using namespace std ;

class Math {
public:
    // int хувилбар
    int add(int a , int b) {
        cout << "Integer add ажиллаж байна\n" ;
        return a + b ;
    }

    // double хувилбар
    double add(double a , double b) {
        cout << "Double add ажиллаж байна\n" ;
        return a + b ;
    }
};

int main() {
    Math m;

    cout << m.add(2 , 3) << endl ;       // int функц
    cout << m.add(2.5 , 3.5) << endl ;   // double функц

    return 0 ;
}