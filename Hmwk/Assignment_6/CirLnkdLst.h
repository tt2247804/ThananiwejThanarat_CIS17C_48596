/* 
 * File:   CirLnkdLst.h
 * Author: Thanarat Thananiwej
 * Created on October 12, 2014, 6:30 PM
 */

#ifndef CIRLNKDLST_H
#define	CIRLNKDLST_H

#include <sstream>
#include <iostream>
#include <string>

using namespace std;

template <class T>
class CirLnkdLst 
{
public:
    CirLnkdLst(int);
	CirLnkdLst(const CirLnkdLst &other);
	CirLnkdLst & operator= (const CirLnkdLst &other);
    void append(T);
	void prepend(T);
    string toString();
	string extract(int);
	T first();
	T last();
    ~CirLnkdLst();
private:
    struct Node{
         T data;
         Node *next;
    };
    Node *head;
    Node *worker;
};

/* This constructor constructs a linked list of *
 * specified size. The data of each Node is 0.  */
template <class T>
CirLnkdLst<T>::CirLnkdLst(int size)
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

		//Create following Nodes
		for (int i = 1; i < size; ++i)
		{
			worker = new Node;
			worker->data = T();
			worker->next = head;
			head = worker;
		}

		worker = head;
		while (worker->next) worker = worker->next;
		worker->next = head;
	}
}

/* This constructor makes a deep copy of a      *
 * CirLnkdLst argument.                         */
template <class T>
CirLnkdLst<T>::CirLnkdLst(const CirLnkdLst<T> &other)
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
CirLnkdLst<T> & CirLnkdLst<T>::operator= (const CirLnkdLst<T> &other)
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
void CirLnkdLst<T>::append(T i)
{
	//Construct a new Node to append
	Node* temp = new Node;
	temp->data = i;
	temp->next = NULL;

	//Check if linked list is empty
	if (head)
	{
		worker = head;
		//Go through the list until last Node
		while (worker->next != head)
		{
			worker = worker->next;
		}
		//Last Node->next points to new Node
		worker->next = temp;
		temp->next = head;
	}
	//New Node is the head if empty
	else 
	{
		head = temp;
		head->next = head;
	}
}

/* This function creates a new Node and prepend *
 * it to the front of the linked list. The new  *
 * Node becomes head. Return nothing.           */
template <class T>
void CirLnkdLst<T>::prepend(T i)
{
	//Construct a new Node to prepend
	Node* temp = new Node;
	temp->data = i;
	temp->next = NULL;

	//Check if linked list is empty
	if (head)
	{
		worker = head;
		while (worker->next != head)
		{
			worker = worker->next;
		}
		worker->next = temp;
		temp->next = head;
		head = temp;
	}
	else
	{
		head = temp;
		head->next = head;
	}
}

/* This function collects data in each Node and *
 * returns string of the data.                  */
template <class T>
string CirLnkdLst<T>::toString()
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
			worker = worker->next;
        } while (worker != head);
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
string CirLnkdLst<T>::extract(int len)
{
	stringstream ss;
	worker = head;
	for (int i = 0; i < len; ++i)
	{
		ss << worker->data;
		worker = worker->next;
	}
	string ret = ss.str();
	return ret;
}

/* This function returns the first Node's data. */
template <class T>
T CirLnkdLst<T>::first()
{
	if (head) return head->data;
	else return T();
}

/* This function returns the last Node's data.  */
template <class T>
T CirLnkdLst<T>::last()
{
	if (head)
	{
		worker = head;
		while (worker->next != head)
		{
			worker = worker->next;
		}
		return worker->data;
	}
	else return T();
}

/* The destructor to destoy all Nodes.          */
template <class T>
CirLnkdLst<T>::~CirLnkdLst()
{
	if (head)
	{
        while (worker->next != head) worker = worker->next;
		worker->next = NULL;
		do
		{
            worker = head;
            head = head->next;
            delete worker;
        } while (head);
    }
}

#endif	/* CIRLNKDLST_H */

