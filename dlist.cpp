#include "header/dList.hpp"


template<class T>
void Dlist<T>::remove_at(const size_t index)
{
	if(index < 0 || index > _size)
		return;
	if(index < _size / 2)
	{
		if(index == 0)
			pop_front();
		else
		{
			size_t counter = 0;
			Node<T>* it = head;
			while(counter < index)
			{
				it = it->pnext;
				++counter;
			}
			it->pnext->pprev = it->pprev;
			it->pprev->pnext = it->pnext;
			delete it;
			--_size;
		}
	}
	else
	{
		if(index == _size)
			pop_back();
		else
		{
			size_t counter = _size - 1;
			Node<T>* it = tail;
			while(counter > index)
			{
				it = it->pprev;
				--counter;
			}
			it->pnext->pprev = it->pprev;
			it->pprev->pnext = it->pnext;
			delete it;
			--_size;
		}
	}
}

template<class T>
void Dlist<T>::clear()
{
	while(_size)
		this->pop_front();
}

template<class T>
void Dlist<T>::pop_back()
{
	if(tail != nullptr)
	{
		Node<T>* temp = tail;
		tail->pprev->pnext = nullptr;
		tail = tail->pprev;
		delete temp;
		--_size;
	}
	else
		return;
}

template<class T>
void Dlist<T>::pop_front()
{
    if(head != nullptr)
    {
        Node<T>* temp = head;
        if(head->pnext) {
            head->pnext->pprev = nullptr;
            head = head->pnext;
        }
        else 
			head = nullptr;
			
        delete temp;
        --_size;
    }
    else
        return;
}

template<class T>
void Dlist<T>::insert(const T& el, const size_t index)
{
	if(index > _size || index < 0)
		return;
		
	else if(index == 0)
		push_front(el);
		
	else if(index == _size)
		push_back(el);
		
	else
	{
		Node<T>* temp = new Node<T>;
		temp->data = el;
		
		if(index < _size / 2)
		{
			Node<T>* it = head;
			size_t counter = 1;
			while(counter < index)
			{
				it = it->pnext;
				++counter;
			}
			temp->pprev = it->pprev;
			temp->pnext = it;
			it->pprev->pnext = temp;
			it->pprev = temp;
		}
		else
		{
			Node<T>* it = tail;
			size_t counter = _size;
			while(counter > index)
			{
				it = it->pprev;
				--counter;
			}
			temp->pnext = it->pnext;
			temp->pprev = it;
			it->pnext->pprev = temp;
			it->pnext = temp;
		}
	}
	++_size;
}

template<class T>
void Dlist<T>::show()
{
	Node<T>* it = head;
	while(it != nullptr)
	{
		std::cout << it->data << " ";
		it = it->pnext;
	}
}

template<class T>
void Dlist<T>::push_front(const T& el)
{
	Node<T>* temp = new Node<T>;
	temp->data = el;
	temp->pnext = head;
	
	if(head != nullptr)
	{
		head->pprev = temp;
		head = temp;
	}
	else if(_size == 0)
		head = tail = temp;
		
	else
		head = temp;
		
	++_size;
}

template<class T>
void Dlist<T>::push_back(const T& el)
{
	Node<T>* temp = new Node<T>;
	temp->data = el;
	temp->pprev = tail;
	
	if(tail != nullptr)		
	{
		tail->pnext = temp;
		tail = temp;
	}
	else if(_size == 0)	
		head = tail = temp;
		
	else
		tail = temp;
		
	++_size;
}

template<class T>
const size_t Dlist<T>::size()
{
	return this->_size;
}

template<class T>
Dlist<T>& Dlist<T>::operator=(const Dlist& other)
{
	if(this != &other)
	{
		this->clear();
		Node<T>* newList = other.head;
		while(newList != nullptr)
		{
			push_back(newList->data);
			newList = newList->pprev;
		}
		return*this;
	}
	return*this;
}



