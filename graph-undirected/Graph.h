// Kemal Kilic 300143720
// Yasemin Eroltu 300111834

#pragma once
#include <iostream>
#include <vector>
#include "DoubleLinkedList.h"


using namespace std;

#define MAX_ELEM 100
#define DEF_ELEM 10

class Graph
{
private:
	//DoubleLinkedList<DoubleLinkedList <int>>* vertices; 
    vector<DoubleLinkedList*> vertices;
	int size;
	int capacity;
public:
	Graph();
	Graph(int);
	Graph(const Graph&);
	~Graph();
    bool add_edge_dir(int, int);
	void add_edge(int, int);
    bool remove_edge_dir(int, int);
	void remove_edge(int, int);
	bool edge_exist(int, int);
	int get_degree(int); //out degree
	Graph operator++();
	Graph operator--();
	Graph operator++(int);
	Graph operator--(int);
	bool path_exist(int, int);
	int connectivity_type();
	void BFS(int); 
	void DFS(int); 
	void dfs_recur(int, vector<bool>*);
	friend ostream& operator<<(ostream&, Graph&);
    int operator()(int, int);
};