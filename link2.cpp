// List example from course booklet - page 16-17
#include "link2.h"
#include <cstring> // Needed for NULL
#include <iostream>
using namespace std;

//------------------------------------------------
//  class Link implementation
//------------------------------------------------
// Constructor
//------------------------------------------------
List::Link::Link(int val, Link* nxt) : value(val), next(nxt)
{}

//------------------------------------------------
// Copy Constructor
//------------------------------------------------
List::Link::Link(const Link& source) : value(source.value), next(source.next)
{}

//--------------------------------------------
//  class List implementation
//--------------------------------------------
// Default constructor
//--------------------------------------------
List::List() : head(NULL)
{
	// no further initialization
}

//------------------------------------------------
// Copy constructor
//------------------------------------------------
List::List(const List &l)
{
	Link *src, *target;
	if (l.head == NULL)
		head = NULL;
	else {
		head = new Link((l.head)->value, NULL);
		src = l.head;
		target = head;
		while (src->next != NULL)	{
			target->next = new Link((src->next)->value, NULL);
			src = src->next;
			target = target->next;
		}
	}
} // Copy constructor

//------------------------------------------------
List::~List()
{
	clear();
} // Destructor

//------------------------------------------------
void List::clear()
{
	// empty all elements from the List
	Link* next;
	for (Link *p = head; p != NULL; p = next) {
		// delete the element pointed to by p
		next = p->next;
		p->next = NULL;
		delete p;
	}

	// mark that the List contains no elements
	head = NULL;
} // clear

//------------------------------------------------
bool List::isEmpty() const
{
	// test to see if the List is empty
	// List is empty if the pointer to the head
	// Link is null
	return head == NULL;
} // isEmpty

//------------------------------------------------
void List::add(int val)
{
	//Add a new value to the front of a Linked List
	head = new Link(val, head);
	if (NULL == head)
		throw "failed in memory allocation";
} // add

//------------------------------------------------
int List::firstElement() const
{
	// return first value in List
	if (isEmpty())
		throw "the List is empty, no first Element";
	return head->value;
} // firstElement

//------------------------------------------------
bool  List::search(const  int &val) const
{
	// loop to test each element
	for (Link* p = head; p != NULL; p = p->next)
		if (val == p->value)
			return true;
	// not found
	return false;
} // search

//------------------------------------------------
void List::removeFirst()
{
	// make sure there is a first element
	if (isEmpty())
		throw "the List is empty, no Elements to remove";

	// save pointer to the removed node
	Link* p = head;
	// reassign the first node
	head = p->next;
	p->next = NULL;
	// recover memory used by the first element
	delete p;
} // removeFirst

istream& operator >>(istream& in, List& param)
{
	
	return in;
}

ostream& operator <<(ostream& out, List param)
{
	List cheese = param;
	int first; 
	while (!cheese.isEmpty())
	{
		out << cheese.firstElement() << " ";
		cheese.removeFirst();
	}
	return out;
}

int main()
{
	List lst;
	lst.add(5);
	lst.add(17);
	lst.add(3);
	cout << lst;

	system("pause");
	return 0;
}