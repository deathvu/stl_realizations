#include <iostream>

template<class T>
class Shared_ptr
{
    public:
        Shared_ptr();
        Shared_ptr(T*);
        Shared_ptr(Shared_ptr<T>&);
        virtual ~Shared_ptr();
        Shared_ptr& operator =(Shared_ptr&);
        void reset();
        bool unique() const;
        size_t use_count () const;

    private:
        T* s_ptr;
        size_t* counter;

};