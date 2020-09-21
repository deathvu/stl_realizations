#include <iostream>
 
template <typename T>
class Stack
{
private:
    T *stackPtr; 
    int size; 
    T top; 
public:
    Stack(int = 10);
    ~Stack(); 
    bool push(const T  ); 
    bool pop(); 
    void printStack();
};