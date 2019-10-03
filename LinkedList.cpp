	#include "LinkedList.h"
	#include <iostream>

	namespace LocalLinkedLists
	{
		Node* LinkedList::getNode()
		{
			return new Node();
		}

		Node* LinkedList::getHead()
		{
			return this->head;
		}

		LinkedList::LinkedList()
		{
			head = nullptr, size = 0;
		}

		void LinkedList::printList()
		{
			Node* temp = head;

			while (temp)
			{
				std::cout << temp->data << "->";
				temp = temp->next;
			}
			std::cout << "NULL" << std::endl;
			std::cout << std::endl << "Total elements are	:	:" << this->size << std::endl;
		}

		void LinkedList::insertAtBeginning()
		{
			Node* temp = getNode();

			std::cout << "Enter data to insert	:	";
			std::cin >> temp->data;

			if (!head) head = temp;
			else
			{
				temp->next = head;
				this->head = temp;
			}
			
			size++;
		}

		void LinkedList::insertMiddleBefore()
		{
			Node* temp = getNode();
			int ele;
		
			std::cout << "Enter data to insert	:	";
			std::cin >> temp->data;

			std::cout << "Enter element, before whom to insert	:	";
			std::cin >> ele;

			if (!head)
			{
				std::cout << "\n" << "List is empty. Can't insert" << std::endl;
				return;
			}
			else
			{
				Node* prev, * curr;
				prev = curr = head;
				while (curr->data != ele && curr->next != nullptr)
				{
					prev = curr;
					curr = curr->next;
				}
				//Reached last and element not found
				if (curr->data != ele)
				{
					std::cout << "Element before which to be inserted is not in the list." << std::endl;
					return;
				}
				else
				{
					if (curr == head)
					{
						temp->next = head;
						head = temp;
					}
					else
					{
						temp->next = curr;
						prev->next = temp;
					}				
				}
			}
			size++;
		}

		void LinkedList::insertMiddleAfter()
		{
			Node* temp = getNode();
			int ele;

			std::cout << "Enter data to insert	:	";
			std::cin >> temp->data;

			std::cout << "Enter element, after whom to insert	:	";
			std::cin >> ele;

			if (!head)
			{
				std::cout << "\n" << "List is empty. Can't insert" << std::endl;
				return;
			}
			else
			{
				Node* ptr = head;
				while (ptr->data != ele && ptr->next != nullptr)
				{
					ptr = ptr->next;
				}
				//Reached last and element not found
				if (ptr->data != ele)
				{
					std::cout << "Element after which to be inserted is not in the list." << std::endl;
					return;
				}
				else
				{
					temp->next = ptr->next;
					ptr->next = temp;
				}
			}
			size++;
		}

		void LinkedList::insertAtEnd()
		{
			Node* temp = getNode();

			std::cout << "Enter data to insert	:	";
			std::cin >> temp->data;

			//If empty. Insert it as first.
			if (!head)  head = temp;
			else
			{
				Node* p = head;
				while (p->next)
				{
					p = p->next;
				}
				p->next = temp;
			}
			size++;
		}

		//Recursive. Go till last and then pop from stack.
		void LinkedList::printReverse(Node* head)
		{
			Node* p = head;

			if (p)
			{
				printReverse(p->next);
				std::cout << p->data << "->";
			}		
		}

		void LinkedList::deleteBeginning()
		{
			if (!head) std::cout << "Can't delete" << std::endl;
			else
			{
				Node* tmp = head;
				head = head->next;
				delete tmp;
				tmp = nullptr;
				size--;
			}			
		}
		void LinkedList::deleteMiddleAfter()
		{
			int ele;
			Node* del;

			std::cout << "Enter element, after whom to delete	:	";
			std::cin >> ele;

			if (!head)
			{
				std::cout << "Can't delete" << std::endl;
				return;
			}
			else
			{
				Node* tmp = head;
				while (tmp->data != ele && tmp->next != nullptr)
				{
					tmp = tmp->next;
				}
				if (!tmp->next)
				{
					std::cout << "Can't delete. Your element is last/not in list" << std::endl;
					return;
				}

				if (tmp->next)
				{
					del = tmp->next;
					tmp->next = del->next;
					delete(del);
					del = nullptr;
				}					
			}
			size--;
		}

		void LinkedList::deleteMiddleBefore()
		{
			int ele;

			std::cout << "Enter element, before whom to delete	:	";
			std::cin >> ele;

			if (!head || !head->next)
			{
				std::cout << "Can't delete" << std::endl;
				return;
			}
			else
			{
				Node* curr, * prev = head;
				curr= head;

				//If first one
				if (curr->data == ele)
				{
					std::cout << "Can't delete. Your entered position is first" << std::endl;
					return;
				}

				if (curr->next->data == ele)
				{
					curr = curr->next;
					delete head;
					prev = head = curr;
					size--; return;
				}

				while (curr->next != nullptr && curr->next->data != ele)
				{
					prev = curr;
					curr = curr->next;
				}
				if (curr->next == nullptr)
				{

					std::cout << " Can't delete. Element is not found" << std::endl;
					return;
				}
				else
				{
					prev->next = curr->next;
					delete curr;
					curr = nullptr;
				}
					
			}
	 
			size--;
	}

		void LinkedList::deleteEnd()
		{
			if (!head) std::cout << "Can't delete" << std::endl;
			else
				if (head->next == nullptr)
				{
					delete head;
					head = nullptr;
				}
				else
				{
					Node* tmp = head;
					while (tmp->next->next != NULL)
					{
						tmp = tmp->next;
					}

					delete(tmp->next);
					tmp->next = nullptr;
				}
			size--;
		}

		void LinkedList::findMiddle()
		{
			Node* p, * q;
			p = q = head;

			if (!p) std::cout << "Lists is empty . Can't find middle" << std::endl;

			while (p->next != NULL && q->next != NULL && q->next->next != NULL)
			{
				p = p->next;
				q = q->next->next;
			}

			std::cout << "Middle is	:	" << p->data << std::endl;
		}

		void LinkedList::SortLists()
		{
			//Sorting using selection sort.

			Node* p, * q;
		
			for (p = head; p != nullptr; p = p->next)
			{
				for (q = p->next; q != nullptr; q = q->next)
				{
					if (p->data > q->data)
					{
						int temp = p->data;
						p->data = q->data;
						q->data = temp;
					}
				}
			}

			std::cout << "Sorted List is : " << std::endl;

			Node* temp = head;
			while (temp)
			{
				std::cout << temp->data << "->";
				temp = temp->next;
			}
			std::cout << "NULL" <<std::endl;
		}

		//Recursive approach
		void LinkedList::reverse(Node *current, Node *previous)
		{
			if (current)
			{			
				reverse(current->next, current);
				current->next = previous;
			}
			else
			{
				head = previous;
			}
		}
	}