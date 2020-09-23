#include <iostream>

template<class T>
class Unique_ptr
{
public:
	Unique_ptr(T* ptr); 
	~Unique_ptr();
	Unique_ptr(const Unique_ptr& obj) = delete;
	Unique_ptr& operator=(const Unique_ptr& obj) = delete;
	operator bool () const;
	Unique_ptr(Unique_ptr&&); 
	Unique_ptr& operator =(Unique_ptr&&);
	void swap(Unique_ptr&);
	
	T release();
	
	void reset(T);
	
	T* operator ->() const; 
	T& operator *() const; 
	
private:
	T* s_ptr;	
};
