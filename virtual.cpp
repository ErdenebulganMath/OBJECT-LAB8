#include<bits/stdc++.h>
using namespace std;

class Animal {
    public :
        virtual void sound() = 0 ;
} ; 

class Dog : public Animal {
    public :
        void sound() override {
            cout << "Dog is barking" << endl ;
        }
} ; 

class Lion : public Animal {
    public :
        void sound() override {
            cout << "Lion is roaring" << endl ;
        }
} ; 

class Bird : public Animal {
    public :
        void sound() override {
            cout << "Bird is chirping" << endl ;
        }
} ;

class Cat : public Animal {
    public :
        void sound() override {
            cout << "Cat is meowing" << endl ;
        }
} ;