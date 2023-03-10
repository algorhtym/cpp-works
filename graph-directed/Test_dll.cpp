#include <iostream>
#include "DoubleLinkedList.h"
#include "Graph.h"

using namespace std;

int main() {
	DoubleLinkedList<DoubleLinkedList<int>> * vertices;
	//elems = new DoubleLinkedList<DoubleLinkedList<int>>;

	

	vertices = new DoubleLinkedList<DoubleLinkedList<int>>;

	

	cout << "numnodes: " << vertices->count_nodes();

	return 0;
}