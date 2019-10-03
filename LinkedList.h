#pragma once

#include "Node.h"

namespace LocalLinkedLists
{
	class LinkedList
	{
		Node* head;
		int size;
		Node* getNode();

	public:
		LinkedList();
		Node* getHead();
		void printList();
		void insertAtBeginning();
		void insertMiddleBefore();
		void insertMiddleAfter();
		void insertAtEnd();
		void deleteBeginning();
		void deleteMiddleAfter();
		void deleteMiddleBefore();
		void deleteEnd();
		void findMiddle();
		void SortLists();
		void reverse(Node* current, Node* previous);
		void printReverse(Node* head);
	};
}


