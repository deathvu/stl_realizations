#include <iostream>
#include "header/shared_ptr.hpp"

template<class T>
Shared_ptr<T>::Shared_ptr():
                            s_ptr(nullptr), 
                            counter(nullptr)
{}

template<class T>
Shared_ptr<T>::Shared_ptr(T* ptr):
                                s_ptr(ptr),
                                counter(size_t(1))
{}

template<class T>
Shared_ptr<T>::Shared_ptr(Shared_ptr<T>& ptr):
                                                    s_ptr(ptr.s_ptr),
                                                    counter(ptr.counter)
{
    ++counter;
    ++ptr.counter;
}

template<class T>
Shared_ptr<T>::~Shared_ptr()
{
    reset();
}

template<class T>
Shared_ptr<T>& Shared_ptr<T>::operator=(Shared_ptr& ptr)
{
    if(this != &ptr)
    {
        reset();
        s_ptr = ptr.s_ptr;
        counter = ptr.counter;
        ++counter;
        ++ptr.counter;
    }
    return *this;
}

template<class T>
size_t Shared_ptr<T>::use_count() const {return count;}

template<class T>
bool Shared_ptr<T>::unique() const
{
    if(*counter == 1) return false;
    else if(counter == 0) return true
}

template<class T>
void Shared_ptr<T>::reset()
{
    if(counter > 0)
        --counter;
    else if(counter == 0)
        delete s_ptr;
}

template<class T>
Shared_ptr<T>::~Shared_ptr()
{
    reset();
}