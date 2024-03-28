#include <iostream>
#include <string>

#define SIZE 100
 
using namespace std;

template <class T> class Stack {
    // Public access modifier
public:
    // Empty constructor
    Stack() { top = -1; };
 
    void push(T k);
    T pop();
    T topElement();
    bool isFull();
    bool isEmpty();
 
private:
    int top;
    T st[SIZE];
};
