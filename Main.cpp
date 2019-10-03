#include<iostream>
#include "LinkedList.h"

using namespace LocalLinkedLists;

int main()
{
	bool flag = true;

	LinkedList list1;

	while (flag)
	{
		std::cout << "Enter the options \n" <<
			"1.	PrintList \n" <<
			"2.	Insert a Node in Beginning \n" <<
			"3.	Insert a Node at the end of the list \n" <<
			"4.	Insert a Node at Middle of lists after a node  \n" <<
			"5.	Insert a node at middle of lists before a node \n" <<
			"6.	Print the lists in reverse order  \n" <<
			"7.	Delete a Node from Beginning \n" <<
			"8.	Delete a Node from the end of the list \n" <<
			"9.	Delete a Node from Middle of lists after a node  \n" <<
			"10.	Delete a node from middle of lists before a node \n" <<
			"11.	Find the middle of the lists \n" <<
			"12.	Sort the lists \n" <<
			"13.	Reverse the Lists \n" << 
			"14.	EXIT " << std::endl;

		std::cout << "Please enter your choice	:	";
		int input;
		std::cin >> input;

		switch (input)
		{
		case 1: list1.printList(); break;
		case 2: list1.insertAtBeginning(); break;
		case 3: list1.insertAtEnd(); break;
		case 4: list1.insertMiddleAfter(); break;
		case 5: list1.insertMiddleBefore(); break;
		case 6: list1.printReverse(list1.getHead()); std::cout << std::endl; break;
		case 7: list1.deleteBeginning(); break;
		case 8: list1.deleteEnd(); break;
		case 9: list1.deleteMiddleAfter(); break;
		case 10: list1.deleteMiddleBefore(); break;
		case 11: list1.findMiddle(); break;
		case 12: list1.SortLists(); break;
		case 13: list1.reverse(list1.getHead(), nullptr); break;
		case 14: flag = false;  break;
		}
	}
}