#pragma once

#include <iostream>

using namespace std;

class Node {
	friend class DoubleLinkedList;

	int data;
	Node* next;
	Node* prev;
};

class DoubleLinkedList {
private:
	Node* head;
	Node* tail;
	int dummy;
public:
	DoubleLinkedList();
	~DoubleLinkedList();
	bool add_to_front(int);
	bool add_to_back(int);
	int count_nodes(); // extra
	bool insert_item(int, int);
	//bool search(int); //extra
	void remove_item(int);
	void remove_from_front();
	void remove_from_back();
	int& operator [] (int);
	friend ostream& operator << (ostream&, DoubleLinkedList&);

};