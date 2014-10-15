/* 
 * File:   Stack.h
 * Author: Thanarat Thananiwej
 * Created on October 13, 2014, 6:30 PM
 */

#ifndef STACK_H
#define STACK_H

#include "LnkdLst.h"

template <class T>
class Stack
{
public:
	Stack(int);
	Stack(const Stack &other);
	Stack & operator= (const Stack &other);
	~Stack();
	int size();
	bool is_empty();
	T top();
	void push(T);
	void pop();
private:
	LnkdLst<T> list;
	int s;
};

template <class T>
Stack<T>::Stack(int sz)
	: list(sz)
{
	s = sz;
}

template <class T>
Stack<T>::Stack(const Stack<T> &other)
	: list(other.list)
{
	s = other.s;
}

template <class T>
Stack<T> & Stack<T>::operator= (const Stack<T> &other)
{
	if (this != &other)
	{
		s = other.s;
		list = other.list;
	}
	return *this;
}

template <class T>
Stack<T>::~Stack()
{
	while (!is_empty())
	{
		pop();
	}
}

template <class T>
int Stack<T>::size()
{
	return s;
}

template <class T>
bool Stack<T>::is_empty()
{
	if (s == 0) return true;
	else return false;
}

template <class T>
T Stack<T>::top()
{
	return list.first();
}

template <class T>
void Stack<T>::push(T val)
{
	list.prepend(val);
	++s;
}

template <class T>
void Stack<T>::pop()
{
	if (!is_empty())
	{
		list.removeHead();
		--s;
	}
}

#endif
