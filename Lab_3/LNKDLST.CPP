#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef enum
{
  true = 1,
  false = 0
} bool;


class Node
{
	public:
		Node* prev;
		Node* next;
		int data;
		Node()
		{
			next = prev = NULL;
		}
};

class DoubleLinkedList
{
	private:
		Node* head;
		Node* tail;
		int size;
	public:
		DoubleLinkedList();
		Node* searchForNode(int _key);
		void insertNode(Node* _node);
		void appendNode(Node* _node);
		int deleteNode(int _key);
		void freeList();
		int getSize();
		int isEmpty();
		void printList();
};

DoubleLinkedList::DoubleLinkedList()
{
	head = tail = NULL;
	size = 0;
}


Node* DoubleLinkedList::searchForNode(int _key)
{
	Node* indirect = head;
	if (indirect == NULL) // empty list
		return NULL;


	while(indirect && (indirect->data != _key))
		indirect = indirect->next;

	return indirect;
}

void DoubleLinkedList::appendNode(Node* _node)
{
	if (head == NULL) // empty list
		head = tail = _node;
	else if (head != NULL) // general case
	{
		_node->prev = tail;
		tail->next = _node;
		tail = _node;
		tail->next = NULL;
	}

	size++;

	return;
}

// assuming list is sorted
void DoubleLinkedList::insertNode(Node* _node)
{
	Node* indirect = head;
	if (indirect == NULL) // empty list
		return;


	while(indirect && (indirect->data < _node->data))
		indirect = indirect->next;

	if (indirect == NULL) // empty list or larger than largest node
	{
		appendNode(_node);
	}
	else if (indirect == head) // smaller than smallest node
	{
		head->prev = _node;
		_node->next = head;
		head = _node;
		head->prev = NULL;
	}
	else // insert in-between list nodes
	{   /**
		standing on the node with bigger data (indirect)
		1. make the next of its previous = _node
		2. make _node's previous the bigger node's (indirect) previous
		3. make the bigger node's previous = _node
		4. make _node'next = the bigger node (indirect)
			*/
		indirect->prev->next = _node;
		_node->prev = indirect->prev;
		indirect->prev = _node;
		_node->next = indirect;
	}

	size++;

	return;
}

int DoubleLinkedList::deleteNode(int _key)
{
	if (head == NULL) // empty list
		return 0;

	Node* indirect = searchForNode(_key);
	if (indirect == NULL) // not found
		return 0;

	// only one node in list
	if ((head == indirect) && (tail == indirect))
	{
		head = tail = NULL;
		size = 0;
	}
	else if (indirect == head) // remove head
	{
		head = head->next;
		head->prev = NULL;
	}
	else if (indirect == tail) // remove tail
	{
		tail = tail->prev;
		tail->next = NULL;
	}
	else // general case
	{
		indirect->prev->next = indirect->next;
		indirect->next->prev = indirect->prev;
	}

	size--;
	free(indirect);
	return 1;
}


void DoubleLinkedList::freeList()
{
	Node* indirect = head;
	if (head == NULL)
		return;

	while (indirect)
	{
		head = head->next;
		free(indirect);
		indirect = head;
	}

	tail = NULL;
	size = 0;
}

int DoubleLinkedList::getSize()
{
	 return size;
}
int DoubleLinkedList::isEmpty()
{
	return (getSize() == 0);
}

void DoubleLinkedList::printList()
{
	Node* indirect = head;
	if (indirect == NULL)
	{
		cout << "\[ \]\n";
		return;
	}

	cout << "\[ ";
	while (indirect)
	{
		cout << indirect->data
			 << " ";
		indirect = indirect->next;
	}
	cout << "\]\n";

	return;
}

void main()
{
	clrscr();

	DoubleLinkedList list;


	// Testing appendNode
	Node* node1 = new Node();
	node1->data = 10;
	list.appendNode(node1);

	Node* node2 = new Node();
	node2->data = 20;
	list.appendNode(node2);

	Node* node3 = new Node();
	node3->data = 30;
	list.appendNode(node3);

	cout << "List After Appending Nodes: \n";
	list.printList();

	// Testing insertNode
	Node* node4 = new Node();
	node4->data = 15;
	list.insertNode(node4); // inserted between 10 & 20

	cout << "List After Inserting a New Node: \n";
	list.printList();


	// Testing deleteNode
	list.deleteNode(20);
	cout << "List After Deleting a Node with Key 20: \n";
	list.printList();


	// Testing freeList
	list.freeList();
	cout << "List After Deleting All Nodes: \n";
	list.printList();


	return;

}

