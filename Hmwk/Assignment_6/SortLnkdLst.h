/* 
 * File:   SortLnkdLst.h
 * Author: Thanarat Thananiwej
 * Created on October 12, 2014, 8:00 PM
 */

#ifndef SORTLNKDLST_H
#define	SORTLNKDLST_H

#include <sstream>
#include <iostream>
#include <string>

using namespace std;

template <class T>
class SortLnkdLst 
{
public:
    SortLnkdLst(int);
	SortLnkdLst(const SortLnkdLst &other);
	SortLnkdLst & operator= (const SortLnkdLst &other);
	void insertSorted(T);
    string toString();
	string extract(int, int);
	T first();
	T last();
    ~SortLnkdLst();
private:
    struct Node
	{
         T data;
         Node *next;
    };
    Node *head;
    Node *worker;

	void append(T);
};

/* This constructor constructs a linked list of *
 * specified size. The data of each Node is 0.  */
template <class T>
SortLnkdLst<T>::SortLnkdLst(int size)
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
SortLnkdLst<T>::SortLnkdLst(const SortLnkdLst<T> &other)
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
SortLnkdLst<T> & SortLnkdLst<T>::operator= (const SortLnkdLst<T> &other)
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

template <class T>
void SortLnkdLst<T>::insertSorted(T val)
{
	Node* temp = new Node;
	temp->data = val;
	temp->next = NULL;

	if (head)
	{
		if (val < head->data)
		{
			temp->next = head;
			head = temp;
		}
		else
		{
			worker = head;
			while (worker->next)
			{
				if (val < worker->next->data)
				{
					temp->next = worker->next;
					worker->next = temp;
					return;
				}
				worker = worker->next;
			}

			worker->next = temp;
		}
	}
	else head = temp;
}

/* This function collects data in each Node and *
 * returns string of the data.                  */
template <class T>
string SortLnkdLst<T>::toString()
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
string SortLnkdLst<T>::extract(int pos, int len)
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
T SortLnkdLst<T>::first()
{
	if (head) return head->data;
	else return T();
}

/* This function returns the last Node's data.  */
template <class T>
T SortLnkdLst<T>::last()
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
SortLnkdLst<T>::~SortLnkdLst()
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

/* This function creates a new Node and append  *
 * it to the end of the linked list. The new    *
 * Node becomes head if the list is empty.      *
 * Returns nothing.                             */
template <class T>
void SortLnkdLst<T>::append(T i)
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

#endif	/* SORTLNKDLST_H */

