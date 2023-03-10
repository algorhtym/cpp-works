#pragma once

//Kemal Kilic 300143720

#include <iostream>
#include <set>
#include <vector>


using namespace std;

template <typename type>
struct Pair {
	type first;
	type second;
};

template <typename type>
class Relation {
private:
	int size;
	set<type> root;
	vector<Pair<type>> elements;
	//int capacity;
public:
	Relation();
	Relation(const Relation<type>&);
	~Relation();
	int cardinality();
	bool add_to_set(type);
	bool add_element(type, type);
	bool remove_element(type, type);
	bool is_member(type, type);
	bool subset(Relation<type>);
	bool operator == (Relation<type>);
	vector<type> operator [] (type);
	bool reflexive();
	bool irreflexive();
	bool symmetric();
	bool asymmetric();
	bool transitive();
	bool is_function();
	Relation<type> inverse();
	Relation<type> combination(Relation<type>);
	template <typename typex> friend ostream& operator << (ostream&, Relation<typex>&);


};