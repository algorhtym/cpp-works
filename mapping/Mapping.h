#pragma once

#include <iostream>
#include <map>
#include <set>

using namespace std;

template <typename type1, typename type2>
class Mapping
{
private:
	map<type1, set<type2>>* elems;
	int numkeys;

public:
	Mapping();
	Mapping(const Mapping<type1, type2>&);
	bool add_item(type1, type2);
	bool remove_item(type1, type2);
	bool clear_item(type1);
	set<type2> operator[](type1);
	template <typename typex1, typename typex2> friend ostream& operator << (ostream&, Mapping<typex1, typex2>&);
	Mapping<type1, type2>& operator = (Mapping<type1, type2>&);

};


