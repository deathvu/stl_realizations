#include <iostream>
#include <exception>

template<class T>
class Dlist
{
public:
	Dlist() :
		_size(0), head(nullptr), tail(nullptr) {}
	~Dlist() { clear(); }
	
	void push_back(const T&);
	void push_front(const T&);
	void insert(const T&, const size_t);
	void remove_at(const size_t);
	void pop_front();
	void pop_back();
	void clear();
	void show();
	
	const size_t size();
	
	Dlist& operator=(const Dlist&);
	
private:
	
	template<class T2>
	class Node
	{
	public:
		Node* pnext;	
		Node* pprev;	
		T2 data;
		
		Node(T2 data = T2(), Node* pnext = nullptr, Node* pprev = nullptr) :
			data(data), pnext(pnext), pprev(pprev) {}
	};
	
	Node<T>* tail;
	Node<T>* head;
	size_t _size;		
};