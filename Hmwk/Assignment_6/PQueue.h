/* 
 * File:   PQueue.h
 * Author: Thanarat Thananiwej
 * Created on October 14, 2014, 6:30 PM
 */

#ifndef PQUEUE_H
#define PQUEUE_H

#include "PLnkdLst.h"

template <class T>
class PQueue
{
public:
	PQueue(int);
	PQueue(const PQueue &other);
	PQueue & operator= (const PQueue &other);
	~PQueue();
	int size();
	bool is_empty();
	T front();
	void push_prior(T, int);
	void pop_front();
private:
	PLnkdLst<T> PList;
	int s;
};

template <class T>
PQueue<T>::PQueue(int sz)
	: PList(sz)
{
	s = sz;
}

template <class T>
PQueue<T>::PQueue(const PQueue<T> &other)
	: PList(other.PList)
{
	s = other.s;
}

template <class T>
PQueue<T> & PQueue<T>::operator= (const PQueue<T> &other)
{
	if (this != &other)
	{
		s = other.s;
		PList = other.PList;
	}
	return *this;
}

template <class T>
PQueue<T>::~PQueue()
{
	while (!is_empty())
	{
		pop_front();
	}
}

template <class T>
int PQueue<T>::size()
{
	return s;
}

template <class T>
bool PQueue<T>::is_empty()
{
	if (s == 0) return true;
	else return false;
}

template <class T>
T PQueue<T>::front()
{
	return PList.first();
}

template <class T>
void PQueue<T>::push_prior(T val, int p)
{
	PList.insertPrior(val, p);
	++s;
}

template <class T>
void PQueue<T>::pop_front()
{
	if (!is_empty())
	{
		PList.removeHead();
		--s;
	}
}

#endif
