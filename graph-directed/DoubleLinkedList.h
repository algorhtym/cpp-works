#pragma once

#include <iostream>


using namespace std;

template <typename type>
class Node
{	
	template <typename type>
	friend class DoubleLinkedList;

	type data;
	Node* next;
	Node* previous;
	//void* operator new[](size_t);
};

template <typename type>
class DoubleLinkedList
{
private:
	Node<type>* head;
	Node<type>* tail;
	int dummy;
public:
	DoubleLinkedList();
	~DoubleLinkedList();
	bool add_to_front(type);
	bool add_to_back(type);
	int  count_nodes();
	bool insert_item(int, type);
	bool search(type);
	void remove_item(type);
	void remove_from_front();
	void remove_from_back();
	type& operator[](int);
	template <typename typex> friend ostream& operator<<(ostream&, DoubleLinkedList<typex>&);
	//Node<type> get_node(int);
};