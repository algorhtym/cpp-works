#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;




ostream& operator<<(ostream& out,  DoubleLinkedList& list)
{
	// TODO: insert return statement here
	int n = 0;
	n = list.count_nodes();

	int i;
	for (i = 0; i < n; i++) {
		if (i != 0)
			out << ", ";
		out << list[i];
	}

	return out;
}

DoubleLinkedList::DoubleLinkedList() {
	head = NULL;
	tail = NULL;
	dummy = 0;
}

DoubleLinkedList::~DoubleLinkedList() {
	if (head == NULL) {
		return;
	}

	Node* current = head;

	while (current != tail) {
		Node* temp = current;
		current = current->next;
		current->prev = NULL;
		delete temp;
	}

	head = NULL;
	tail = NULL;
}

bool DoubleLinkedList::add_to_front(int x) {
	Node* new_node = new Node;
	if (new_node == NULL) {
		return false;
	}
	if (x == NULL) {
		return false;
	}
	new_node->data = x;

	if (head != NULL) {
		new_node->next = head;
		head->prev = new_node;
	}
	
	head = new_node;
	if (tail == NULL) {
		tail = new_node;
	}

	return true;
}

bool DoubleLinkedList::add_to_back(int x) {
	Node* new_node = new Node;
	if (new_node == NULL) {
		return false;
	}

	if (x == NULL) {
		return false;
	}

	// changed count_nodes usage here
	if (head == NULL) {
		return add_to_front(x);
	}

	new_node->data = x;
	new_node->prev = tail;
	tail->next = new_node;
	tail = new_node;

	return true;
}

bool DoubleLinkedList::insert_item(int pos, int x) {
	int i;
	Node* current;
	Node* new_node;
	int c = count_nodes();

	if (pos < 0 || pos >= c) {
		return false;
	}

	if (x == NULL) {
		return false;
	}

	if (pos == 0) {
		return add_to_front(x);
	}

	if (pos == c - 1) {
		return add_to_back(x);
	}


	new_node = new Node;
	if (new_node == NULL) {
		return false;
	}

	new_node->data = x;
	new_node->next = NULL;
	new_node->prev = NULL;

	current = head;
	for (i = 0; i < pos - 1; ++i) {
		current = current->next;
	}

	new_node->next = current->next;
	new_node->prev = current;
	current->next->prev = new_node;
	current->next = new_node;

	return true;

}

int DoubleLinkedList::count_nodes() {
	int c = 0;
	if (head == NULL) {
		return c;
	}
	//DoubleLinkedList* a = this;
	Node* temp = head;
	c++;

	while (temp != tail) 
	{
		++c;
		if (temp->next == tail)
			break;
		temp = temp->next;
		
	}
	

	return c;
}

void DoubleLinkedList::remove_from_front() {
	if (head == NULL) {
		return;
	}
	Node* temp = head;

	if (tail != head) {
		head = head->next;
		head->prev = NULL;
	}
	else {
		tail = NULL;
		head = NULL;
	}
	

	delete temp;
}

void DoubleLinkedList::remove_from_back() {
	if (tail == NULL) {
		return;
	}

	Node* temp = tail;

	if (tail != head) {
		tail = tail->prev;
		tail->next = NULL;
	}
	else {
		head = NULL;
		tail = NULL;
	}

	delete temp;
	
}

void DoubleLinkedList::remove_item(int x) {
	if (head == NULL) {
		return;
	}

	if (x == NULL) {
		return;
	}

	if (head->data == x) {
		remove_from_front();
		return;
	}

	if (tail->data == x) {
		remove_from_back();
		return;
	}

	Node* current;
	current = head;
	current = current->next;
	while (current != tail) {
		if (current->data == x) {
			Node* temp = current;
			current->prev->next = current->next;
			current->next->prev = current->prev;
			delete temp;
			break;
		}
		current = current->next;
	}
}



int& DoubleLinkedList::operator [] (int index) {
	int c = count_nodes();
	int i;
	if (index < 0 || index >= c) {
		cout << "Index out of range!\n";
		return dummy;
	}

	Node* current;
	
	if (index < c / 2) {
		current = head;
		for (i = 0; i < index; i++) {
			current = current->next;
		}
	}
	else {
		current = tail;
		for (i = c - 1; i > index; i--) {
			current = current->prev;
		}
	}

	return current->data;
}

