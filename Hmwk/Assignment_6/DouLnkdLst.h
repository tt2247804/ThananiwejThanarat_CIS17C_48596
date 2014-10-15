/* 
 * File:   DouLnkdLst.h
 * Author: Thanarat Thananiwej
 * Created on October 12, 2014, 6:30 PM
 */

#ifndef DOULNKDLST_H
#define	DOULNKDLST_H

#include <sstream>
#include <iostream>
#include <string>

using namespace std;

template <class T>
class DouLnkdLst 
{
public:
    DouLnkdLst(int);
	DouLnkdLst(const DouLnkdLst &other);
	DouLnkdLst & operator= (const DouLnkdLst &other);
    void append(T);
	void prepend(T);
	void insertAfter(int, T);
	void insertBefore(int, T);
    string toString();
	string toStringBack();
	string extract(int, int);
	T first();
	T last();
    ~DouLnkdLst();
private:
    struct Node
	{
         T data;
         Node *next;
		 Node *prev;
    };
    Node *head;
    Node *worker;
};

/* This constructor constructs a doubly linked  *
 * list of specified size.                      */
template <class T>
DouLnkdLst<T>::DouLnkdLst(int size)
{
	//Initialize head and worker
	head = NULL;
	worker = NULL;

	//Linked list with at least one Node
	if (size >= 1)
	{
		//Create first Node
		head = new Node;
		head->data = T();
		head->next = NULL;
		head->prev = NULL;

		//Create following Nodes
		for (int i = 1; i < size; ++i)
		{
			worker = new Node;
			worker->data = T();
			worker->next = head;
			worker->prev = NULL;
			head->prev = worker;
			head = worker;
		}
	}
}

/* This constructor makes a deep copy of a      *
 * DouLnkdLst argument.                         */
template <class T>
DouLnkdLst<T>::DouLnkdLst(const DouLnkdLst<T> &other)
{
	head = NULL;
	Node *i = other.head;
	if (i)
	{
		do
		{
			//Use append to copy data over
			this->append(i->data);
		} while (i=i->next);
	}
}

/* Overload assignment operator                 */
template <class T>
DouLnkdLst<T> & DouLnkdLst<T>::operator= (const DouLnkdLst<T> &other)
{
	if (this != &other)
	{
		//Delete old list if there is one
		if (head)
		{
			do
			{
				worker = head;
				head = head->next;
				delete worker;
			} while (head);
		}

		//Deep copy
		head = NULL;
		Node *i = other.head;
		if (i)
		{
			do
			{
				//Use append to copy data over
				this->append(i->data);
			} while (i=i->next);
		}
	}
	return *this;
}

/* This function creates a new Node and append  *
 * it to the end of the linked list. The new    *
 * Node becomes head if the list is empty.      *
 * Returns nothing.                             */
template <class T>
void DouLnkdLst<T>::append(T i)
{
	//Construct a new Node to append
	Node* temp = new Node;
	temp->data = i;
	temp->next = NULL;
	temp->prev = NULL;

	//Check if linked list is empty
	if (head)
	{
		worker = head;
		//Go through the list until last Node
		while (worker->next)
		{
			worker = worker->next;
		}
		//Last Node->next points to new Node
		worker->next = temp;
		temp->prev = worker;
	}
	//New Node is the head if empty
	else head = temp;
}

/* This function creates a new Node and prepend *
 * it to the front of the linked list. The new  *
 * Node becomes head. Return nothing.           */
template <class T>
void DouLnkdLst<T>::prepend(T i)
{
	//Construct a new Node to prepend
	Node* temp = new Node;
	temp->data = i;
	temp->next = NULL;
	temp->prev = NULL;

	//Check if linked list is empty
	if (head) 
	{
		temp->next = head;
		head->prev = temp;
	}

	//New Node becomes head
	head = temp;
}

/* This function insert a new Node after the    *
 * specified position. First argument accepts   *
 * the position and second accepts value.       */
template <class T>
void DouLnkdLst<T>::insertAfter(int pos, T val)
{
	//Posistion cannot be negative
	if (pos < 0)
	{
		cout << "Error: invalid index." << endl;
		return;
	}

	Node* temp = new Node;
	temp->data = val;
	temp->next = NULL;
	temp->prev = NULL;
	
	if (head)
	{
		worker = head;
		//Loop to the specified position
		for (int i = 0; i < pos; i++)
		{
			worker = worker->next;
			//Check index out of bound
			if (!worker)
			{
				cout << "Error: invalid index." << endl;
				return;
			}
		}
		temp->next = worker->next;
		temp->prev = worker;
		if (worker->next) worker->next->prev = temp;
		worker->next = temp;

	}
	else head = temp;
}

/* This function insert a new Node before the   *
 * specified position. First argument accepts   *
 * the position and second accepts value.       */
template <class T>
void DouLnkdLst<T>::insertBefore(int pos, T val)
{
	if (pos < 0)
	{
		cout << "Error: invalid index." << endl;
		return;
	}

	Node* temp = new Node;
	temp->data = val;
	temp->next = NULL;
	temp->prev = NULL;
	
	//Insert before head
	if (pos == 0)
	{
		temp->next = head;
		head->prev = temp;
		head = temp;
	}

	else if (head)
	{
		worker = head;
		for (int i = 0; i < pos-1; i++)
		{
			worker = worker->next;
			if (!worker->next)
			{
				cout << "Error: invalid index." << endl;
				return;
			}
		}
		temp->next = worker->next;
		temp->prev = worker;
		worker->next->prev = temp;
		worker->next = temp;
	}
	else head = temp;
}

/* This function collects data in each Node and *
 * returns string of the data.                  */
template <class T>
string DouLnkdLst<T>::toString()
{
	//Create stringstream to convert int to string
	stringstream ss;
	if (head)
	{
		worker = head;
		//Go through the list
        do
		{
			//Add data to the stringstream
			ss << worker->data;
        } while (worker=worker->next);
    }
	//Create string ret to hold all the data
	string ret = ss.str();
	return ret;
}

/* This function collects data in each Node and *
 * returns string of the data backward.         */
template <class T>
string DouLnkdLst<T>::toStringBack()
{
	//Create stringstream to convert int to string
	stringstream ss;
	if (head)
	{
		worker = head;
		while (worker->next) worker = worker->next;
		while (worker)
		{
			ss << worker->data;
			worker = worker->prev;
		}
    }
	//Create string ret to hold all the data
	string ret = ss.str();
	return ret;
}

/* This function extracts data from specified   *
 * position and length. First argument accepts  *
 * position and second accepts length. Return   *
 * the data as string.                          */
template <class T>
string DouLnkdLst<T>::extract(int pos, int len)
{
	if (pos < 0)
	{
		cout << "Error: invalid index." << endl;
		return NULL;
	}

	string ret = this->toString();
	ret = ret.substr(pos, len);
	return ret;
}

/* This function returns the first Node's data. */
template <class T>
T DouLnkdLst<T>::first()
{
	if (head) return head->data;
	else return T();
}

/* This function returns the last Node's data.  */
template <class T>
T DouLnkdLst<T>::last()
{
	if (head)
	{
		worker = head;
		while (worker = worker->next)
		{
			if (worker->next == NULL) return worker->data;
		}
	}
	else return T();
}

/* The destructor to destoy all Nodes.          */
template <class T>
DouLnkdLst<T>::~DouLnkdLst()
{
	if (head)
	{
        do
		{
            worker = head;
            head = head->next;
            delete worker;
        } while (head);
    }
}

#endif	/* DOULNKDLST_H */
