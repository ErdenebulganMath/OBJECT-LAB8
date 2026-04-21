#include<bits/stdc++.h>
#include<cmath>
using namespace std; 
 
struct Point{
    float x;
    float y;
} ;   
 
// Shape эх класс - байгуулагч нэмлээ
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

// Shape2D эх класс - параметертэй байгуулагч нэмлээ
class Shape2D : public Shape{
    protected : 
        string name;
    public :
        // Параметертэй байгуулагч - эх классын Shape() дуудна
        Shape2D(string name) : Shape() {
            this->name = name ;
        }

        virtual float talbai() = 0 ;
        virtual float perimetr() = 0 ;

        string getName(){
            return name ; 
        }

        ~Shape2D() override {}

} ; 
 
// Circle
class Circle : public Shape2D{
    protected : 
        Point p1 ; 
        float radius ;  
    public :
        // Shape2D-ийн параметертэй байгуулагчийг дуудаж байна
        Circle(Point p1 , float radius , string name) : Shape2D(name) {
            this->p1 = p1 ; 
            this->radius = radius ; 
        }
        float talbai() override {
            return 3.14 * radius * radius ; 
        }
        float perimetr() override {
            return 2 * 3.14 * radius ; 
        }
        ~Circle() override {}
} ; 
 
// Square
class Square : public Shape2D{
    protected :
        Point p1 , p2 , p3 , p4 ; 
        float tal ; 
    public :
        // Shape2D-ийн параметертэй байгуулагчийг дуудаж байна
        Square(Point topLeft, float length, string name) : Shape2D(name) {
            p1 = topLeft;
            p2 = {topLeft.x + length, topLeft.y};
            p3 = {topLeft.x + length, topLeft.y - length};
            p4 = {topLeft.x, topLeft.y - length};
            tal = length;
        }
        float talbai() override {
            return tal * tal ; 
        }
        float perimetr() override {
            return 4 * tal ; 
        }
        ~Square() override {}
};
 
// Triangle
class Triangle : public Shape2D {
protected:
    Point p1, p2, p3;
    float tal1, tal2, tal3;
public:
    // Shape2D-ийн параметертэй байгуулагчийг дуудаж байна
    Triangle(Point top, float a, string name) : Shape2D(name) {
        p1 = top; 
        float height = sqrt(3)/2 * a;
        p2 = {top.x - a/2, top.y - height}; 
        p3 = {top.x + a/2, top.y - height}; 
    
        tal1 = tal2 = tal3 = a;
    }
    float talbai() override {
        return (sqrt(3)/4) * tal1 * tal1; 
    }
    float perimetr() override {
        return tal1 + tal2 + tal3; 
    }
    ~Triangle() override {}
};
 
void bubbleSort( Shape2D* shapes[] , int n){ 
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
 
int main() {

// Олон объект үүсгэх (vector ашиглахгүй)
int n = 6 ;

// dynamic array үүсгэнэ
Shape2D** shapes = new Shape2D*[n];

shapes[0] = new Circle({0,0}, 5, "Circle1");
shapes[1] = new Square({0,10}, 4, "Square1");
shapes[2] = new Triangle({0,10}, 6, "Triangle1");
shapes[3] = new Circle({1,1}, 3, "Circle2");
shapes[4] = new Square({2,8}, 2, "Square2");
shapes[5] = new Triangle({2,5}, 4, "Triangle2");

bubbleSort(shapes, n) ;

// ===== Хэвлэх =====
cout << "=== Sorted by area ===\n\n";

for(int i = 0; i < n; i++){
    cout << shapes[i]->getName() << endl;
    cout << "Talbai: " << shapes[i]->talbai() << endl;
    cout << "Perimetr: " << shapes[i]->perimetr() << endl;
    cout << "------------------" << endl;
}


// ===== Memory цэвэрлэх =====
for(int i = 0; i < n; i++){
    delete shapes[i];
}

delete[] shapes;


}