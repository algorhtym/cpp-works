#pragma once

//Kemal Kilic 300143720


#include <iostream>
#include <set>
#include <vector>


using namespace std;

template <typename type1, typename type2>
struct Pair {
	type1 first;
	type2 second;
};

template <typename type1, typename type2>
class MappingRelation {
private:
	int size;
	set<type1> root1;
	set<type2> root2;
	vector<Pair<type1, type2>> elements;
	//int capacity;
public:
	MappingRelation();
	MappingRelation(const MappingRelation<type1, type2>&);
	~MappingRelation();
	int cardinality();
	bool add_to_set1(type1);
	bool add_to_set2(type2);
	bool add_element(type1, type2);
	bool remove_element(type1, type2);
	bool is_member(type1, type2);
	bool subset(MappingRelation<type1, type2>);
	bool operator == (MappingRelation<type1, type2>);
	MappingRelation<type1, type2> operator + (MappingRelation<type1, type2>);
	MappingRelation<type1, type2> operator - (MappingRelation<type1, type2>);
	vector<type2> operator [] (type1);
	MappingRelation<type1, type2> intersection(MappingRelation<type1, type2>);
	bool is_function();
	MappingRelation<type2, type1> inverse();
	MappingRelation<type1, type2> combination(MappingRelation<type1, type2>);
	template <typename typex1, typename typex2> friend ostream& operator << (ostream&, MappingRelation<typex1, typex2>&);


};