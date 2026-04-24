#include<bits/stdc++.h>
#include<cmath>
using namespace std;

struct Point{
    float x;
    float y;
} ;

class Shape{
    protected :
        static int counter ;
    public :
        Shape(){
            counter++ ;
        }

        virtual ~Shape(){
            counter-- ;
        }

        static int getCounter(){
            return counter ;
        }

        static void setCounter(int c){
            counter = c ;
        }
} ;

int Shape::counter = 0 ;

class Shape2D : public Shape{
    protected :
        string name;
    public :
        Shape2D(string name) : Shape() {
            this->name = name ;
        }

        virtual float talbai() = 0 ;
        virtual float perimetr() = 0 ;

        string getName(){
            return this->name ;
        }

        ~Shape2D() override {}
} ;

class Circle : public Shape2D{
    protected :
        Point p1 ;
        float radius ;
    public :
        Circle(Point p1 , float radius , string name) : Shape2D(name) {
            this->p1 = p1 ;
            this->radius = radius ;
        }
        float talbai() override {
            return 3.14f * this->radius * this->radius ;
        }
        float perimetr() override {
            return 2 * 3.14f * this->radius ;
        }
        ~Circle() override {}
} ;

class Square : public Shape2D{
    protected :
        Point p1 , p2 , p3 , p4 ;
        float tal ;
    public :
        Square(Point topLeft, float length, string name) : Shape2D(name) {
            this->p1 = topLeft;
            this->p2 = {topLeft.x + length, topLeft.y};
            this->p3 = {topLeft.x + length, topLeft.y - length};
            this->p4 = {topLeft.x, topLeft.y - length};
            this->tal = length;
        }
        float talbai() override {
            return this->tal * this->tal ;
        }
        float perimetr() override {
            return 4 * this->tal ;
        }
        ~Square() override {}
};

class Triangle : public Shape2D {
protected:
    Point p1, p2, p3;
    float tal1, tal2, tal3;
public:
    Triangle(Point top, float a, string name) : Shape2D(name) {
        this->p1 = top;
        float height = sqrt(3)/2 * a;
        this->p2 = {top.x - a/2, top.y - height};
        this->p3 = {top.x + a/2, top.y - height};
        this->tal1 = this->tal2 = this->tal3 = a;
    }
    float talbai() override {
        return (sqrt(3.0f)/4) * this->tal1 * this->tal1;
    }
    float perimetr() override {
        return this->tal1 + this->tal2 + this->tal3;
    }
    ~Triangle() override {}
};

void sortByTalbai(Shape2D* shapes[], int n){
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(shapes[j]->talbai() > shapes[j+1]->talbai()) {
                Shape2D* temp = shapes[j];
                shapes[j] = shapes[j+1];
                shapes[j+1] = temp ;
            }
        }
    }
}

void sortByPerimetr(Shape2D* shapes[], int n){
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(shapes[j]->perimetr() > shapes[j+1]->perimetr()) {
                Shape2D* temp = shapes[j];
                shapes[j] = shapes[j+1];
                shapes[j+1] = temp ;
            }
        }
    }
}

void printShapes(Shape2D* shapes[], int n){
    for(int i = 0; i < n; i++){
        cout << i+1 << ". " << shapes[i]->getName() << endl;
        cout << "   Talbai   : " << fixed << setprecision(2) << shapes[i]->talbai() << endl;
        cout << "   Perimetr : " << fixed << setprecision(2) << shapes[i]->perimetr() << endl;
        cout << "------------------" << endl;
    }
}

int main() {

    cout << "======================================" << endl;
    cout << "Объект үүсгэхийн өмнөх тоо: " << Shape::getCounter() << endl;
    cout << "======================================\n" << endl;

    int n = 6 ;
    Shape2D** shapes = new Shape2D*[n];

    shapes[0] = new Circle({0,0}, 5, "Circle1");
    shapes[1] = new Square({0,10}, 4, "Square1");
    shapes[2] = new Triangle({0,10}, 6, "Triangle1");
    shapes[3] = new Circle({1,1}, 3, "Circle2");
    shapes[4] = new Square({2,8}, 2, "Square2");
    shapes[5] = new Triangle({2,5}, 4, "Triangle2");

    cout << "Нийт үүссэн объектийн тоо (static counter): " << Shape::getCounter() << "\n" << endl;

    // ===== Талбайгаар эрэмбэлж хэвлэх =====
    sortByTalbai(shapes, n) ;
    cout << "======================================" << endl;
    cout << "=== Талбайгаар эрэмбэлсэн (өсөх дараалал) ===" << endl;
    cout << "======================================" << endl;
    printShapes(shapes, n);

    // ===== Периметрээр эрэмбэлж хэвлэх =====
    sortByPerimetr(shapes, n) ;
    cout << "\n======================================" << endl;
    cout << "=== Периметрээр эрэмбэлсэн (өсөх дараалал) ===" << endl;
    cout << "======================================" << endl;
    printShapes(shapes, n);

    // ===== Memory цэвэрлэх =====
    for(int i = 0; i < n; i++){
        delete shapes[i];
    }
    delete[] shapes;

    cout << "\nОбъект устгасны дараах тоо (static counter): " << Shape::getCounter() << endl;

    return 0;
}
