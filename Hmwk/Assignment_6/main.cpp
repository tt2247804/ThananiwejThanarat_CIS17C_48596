/* 
 * File:   main.cpp
 * Author: Thanarat Thananiwej
 * Created on October 12, 2014, 6:30 PM
 * Purpose:  To test new classes
 */

//System Libraries
#include <iostream>
using namespace std;

//Our Library
#include "Stack.h"
#include "Queue.h"
#include "DouLnkdLst.h"
#include "CirLnkdLst.h"
#include "PLnkdLst.h"
#include "PQueue.h"
#include "SortLnkdLst.h"

int main(int argc, char** argv) 
{
	cout << "* * * * * Stack * * * * *" << endl << endl;
	Stack<int> stack(3);
	cout << "Test: Create Stack of size 3." << endl;
	cout << "Empty? ";
	if (stack.is_empty()) cout << "Yes."; 
	else cout << "No."; 
	cout << endl;
	cout << "Size: " << stack.size() << endl;
	cout << "Top value: " << stack.top() << endl << endl;

	cout << "Test: Push value 9 and then 7." << endl;
	stack.push(9);
	stack.push(7);
	cout << "Size: " << stack.size() << endl;
	cout << "Top value: " << stack.top() << endl << endl;

	cout << "Test: Pop once." << endl;
	stack.pop();
	cout << "Size: " << stack.size() << endl;
	cout << "Top value: " << stack.top() << endl << endl;

	cout << "Test: Copy c'tor." << endl;
	Stack<int> stackCopy(stack);
	cout << "Empty? ";
	if (stack.is_empty()) cout << "Yes."; 
	else cout << "No."; 
	cout << endl;
	cout << "Size: " << stack.size() << endl;
	cout << "Top value: " << stack.top() << endl << endl;

	cout << "Test: Assignment op." << endl;
	Stack<int> stackAssign = stackCopy;
	cout << "Empty? ";
	if (stack.is_empty()) cout << "Yes."; 
	else cout << "No."; 
	cout << endl;
	cout << "Size: " << stack.size() << endl;
	cout << "Top value: " << stack.top() << endl << endl;

	cout << "Test: Empty by pop all." << endl;
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	cout << "Size: " << stack.size() << endl;
	cout << "Empty? ";
	if (stack.is_empty()) cout << "Yes."; 
	else cout << "No."; 
	cout << endl << endl;

	cout << "------------------------------------------------------------------------" << endl << endl;

	cout << "* * * * * Queue * * * * *" << endl << endl;
	Queue<int> queue(0);
	cout << "Test: Create Queue of size 0." << endl;
	cout << "Empty? ";
	if (queue.is_empty()) cout << "Yes."; 
	else cout << "No."; 
	cout << endl;
	cout << "Size: " << queue.size() << endl << endl;

	cout << "Test: Push_back 1, 2 and then 3." << endl;
	queue.push_back(1);
	queue.push_back(2);
	queue.push_back(3);
	cout << "Empty? ";
	if (queue.is_empty()) cout << "Yes."; 
	else cout << "No."; 
	cout << endl;
	cout << "Size: " << queue.size() << endl;
	cout << "Front value: " << queue.front() << endl;
	cout << "Back value: " << queue.back() << endl << endl;

	cout << "Test: Pop_front once." << endl;
	queue.pop_front();
	cout << "Size: " << queue.size() << endl;
	cout << "Front value: " << queue.front() << endl;
	cout << "Back value: " << queue.back() << endl << endl;

	cout << "------------------------------------------------------------------------" << endl << endl;

	cout << "* * * * * Doubly Linked List * * * * *" << endl << endl;

	DouLnkdLst<int> DList(2);
	cout << "Test: Create Doubly Linked List of size 2." << endl;
	cout << "Result: " << DList.toString() << endl << endl;

	cout << "Test: Append value 2 and Prepend value 1." << endl;
	DList.append(2);
	DList.prepend(1);
	cout << "Result: " << DList.toString() << endl << endl;

	cout << "Test: Insert val 5 after index 1 and val 6 before index 0." << endl;
	DList.insertAfter(1, 5);
	DList.insertBefore(0, 6);
	cout << "Result: " << DList.toString() << endl << endl;
	
	cout << "Test: First, Last, and Extract from index 1 and length 4." << endl;
	cout << "First: " << DList.first() << endl;
	cout << "Last: " << DList.last() << endl;
	cout << "Extract(1, 4): " << DList.extract(1, 4) << endl << endl;

	cout << "Test: Copy Constructor and Assignment Operator." << endl;
	DouLnkdLst<int> DListCopy(DList);
	DouLnkdLst<int> DListAssign = DList;
	cout << "Copy: " << DListCopy.toString() << endl;
	cout << "Assign: " << DListAssign.toString() << endl << endl;

	cout << "Test: Doubly linked list property of prev pointers by printing backward." << endl;
	cout << "Result: " << DList.toStringBack() << endl << endl;

	cout << "------------------------------------------------------------------------" << endl << endl;

	cout << "* * * * * Circularly Linked List * * * * *" << endl << endl;

	cout << "Test: Create Circular list of size 5." << endl;
	CirLnkdLst<int> CList(5);
	cout << "Result: " << CList.toString() << endl << endl;

	cout << "Test: Append 6 and prepend 3." << endl;
	CList.append(6);
	CList.prepend(3);
	cout << "Result: " << CList.toString() << endl;
	cout << "First: " << CList.first() << endl;
	cout << "Last: " << CList.last() << endl << endl;

	cout << "Test: Circular property by printing data of specified length. " << endl;
	cout << "Length(15): " << CList.extract(15) << endl << endl;

	cout << "------------------------------------------------------------------------" << endl << endl;

	cout << "* * * * * Priority Linked List * * * * *" << endl << endl;

	cout << "Test: Create an empty priority list and insert val 1 prior 5 and 2 prior 3. " << endl;
	PLnkdLst<int> PList(0);
	PList.insertPrior(2, 3);
	PList.insertPrior(1, 5);
	cout << "Result: " << PList.toString() << endl;
	cout << "Highest Priority value: " << PList.first() << endl << endl; 

	cout << "------------------------------------------------------------------------" << endl << endl;

	cout << "* * * * * Priority Queue * * * * *" << endl << endl;
	PQueue<int> PQueue(0);
	cout << "Test: Create an empty Priority Queue." << endl;
	cout << "Empty? ";
	if (PQueue.is_empty()) cout << "Yes."; 
	else cout << "No."; 
	cout << endl;
	cout << "Size: " << PQueue.size() << endl << endl;

	cout << "Test: Push val 3 of prior 10, val 2 of prior 15 and val 1 of prior 20." << endl;
	PQueue.push_prior(3, 10);
	PQueue.push_prior(2, 15);
	PQueue.push_prior(1, 20);
	cout << "Empty? ";
	if (PQueue.is_empty()) cout << "Yes."; 
	else cout << "No."; 
	cout << endl;
	cout << "Size: " << PQueue.size() << endl;
	cout << "Front value: " << PQueue.front() << endl << endl;

	cout << "Test: Pop_front once." << endl;
	PQueue.pop_front();
	cout << "Size: " << PQueue.size() << endl;
	cout << "Front value: " << PQueue.front() << endl << endl;

	cout << "------------------------------------------------------------------------" << endl << endl;

	cout << "* * * * * Sorted Linked List * * * * *" << endl << endl;

	cout << "Test: Create empty sorted list and insert val 2 and val 4." << endl;
	SortLnkdLst<int> SList(0);
	SList.insertSorted(2);
	SList.insertSorted(4);
	cout << "Result: " << SList.toString() << endl << endl;

	cout << "Test: Insert val 5, 1 and 3." << endl;
	SList.insertSorted(5);
	SList.insertSorted(1);
	SList.insertSorted(3);
	cout << "Result: " << SList.toString() << endl << endl;

	cout << "------------------------------------------------------------------------" << endl << endl;

    return 0;
}
