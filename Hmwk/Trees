#ifndef TREE_H
#define	TREE_H

#include <iostream>
#include <string>

using namespace std;

class Tree 
{
private:
	struct Node
	{
		int data;
		Node *left;
		Node *right;
		int height;
		Node(int d)
		{
			data = d;
			left = NULL;
			right = NULL;
			height = 1;
		}
	};
	Node* root;

public:
	Tree();
	~Tree();
	void insert(int d);
	void remove(int d);
	void printPre();
	void printIn();
	void printPost();
	//void balance();

private:
	void deleteTree(Node* temp);
	void printPreTree(Node* temp);
	void printInTree(Node* temp);
	void printPostTree(Node* temp);
	int height(Node* temp);
	int balFactor(Node* temp);
	void setHeight(Node* temp);

};

Tree::Tree()
{
	root = NULL;
}

void Tree::insert(int d)
{
	if (!root) root = new Node(d);
	else
	{
		Node* temp = root;
		while (temp)
		{
			if (d < temp->data)
			{
				if (temp->left)
					temp = temp->left;
				else
				{
					temp->left = new Node(d);
					return;
				}
			}
			else
			{
				if (temp->right)
					temp = temp->right;
				else
				{
					temp->right = new Node(d);
					return;
				}
			}
		}
	}
}

void Tree::remove(int d)
{
	Node* temp = root;
	Node* temp_p;

	while (temp)
	{
		if (d < temp->data)
		{
			temp_p = temp;
			temp = temp->left;
		}
		else if (d > temp->data)
		{
			temp_p = temp;
			temp = temp->right;
		}
		else
		{
			if (!temp->left && !temp->right)
			{
				if (temp_p->left == temp)
					temp_p->left = 0;
				else
					temp_p->right = 0;
				delete temp;
				return;
			}
			else if (temp->left && !temp->right)
			{
				if (temp_p->left == temp)
					temp_p->left = temp->left;
				else
					temp_p->right = temp->left;
				delete temp;
				return;
			}
			else if (!temp->left && temp->right)
			{
				if (temp_p->right == temp)
					temp_p->right = temp->right;
				else
					temp_p->left = temp->left;
				delete temp;
				return;
			}
			else
			{
				if (temp_p->right == temp)
				{
					temp->left->right = temp->right;
					temp_p->right = temp->left;
					delete temp;
				}
				else
				{
					temp->right->left = temp->left;
					temp_p->left = temp->right;
					delete temp;
				}
				return;
			}
		}

	}
}

Tree::~Tree()
{
	deleteTree(root);
}

void Tree::deleteTree(Node* temp)
{
	if (temp)
	{
		deleteTree(temp->left);
		deleteTree(temp->right);
		delete temp;
	}
}

void Tree::printPre()
{
	printPreTree(root);
	cout << endl;
}

void Tree::printPreTree(Node* temp)
{
	if (temp)
	{
		cout << temp->data << " ";
		printPreTree(temp->left);
		printPreTree(temp->right);
	}
}

void Tree::printIn()
{
	printInTree(root);
	cout << endl;
}

void Tree::printInTree(Node* temp)
{
	if (temp)
	{
		printInTree(temp->left);
		cout << temp->data << " ";
		printInTree(temp->right);
	}
}

void Tree::printPost()
{
	printPostTree(root);
	cout << endl;
}

void Tree::printPostTree(Node* temp)
{
	if (temp)
	{
		printPostTree(temp->left);
		printPostTree(temp->right);
		cout << temp->data << " ";
	}
}

int Tree::height(Node* temp)
{
	if (temp) return temp->height;
	else return -1;
}

int Tree::balFactor(Node* temp)
{
	return height(temp->left) - height(temp->right);
}

void Tree::setHeight(Node* temp)
{
	int hl = height(temp->left);
	int hr = height(temp->right);
	if (hl > hr)
		temp->height = hl + 1;
	else
		temp->height = hr + 1;
}

#endif
