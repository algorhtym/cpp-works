#include <iostream>
#include "DoubleLinkedList.h"
#include "Graph.h"

using namespace std;

Graph::Graph() {

	int i;
	
	size = 0;
	capacity = DEF_ELEM;

	vertices = new DoubleLinkedList<DoubleLinkedList<int>>;

	if (vertices == NULL)
		cout << "Not enough memory for this graph!\n";
	else {
		for (i = 0; i < capacity; i++) {
			DoubleLinkedList<int> edge;
			edge.add_to_back(i+1);
			vertices->add_to_back(edge);
			cout << "added vertice: " << i + 1 << endl;
		}
		
	}
 
}

Graph::Graph(int s) {

	size = 0;
	capacity = s;
	int i;

	vertices = new DoubleLinkedList<DoubleLinkedList<int>>;
	if (vertices == NULL)
		cout << "Not enough memory for this graph!\n";
	else {
		for (i = 0; i < capacity; i++) {
			DoubleLinkedList<int> temp;
			temp.add_to_back(i + 1);
			vertices->add_to_back(temp);
			/*
			DoubleLinkedList<int> temp;
			temp.add_to_back(i+1);
			vertices->add_to_back(temp);
			*/
		}
	}

}
/*		vertices:
*		n: 2a			3a				4a				5a		-
*		d: 1a{1b}		2a{2b}			3a{3b}				4a		5a
*		p: -			1a				2a				3a		4a
*			
*			1b:				2b				3b
*		p:  d:    n: 	p:  d:    n:	p:  d:    n:	
*   	-   1c{1} -		-   2c{2} -		-   3c{3}
*		 			
* 
* 
*/

Graph::Graph(const Graph& g) {
	//int i;
	size = 0;
	capacity = 0;

	vertices = new DoubleLinkedList<DoubleLinkedList<int>>;

	if (vertices == NULL)
		cout << "Not enough memory for this graph!\n";
	else {
		size = g.size;
		capacity = g.capacity;
		vertices = g.vertices;
		
	}

}

Graph::~Graph() {
	delete[] vertices;
}

bool Graph::add_edge(int from, int to) {

	DoubleLinkedList<int> n = vertices[0][0];
	n.add_to_back(to);
	size++;
	return true;
}