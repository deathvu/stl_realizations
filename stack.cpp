#include "header/stack.hpp"

template <typename T>
Stack<T>::Stack(int s)
{
    size = s > 0 ? s: 10;   
    stackPtr = new T[size]; 
    top = -1; 
}
 
// деструктор
template <typename T>
Stack<T>::~Stack()
{
    delete [] stackPtr; 
}
 
template <typename T>
bool Stack<T>::push(const T value)
{
    if (top == size - 1)
        return false; 
 
    top++;
    stackPtr[top] = value; 
 
    return true; 
}
 
template <typename T>
bool Stack<T>::pop()
{
    if (top == - 1)
        return false; 
 
    stackPtr[top] = 0; 
    top--;
 
    return true; 
}
 
template <typename T>
void Stack<T>::printStack()
{
    for (int ix = size -1; ix >= 0; ix--)
        std::cout << "|" << stackPtr[ix] << std::endl;
}
