#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;

template <typename typex>
ostream& operator<<(ostream& out, DoubleLinkedList<typex>& list)
{
	int n = list.count_nodes(), i;
	
	for (i = 0; i < n; ++i)
	{
		if (i != 0) out << ", ";
		out << list[i];
	}

	return out;
}

template <typename type>
DoubleLinkedList<type>::DoubleLinkedList()
{
	head = tail = NULL;
	dummy = 0;
}

template <typename type>
DoubleLinkedList<type>::~DoubleLinkedList()
{
	if (head == NULL)
		return;

	Node<type>* current;
	current = head;

	while (current != NULL)
	{
		Node<type>* temp = current;
		current = current->next;
		delete temp;
	}

	head = tail = NULL;
}

template <typename type>
bool DoubleLinkedList<type>::add_to_front(type x)
{
	//Allocating memory for one node using a pointer to a node
	Node<type>* new_node = new Node<type>;

	if (new_node == NULL)
		return false;

	new_node->data = x;
	new_node->next = head;
	new_node->previous = NULL;

	if (head == NULL)
		head = tail = new_node;
	else
	{
		head->previous = new_node;
		head = new_node;
	}

	return true;
}


template <typename type>
bool DoubleLinkedList<type>::add_to_back(type x)
{
	//Allocating memory for one node using a pointer to a node
	Node<type>* new_node = new Node<type>;

	if (new_node == NULL)
		return false;
	
	new_node->data = x;
	new_node->next = NULL;
	new_node->previous = NULL;

	if (head == NULL)
		head = tail = new_node;
	else
	{
		tail->next = new_node;
		new_node->previous = tail;
		tail = new_node;
	}

	return true;
}

template <typename type>
bool DoubleLinkedList<type>::search(type x)
{
	Node<type>* current;

	for (current = head; current != NULL; current = current->next)
		if (current->data == x) return true;

	return false;
}


template <typename type>
bool DoubleLinkedList<type>::insert_item(int pos, type x)
{
	int i;
	Node<type>* current;
	Node<type>* new_node;
	if (pos == 0)
		return add_to_front(x);
	
	int n = count_nodes();
	if (pos == n)
		return add_to_back(x);

	if (pos > n)
	{
		cout << "Position is out of range!" << endl;
		return false;
	}
	//Allocating memory for one node to be added
	//to the linked list
	new_node = new Node<type>;

	if (new_node == NULL)
		return false;

	new_node->data = x;
	new_node->next = NULL;
	new_node->previous = NULL;

	current = head;
	for (i = 0; i < pos; ++i)
		current = current->next;

	new_node->next = current;
	new_node->previous = current->previous;
	new_node->previous->next = new_node;
	current->previous = new_node;

	return true;
}

template <typename type>
int DoubleLinkedList<type>::count_nodes()
{
	int c = 0;
	Node<type>* current;

	for (current = head; current != NULL; current = current->next)
		++c;

	return c;
}


template <typename type>
void DoubleLinkedList<type>::remove_from_front()
{
	if (head == NULL)
		return;

	Node<type>* temp = head;

	//If we do not check head is NULL
	//NULL pointer exception
	if (head == tail)
		head = tail = NULL;
	else	
		head = head->next;
	
	delete temp;
}

template <typename type>
void DoubleLinkedList<type>::remove_item(type x)
{
	if (head == NULL)
		return;

	if (head->data == x)
	{
		remove_from_front();
		return;
	}

	if (tail->data == x)
	{
		remove_from_back();
		return;
	}

	Node<type>* current;
	for (current = head; current != NULL; current = current->next)
	{
		if (current->data == x)
		{
			Node<type>* temp = current;
			current->previous->next = current->next;
			current->next->previous = current->previous;
			delete temp;
			break;
		}
	}
}

template <typename type>
void DoubleLinkedList<type> ::remove_from_back()
{
	if (head == NULL)
		return;

	if (head == tail)
	{
		remove_from_front();
		return;
	}

	Node<type>* temp = tail;
	tail->previous->next = NULL;
	tail = tail->previous;
	delete temp;
}

template <typename type>
type& DoubleLinkedList<type>::operator[](int index)
{
	int i, n = count_nodes();

	if (index < 0 || index >= n)
	{
		cout << "Index out of range!" << endl;
		return dummy;
	}


	Node<type>* current = head;
	for (i = 0; i < index; ++i)
		current = current->next;

	return current->data;
}

/*
template <typename type>
Node<type> DoubleLinkedList<type>::get_node(int x) {
	Node<type> cur = ;
	int res = cur->data;
}
*/