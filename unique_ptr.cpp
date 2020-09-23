#include <iostream>
#include "header/unique_ptr.hpp"

template<class T>
Unique_ptr<T>::Unique_ptr(T* ptr) :
		s_ptr(ptr) {}
	
template<class T>
Unique_ptr<T>::~Unique_ptr() { delete s_ptr; }
	
template<class T>
Unique_ptr<T>::operator bool () const { return s_ptr; }
	
template<class T>
Unique_ptr<T>::Unique_ptr(Unique_ptr&& obj) :
	s_ptr(obj.s_ptr)
{ obj.s_ptr = nullptr; }
	
template<class T>
Unique_ptr<T>& Unique_ptr<T>::operator =(Unique_ptr&& obj)
{
	if(&obj != this)
	{
		delete s_ptr;
		s_ptr = obj.s_ptr;
		obj.s_ptr = nullptr;
		return* this;
	}
	return* this;
}
	
template<class T>
void Unique_ptr<T>::swap(Unique_ptr& obj)
{
	T* temp { std::move(obj) };
	obj = std::move(obj.s_ptr);
	obj.s_ptr = temp;
}
	
template<class T>
T Unique_ptr<T>::release()
{
	T* ans = s_ptr;
	s_ptr = nullptr;
	return ans;
}
	
template<class T>
void Unique_ptr<T>::reset(T ptr)
{
	T* old = s_ptr;
	s_ptr = ptr;
	if(old != nullptr) delete old;
}

template<class T>
T* Unique_ptr<T>::operator ->() const { return s_ptr; }
template<class T>
T& Unique_ptr<T>::operator *() const { return *s_ptr; }
