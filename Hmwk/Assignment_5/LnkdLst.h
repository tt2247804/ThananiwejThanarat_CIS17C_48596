/* 
 * File:   LnkdLst.h
 * Author: Thanarat Thananiwej
 * Created on October 6, 2014, 6:00 PM
 */

#ifndef LNKDLST_H
#define	LNKDLST_H

#include <sstream>
#include <iostream>
#include <string>

using namespace std;

template <class T>
class LnkdLst {
public:
    LnkdLst(int);
	LnkdLst(const LnkdLst &other);
	LnkdLst & operator= (const LnkdLst &other);
    void append(T);
	void prepend(T);
	void insertAfter(int, T);
	void insertBefore(int, T);
    string toString();
	string extract(int, int);
	T first();
	T last();
    virtual ~LnkdLst();
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
LnkdLst<T>::LnkdLst(int size)
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
	}
}

/* This constructor makes a deep copy of a      *
 * LnkdLst argument.                            */
template <class T>
LnkdLst<T>::LnkdLst(const LnkdLst<T> &other)
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
LnkdLst<T> & LnkdLst<T>::operator= (const LnkdLst<T> &other)
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
void LnkdLst<T>::append(T i)
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
		while (worker->next)
		{
			worker = worker->next;
		}
		//Last Node->next points to new Node
		worker->next = temp;
	}
	//New Node is the head if empty
	else head = temp;
}

/* This function creates a new Node and prepend *
 * it to the front of the linked list. The new  *
 * Node becomes head. Return nothing.           */
template <class T>
void LnkdLst<T>::prepend(T i)
{
	//Construct a new Node to prepend
	Node* temp = new Node;
	temp->data = i;
	temp->next = NULL;

	//Check if linked list is empty
	if (head) temp->next = head;

	//New Node becomes head
	head = temp;
}

/* This function insert a new Node after the    *
 * specified position. First argument accepts   *
 * the position and second accepts value.       */
template <class T>
void LnkdLst<T>::insertAfter(int pos, T val)
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
		worker->next = temp;
	}
	else head = temp;
}

/* This function insert a new Node before the   *
 * specified position. First argument accepts   *
 * the position and second accepts value.       */
template <class T>
void LnkdLst<T>::insertBefore(int pos, T val)
{
	if (pos < 0)
	{
		cout << "Error: invalid index." << endl;
		return;
	}

	Node* temp = new Node;
	temp->data = val;
	temp->next = NULL;
	
	//Insert before head
	if (pos == 0)
	{
		temp->next = head;
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
		worker->next = temp;
	}
	else head = temp;
}

/* This function collects data in each Node and *
 * returns string of the data.                  */
template <class T>
string LnkdLst<T>::toString()
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

/* This function extracts data from specified   *
 * position and length. First argument accepts  *
 * position and second accepts length. Return   *
 * the data as string.                          */
template <class T>
string LnkdLst<T>::extract(int pos, int len)
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
T LnkdLst<T>::first()
{
	if (head) return head->data;
	else return T();
}

/* This function returns the last Node's data.  */
template <class T>
T LnkdLst<T>::last()
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
LnkdLst<T>::~LnkdLst()
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

#endif	/* LNKDLST_H */

