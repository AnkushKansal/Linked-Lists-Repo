#pragma once

class Node
{
public:
	int data;
	Node* next;
	Node(int data = 0, Node *next=nullptr) : data(data), next(next){}

	//Overloading ->, because I want to treat node object a pointer.
	const Node* operator->() const;
	//const Node* operator++() const;
};

