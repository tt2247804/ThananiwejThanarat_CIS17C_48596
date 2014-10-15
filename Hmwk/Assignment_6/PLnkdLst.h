/* 
 * File:   PLnkdLst.h
 * Author: Thanarat Thananiwej
 * Created on October 14, 2014, 6:00 PM
 */

#ifndef PLNKDLST_H
#define	PLNKDLST_H

#include <sstream>
#include <iostream>
#include <string>

using namespace std;

template <class T>
class PLnkdLst 
{
public:
    PLnkdLst(int);
	PLnkdLst(const PLnkdLst &other);
	PLnkdLst & operator= (const PLnkdLst &other);
	void insertPrior(T, int);
    string toString();
	T first();
	~PLnkdLst();

	void removeHead();
private:
    struct Node
	{
		int prior;
        T data;
        Node *next;
    };
    Node *head;
    Node *worker;

	void append(T, int);
};

/* This constructor constructs a linked list of *
 * specified size. The data of each Node is 0.  */
template <class T>
PLnkdLst<T>::PLnkdLst(int size)
{
	//Initialize head and worker
	head = NULL;
	worker = NULL;

	//Linked list with at least one Node
	if (size >= 1)
	{
		//Create first Node
		head = new Node;
		head->prior = 0;
		head->data = T();
		head->next = NULL;

		//Create following Nodes
		for (int i = 1; i < size; ++i)
		{
			worker = new Node;
			worker->prior = 0;
			worker->data = T();
			worker->next = head;
			head = worker;
		}
	}
}

/* This constructor makes a deep copy of a      *
 * LnkdLst argument.                            */
template <class T>
PLnkdLst<T>::PLnkdLst(const PLnkdLst<T> &other)
{
	head = NULL;
	Node *i = other.head;
	if (i)
	{
		do
		{
			//Use append to copy data over
			this->append(i->data, i->prior);
		} while (i=i->next);
	}
}

/* Overload assignment operator                 */
template <class T>
PLnkdLst<T> & PLnkdLst<T>::operator= (const PLnkdLst<T> &other)
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
				this->append(i->data, i->prior);
			} while (i=i->next);
		}
	}
	return *this;
}

template <class T>
void PLnkdLst<T>::insertPrior(T val, int p)
{
	Node* temp = new Node;
	temp->prior = p;
	temp->data = val;
	temp->next = NULL;

	if (head)
	{
		if (p > head->prior)
		{
			temp->next = head;
			head = temp;
		}
		else
		{
			worker = head;
			while (worker->next)
			{
				if (p > worker->next->prior)
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

/* This function creates a new Node and append  *
 * it to the end of the linked list. The new    *
 * Node becomes head if the list is empty.      *
 * Returns nothing.                             */
template <class T>
void PLnkdLst<T>::append(T i, int p)
{
	//Construct a new Node to append
	Node* temp = new Node;
	temp->prior = p;
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

/* This function collects data in each Node and *
 * returns string of the data.                  */
template <class T>
string PLnkdLst<T>::toString()
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

/* This function returns the first Node's data. */
template <class T>
T PLnkdLst<T>::first()
{
	if (head) return head->data;
	else return T();
}

/* The destructor to destoy all Nodes.          */
template <class T>
PLnkdLst<T>::~PLnkdLst()
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

/* Delete head.                                 */
template <class T>
void PLnkdLst<T>::removeHead()
{
	if (head)
	{
		worker = head;
		head = head->next;
		delete worker;
	}
}

#endif	/* PLNKDLST_H */

