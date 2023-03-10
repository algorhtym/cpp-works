#pragma once
#include <iostream>
#include "DoubleLinkedList.h"


using namespace std;

#define MAX_ELEM 100
#define DEF_ELEM 10

class Graph
{
private:
	DoubleLinkedList<DoubleLinkedList <int>>* vertices; 
	int size;
	int capacity;
public:
	Graph();
	Graph(int);
	Graph(const Graph&);
	~Graph();
	bool add_edge(int, int);
	void remove_edge(int, int);
	bool edge_exist(int, int);
	int get_degree(int); //out degree
	Graph operator++();
	Graph operator--();
	Graph operator++(int);
	Graph operator--(int);
	bool path_exist(int, int);
	int connectivity_type();
	void BFS(int); // you can just print the result
	void DFS(int); //you can just print the result
	//int* BFS(int, int&); you can return a list of integers with the number of visited elements as a reference input
	//int* DFS(int, int&); you can return a list of integers with the number of visited elements as a reference input
	friend ostream& operator<<(ostream&, Graph&);
};