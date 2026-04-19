#include <iostream>
using namespace std ;

class Shape {
public:
    virtual void draw() {
        cout << "Drawing Shape\n" ;
    }
} ;

class Circle : public Shape {
public :
    void draw() {
        cout << "Drawing Circle\n" ;
    }
} ;

class Rectangle : public Shape {
public :
    void draw() {
        cout << "Drawing Rectangle\n" ;
    }
} ;

int main() {
    Shape* s ;

    Circle c ;
    Rectangle r ;

    s = &c ;
    s->draw() ;   // Circle

    s = &r ;
    s->draw() ;   // Rectangle

    return 0 ;
}