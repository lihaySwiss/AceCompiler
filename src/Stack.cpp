#include "../headers/Stack.hpp" 

// To add element element k to stack
template <class T> void Stack<T>::push(T k)
{
 
    // Checking whether stack is completely filled
    if (isFull()) {
        cout << "Stack is full\n";
    }
 
    // Inserted element
    cout << "Inserted element " << k << endl;
    top = top + 1;
    st[top] = k;
}
 
// To check if the stack is empty
template <class T> bool Stack<T>::isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
 
// To check if the stack is full or not
template <class T> bool Stack<T>::isFull()
{
    if (top == (SIZE - 1))
        return 1;
    else
         return 0;
}

template <class T> T Stack<T>::pop()
{
    // Initialising a variable to store popped element
    T popped_element = st[top];
    top--;
    return popped_element;
}
 
template <class T> T Stack<T>::topElement()
{
    // Initialising a variable to store top element
    T top_element = st[top];
 
    // Returning the top element
    return top_element;
}