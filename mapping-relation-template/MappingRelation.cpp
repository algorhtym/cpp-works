#include <iostream>
#include "MappingRelation.h"
#include <algorithm>

//Kemal Kilic 300143720


using namespace std;

template <typename typex1, typename typex2>
ostream& operator << (ostream& out, MappingRelation<typex1, typex2>& r) {

	out << "{";
	typename vector<Pair<typex1, typex2>>::iterator it = r.elements.begin();


	while (it != r.elements.end()) {
		if (it != r.elements.begin()) {
			out << ", ";
		}
		out << "(" << (*it).first << ", " << (*it).second << ")";
		++it;
	}

	out << "}";

	return out;

}

template <typename type1, typename type2>
MappingRelation<type1, type2>::MappingRelation() {
	size = 0;
}

template <typename type1, typename type2>
MappingRelation<type1, type2>::MappingRelation(const MappingRelation<type1, type2>& r) {
	size = r.size;
	root1 = r.root1;
	root2 = r.root2;
	elements = r.elements;
}

template <typename type1, typename type2>
MappingRelation<type1, type2>::~MappingRelation() {
	root1.clear();
	root2.clear();
	elements.clear();
}



template <typename type1, typename type2>
int MappingRelation<type1, type2>::cardinality() {
	return size;
}


template <typename type1, typename type2>
bool MappingRelation<type1, type2>::add_to_set1(type1 x) {
	typename set<type1>::iterator it;
	pair<set<type1>::iterator, bool> ret;

	ret = root1.insert(x);
	if (ret.second == false) {
		return false;
	}
	else {
		return true;
	}
}

template <typename type1, typename type2>
bool MappingRelation<type1, type2>::add_to_set2(type2 x) {
	typename set<type2>::iterator it;
	pair<set<type2>::iterator, bool> ret;

	ret = root2.insert(x);
	if (ret.second == false) {
		return false;
	}
	else {
		return true;
	}
}



template <typename type1, typename type2>
bool MappingRelation<type1, type2>::add_element(type1 a, type2 b) {
	//set<type>::iterator it = root.find(p.first)

	Pair<type1, type2> p;
	p.first = a;
	p.second = b;

	add_to_set1(a);
	add_to_set2(b);

	if (root1.find(p.first) == root1.end() || root2.find(p.second) == root2.end()) {
		return false;
	}

	typename vector<Pair<type1, type2>>::iterator it;
	for (it = elements.begin(); it != elements.end(); ++it) {
		if ((*it).first == p.first && (*it).second == p.second)
			return true;
	}

	elements.push_back(p);
	size++;
	return true;
}

template <typename type1, typename type2>
bool MappingRelation<type1, type2>::remove_element(type1 a, type2 b) {
	Pair<type1, type2> p;
	p.first = a;
	p.second = b;

	if (root1.find(p.first) == root1.end() || root2.find(p.second) == root2.end()) {
		return false;
	}

	typename vector<Pair<type1, type2>>::iterator it = elements.begin();

	while (it != elements.end()) {
		if ((*it).first == p.first && (*it).second == p.second)
			break;
		++it;
	}

	if (it != elements.end()) {
		elements.erase(it);
		size--;
		return true;
	}

	return false;


}

template <typename type1, typename type2>
bool MappingRelation<type1, type2>::is_member(type1 a, type2 b) {
	Pair<type1, type2> p;
	p.first = a;
	p.second = b;

	if (root1.find(p.first) == root1.end() || root2.find(p.second) == root2.end()) {
		return false;
	}

	typename vector<Pair<type1, type2>>::iterator it = elements.begin();

	while (it != elements.end()) {
		if ((*it).first == p.first && (*it).second == p.second) {
			break;
		}
		++it;
	}

	if (it != elements.end()) {
		return true;
	}

	return false;
}

template <typename type1, typename type2>
bool MappingRelation<type1, type2>::subset(MappingRelation<type1, type2> r) {
	typename vector<Pair<type1, type2>>::iterator it = elements.begin();

	while (it != elements.end()) {
		if (!r.is_member((*it).first, (*it).second)) {
			return false;
		}

		++it;
	}

	return true;
}

template <typename type1, typename type2>
bool MappingRelation<type1, type2>::operator== (MappingRelation<type1, type2> r) {
	if (subset(r) && r.subset(*this)) {
		return true;
	}

	return false;
}

template <typename type1, typename type2>
vector<type2> MappingRelation<type1, type2>::operator[] (type1 x) {
	vector<type2> ret;
	if (root1.find(x) == root1.end()) {
		cout << "element not found in root set!\n";
		return ret;
	}

	typename vector<Pair<type1, type2>>::iterator it = elements.begin();

	while (it != elements.end()) {
		if ((*it).first == x) {
			//ret.push_back((*it).first);
			ret.push_back((*it).second);
		}

		if (it == elements.end())
			break;
		++it;
	}
	/*
	if (it == elements.end()) {
		cout << "Relation not found!\n";
		return ret;
	}
	*/


	//ret.push_back((*it).first);
	//ret.push_back((*it).second);

	return ret;


}

template <typename type1, typename type2>
MappingRelation<type1, type2> MappingRelation<type1, type2>::operator + (MappingRelation<type1, type2> r) {
	MappingRelation<type1, type2> result;

	result = (*this).combination(r);
	return result;
}

template <typename type1, typename type2>
MappingRelation<type1, type2> MappingRelation<type1, type2>::operator - (MappingRelation<type1, type2> r) {
	MappingRelation<type1, type2> result;
	return result; // not implemented
}


template <typename type1, typename type2>
bool MappingRelation<type1, type2>::is_function() {
	typename vector<Pair<type1, type2>>::iterator it1;
	typename vector<Pair<type1, type2>>::iterator it2;

	for (it1 = elements.begin(); it1 != elements.end(); ++it1) {

		for (it2 = elements.begin(); it2 != elements.end(); ++it2) {
			if ((*it1).first == (*it2).first && (*it1).second != (*it2).second) {
				return false;
			}
		}
	}

	return true;

}

template <typename type1, typename type2>
MappingRelation<type2, type1> MappingRelation<type1, type2>::inverse() {
	MappingRelation<type2, type1> result;

	//result.root = root;
	typename set<type1>::iterator s_it1;
	for (s_it1 = root1.begin(); s_it1 != root1.end(); ++s_it1) {
		result.add_to_set1(*s_it1);
	}

	typename set<type2>::iterator s_it2;
	for (s_it2 = root2.begin(); s_it2 != root2.end(); ++s_it2) {
		result.add_to_set2(*s_it2);
	}


	typename vector<Pair<type1, type2>>::iterator it;
	for (it = elements.begin(); it != elements.end(); ++it) {
		Pair<type2, type1> p;
		p.first = (*it).second;
		p.second = (*it).first;
		result.add_element(p.first, p.second);
	}

	return result;

}

template <typename type1, typename type2>
MappingRelation<type1, type2> MappingRelation<type1, type2>::intersection(MappingRelation<type1, type2> r) {
	MappingRelation<type1, type2> result;

	typename vector<Pair<type1, type2>>::iterator it;

	for (it = elements.begin(); it != elements.end(); ++it) {
		if (r.is_member((*it).first, (*it).second)) {
			result.add_element((*it).first, (*it).second);
		}
	}

	return result;

}

template <typename type1, typename type2>
MappingRelation<type1, type2> MappingRelation<type1, type2>::combination(MappingRelation<type1, type2> r) {
	MappingRelation<type1, type2> result;

	typename set<type1>::iterator s_it1;
	for (s_it1 = root1.begin(); s_it1 != root1.end(); ++s_it1) {
		result.add_to_set1(*s_it1);
	}

	typename set<type2>::iterator s_it2;
	for (s_it2 = root2.begin(); s_it2 != root2.end(); ++s_it2) {
		result.add_to_set2(*s_it2);
	}

	typename vector<Pair<type1, type2>>::iterator it1;
	typename vector<Pair<type1, type2>>::iterator it2;

	for (it1 = elements.begin(); it1 != elements.end(); ++it1) {

		for (it2 = r.elements.begin(); it2 != r.elements.end(); ++it2) {
			if ((*it1).second == (*it2).first) {
				Pair<type1, type2> p;
				p.first = (*it1).first;
				p.second = (*it2).second;
				result.add_element(p.first, p.second);
			}
		}
	}

	return result;
}


