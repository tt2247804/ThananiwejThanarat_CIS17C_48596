/* 
 * File:   main.cpp
 * Author: Thanarat Thananiwej
 * Created on October 6, 2014, 6:00 PM
 * Purpose:  To test new added functions and template
 */

//System Libraries
#include <iostream>
using namespace std;

//Our Library
#include "LnkdLst.h"

int main(int argc, char** argv) {
    //Create a linked list
	cout << "Create list<int> of size 3." << endl;
    LnkdLst<int> list(3);

    //Append 3 more chains
	cout << "Append and prepend 1, 2, 3." << endl;
    int clinks=3;
    for(int i=1;i<=clinks;i++){
        list.append(i);
    }
	for(int i=1;i<=clinks;i++){
        list.prepend(i);
    }

    //Print the data
    cout << "Result: " << list.toString() << endl;
	cout << "First: " << list.first() << endl;
	cout << "Last: " << list.last() << endl << endl;

	//Copy, Assign and Print
	cout << "Test copy cons and assign op." << endl;
	LnkdLst<int> newList(list);

	LnkdLst<int> list2(2);
	list2 = newList;
	cout << "Copy: " << newList.toString() << endl;
	cout << "Assign: " << list2.toString() << endl << endl;

	//Insert After, Before and Print
	list.insertAfter(8, 4);
	list.insertBefore(0, 5);
	cout << "Insert 4 after pos 8 and 5 before pos 0." << endl;
	cout<<list.toString()<<endl;

	//Extract
	cout << "Extract(1, 4): " << list.extract(1, 4) << endl;

	cout << endl << "-------------------------------------------------" << endl;

	//Create a linked list
	cout << "Create list<char> of size 0." << endl;
    LnkdLst<char> c_list(0);

    //Append 3 more chains
	cout << "Append and prepend a, b, c." << endl;
    for(char i='a';i<='c';i++){
        c_list.append(i);
    }
	for(char i='a';i<='c';i++){
        c_list.prepend(i);
    }

    //Print the data
    cout << "Result: " << c_list.toString() << endl;
	cout << "First: " << c_list.first() << endl;
	cout << "Last: " << c_list.last() << endl << endl;

	//Copy, Assign and Print
	cout << "Test copy cons and assign op." << endl;
	LnkdLst<char> c_newList(c_list);

	LnkdLst<char> c_list2(2);
	c_list2 = c_newList;
	cout << "Copy: " << c_newList.toString() << endl;
	cout << "Assign: " << c_list2.toString() << endl << endl;

	//Insert After, Before and Print
	c_list.insertAfter(5, 'd');
	c_list.insertBefore(0, 'e');
	cout << "Insert d after pos 5 and e before pos 0." << endl;
	cout<<c_list.toString()<<endl;

	//Extract
	cout << "Extract(1, 4): " << c_list.extract(1, 4) << endl;

    //Exit stage right!
    return 0;
}
