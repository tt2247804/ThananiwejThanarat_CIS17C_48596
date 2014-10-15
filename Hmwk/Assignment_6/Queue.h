/* 
 * File:   Queue.h
 * Author: Thanarat Thananiwej
 * Created on October 13, 2014, 6:30 PM
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "LnkdLst.h"

template <class T>
class Queue
{
public:
	Queue(int);
	Queue(const Queue &other);
	Queue & operator= (const Queue &other);
	~Queue();
	int size();
	bool is_empty();
	T front();
	T back();
	void push_back(T);
	void pop_front();
private:
	LnkdLst<T> list;
	int s;
};

template <class T>
Queue<T>::Queue(int sz)
	: list(sz)
{
	s = sz;
}

template <class T>
Queue<T>::Queue(const Queue<T> &other)
	: list(other.list)
{
	s = other.s;
}

template <class T>
Queue<T> & Queue<T>::operator= (const Queue<T> &other)
{
	if (this != &other)
	{
		s = other.s;
		list = other.list;
	}
	return *this;
}

template <class T>
Queue<T>::~Queue()
{
	while (!is_empty())
	{
		pop_front();
	}
}

template <class T>
int Queue<T>::size()
{
	return s;
}

template <class T>
bool Queue<T>::is_empty()
{
	if (s == 0) return true;
	else return false;
}

template <class T>
T Queue<T>::front()
{
	return list.first();
}

template <class T>
T Queue<T>::back()
{
	return list.last();
}

template <class T>
void Queue<T>::push_back(T val)
{
	list.append(val);
	++s;
}

template <class T>
void Queue<T>::pop_front()
{
	if (!is_empty())
	{
		list.removeHead();
		--s;
	}
}

#endif
